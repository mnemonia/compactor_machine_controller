import asyncio
import serial_asyncio
from datetime import datetime
import requests
import json
import aiohttp

loop = asyncio.get_event_loop()


apikey = "abcf"
headers = {
    "Content-Type": "application/json",
    "apikey": apikey
}
body = {
    "text": "an"
}
url = "http://localhost:8000/driver_api/param/"
value_url = "http://localhost:8000/driver_api/config/value/"
command_url = "http://localhost:8000/driver_api/command/"


class ValueCache:

    def __init__(self) -> None:
        self.__cache = dict()

    def has_value_changed(self, value_dict):
        from_cache = self.__cache.get(value_dict["param_id"], None)
        if from_cache is None:
            self.__cache[value_dict["param_id"]] = value_dict
            return True
        
        if from_cache["value"] == value_dict["value"]:
            return False

        self.__cache[value_dict["param_id"]] = value_dict
        return True


class ProtocolHandler:
    def __init__(self) -> None:
        super().__init__()
        self._INVALUD = self.__create_invalid()

    def parse_values(self, values_string):
        values_string = values_string.replace("\r", ";")
        values_string = values_string.replace("\n", ";")
        #print("------------------------------------------")
        #print(values_string)
        #print("==========================================")
        return self.__parse_values(values_string)

    def __parse_values(self, values_string):
        values = list()
        if ";" in values_string:
            for value_string in values_string.split(";"):
                if value_string == "":
                    continue

                print(values_string)
                values.append(self.__parse_value(value_string))
        else:
            #values.append(self.__parse_value(values_string))
            print(values_string)

        return filter(lambda x: x["is_valid"] == True, values)

    def __create_invalid(self):
        return {
            "param_id": 0,
            "value": 0,
            "timestamp": 0,
            "is_valid": False,
        }

    def __parse_value(self, value_string):
        ddd = value_string.split("=")
        #print(ddd)
        if len(ddd) == 2:
            param_id = ddd[0]
            if len(param_id) > 3:
                return self._INVALUD
            if len(param_id) < 2:
                return self._INVALUD
            if int(param_id) < 10:
                return self._INVALUD

            value = ddd[1]
            if value == "":
                return self._INVALUD

            #print("From machine: {} - {}".format(param_id, value))
            return {
                "param_id": param_id,
                "value": value,
                "timestamp": datetime.now().isoformat(),
                "is_valid": True,
            }

        return self._INVALUD


class DataBeat:

    def get_commands(self):
        r = requests.get(command_url)
        return r.json()

    def get_nominal_values(self):
        r = requests.get("http://localhost:8000/driver_api/config/value/")
        params = r.json()
        values = list()
        for param in params:
            values.append({
                "param_id": param["param_id"],
                "value": param["value"],
            })

        # values.append({
        #     "param_id": 12,
        #     "value": 25,
        # })
        # values.append({
        #     "param_id": 13,
        #     "value": 26,
        # })
        # values.append({
        #     "param_id": 14,
        #     "value": 27,
        # })
        # values.append({
        #     "param_id": 21,
        #     "value": 15,
        # })
        # values.append({
        #     "param_id": 22,
        #     "value": 16,
        # })
        # values.append({
        #     "param_id": 23,
        #     "value": 17,
        # })
        # values.append({
        #     "param_id": 24,
        #     "value": 18,
        # })
        return values


class OutputProtocol(asyncio.Protocol):
    def __init__(self) -> None:
        super().__init__()
        self._protocol_handler = ProtocolHandler()
        self.__cache = ValueCache()
        self.__beat = DataBeat()
    
    @staticmethod
    def __to_byte_array(param_id, value):
        marker = 1
        byte_array = marker.to_bytes(1, 'big')
        byte_array += param_id.to_bytes(2, 'big')
        byte_array += value.to_bytes(2, 'big')
        byte_array += bytes("\n", 'utf-8')
        return byte_array

    @staticmethod
    def __to_byte_command(command_id):
        marker = 2
        byte_array = marker.to_bytes(1, 'big')
        byte_array += command_id.to_bytes(2, 'big')
        byte_array += bytes("\n", 'utf-8')
        return byte_array


    def send(self):
        for n in self.__beat.get_nominal_values():
            byte_array = OutputProtocol.__to_byte_array(n["param_id"], n["value"])
           # print(byte_array)
            self.transport.write(byte_array)

    def send_cmd(self):
        for cmd in self.__beat.get_commands():
            byte_array = OutputProtocol.__to_byte_command(cmd["command_id"])
            print("Cmd to machine: {}".format(cmd["command_id"]))
            self.transport.write(byte_array)
            cmd["must_run"] = False
            r = requests.put('{}{}/'.format(command_url, cmd["command_id"]), data=cmd)

    def connection_made(self, transport):
        self.transport = transport
        print('port opened', transport)
        #transport.serial.rts = False  # You can manipulate Serial object via transport
        self.send()

    def data_received(self, data):
        #print(data)
        #if b'\n' in data:
        data_string = data.decode('utf-8', errors='ignore')
        #print('data received', data_string)
        values = self._protocol_handler.parse_values(data_string)
        changed_values = list()
        for value in values:
            # print(value["param_id"])
            if self.__cache.has_value_changed(value):
                changed_values.append(value)
        #if len(changed_values) > 0:
        #    r = requests.put(url, data=json.dumps(changed_values), headers=headers)
        #    print(r.status_code)
        # async def runit(changes):
        #     async with aiohttp.ClientSession() as session:
        #         for change in changes:
        #             print(change["param_id"])
        #             async with session.put("{}{}/".format(url, change["param_id"]), headers=headers, json=change) as resp:
        #                 print(str(resp.status) + ": " + str(change["param_id"]) + "=" + str(change["value"]))
        #                 pass

        # loop.create_task(runit(changed_values))

        if len(changed_values) > 0:
            for value in changed_values:
                print(value)
                r = requests.put('{}{}/'.format(url, value["param_id"]), data=value)
               # print(str(r.status_code) + " " + str(value["param_id"]) + "=" + str(value["value"]))

            self.send()
        
        self.send_cmd()

    def connection_lost(self, exc):
        print('port closed')
        self.transport.loop.stop()


reader = serial_asyncio.create_serial_connection(loop, OutputProtocol, 'COM7', baudrate=115200)
transport, protocol = loop.run_until_complete(reader)
loop.run_forever()
loop.close()
