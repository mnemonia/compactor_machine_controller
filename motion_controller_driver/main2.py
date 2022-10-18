import asyncio
import serial_asyncio
from datetime import datetime
import requests


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
        values = list()
        #if "\n" in values_string:
        values_string = values_string.replace("\r", ";")
        values_string = values_string.replace("\n", ";")
        # print(values_string)
        values.extend(self.__parse_values(values_string))
        #else:
        #    values.append(self.__parse_value(values_string))
        return values

    def __parse_values(self, values_string):
        values = list()
        if ";" in values_string:
            for value_string in values_string.split(";"):
                if value_string == "":
                    continue

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


class Writer(asyncio.Protocol):
    def connection_made(self, transport):
        """Store the serial transport and schedule the task to send data.
        """
        self.transport = transport
        print('Writer connection created')
        asyncio.ensure_future(self.send())
        print('Writer.send() scheduled')

    def connection_lost(self, exc):
        print('Writer closed')

    async def send(self):
        """Send four newline-terminated messages, one byte at a time.
        """
        message = b'foo\nbar\nbaz\nqux\n'
        for b in message:
            await asyncio.sleep(5)
            self.transport.serial.write(bytes([b]))
            print(f'Writer sent: {bytes([b])}')
        self.transport.close()

class DataBeat:
    def get_nominal_values(self):
        values = list()
        values.append({
            "param_id": 11,
            "value": 24,
        })
        values.append({
            "param_id": 12,
            "value": 25,
        })
        values.append({
            "param_id": 13,
            "value": 26,
        })
        values.append({
            "param_id": 14,
            "value": 27,
        })
        values.append({
            "param_id": 21,
            "value": 15,
        })
        values.append({
            "param_id": 22,
            "value": 16,
        })
        values.append({
            "param_id": 23,
            "value": 17,
        })
        values.append({
            "param_id": 24,
            "value": 18,
        })
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


    def send(self):
        for n in self.__beat.get_nominal_values():
            byte_array = OutputProtocol.__to_byte_array(n["param_id"], n["value"])
            #print("To machine: {}={}".format(n["param_id"], n["value"]))
           # print(byte_array)
            self.transport.write(byte_array)

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
        for value in values:
            print(value["param_id"])
            if self.__cache.has_value_changed(value):
                #print(value)
                r = requests.put('{}{}/'.format(url, value["param_id"]), data=value)
                print(r)
                pass

        #self.transport.close()
        self.send()

    def connection_lost(self, exc):
        print('port closed')
        self.transport.loop.stop()


loop = asyncio.get_event_loop()
reader = serial_asyncio.create_serial_connection(loop, OutputProtocol, 'COM7', baudrate=115200)
transport, protocol = loop.run_until_complete(reader)
loop.run_forever()
loop.close()
