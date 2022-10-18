import asyncio
import aiohttp
import aioserial
import json
from datetime import datetime
import struct

print("Kessler Machine Controller Serial Driver")

apikey = "abcf"

headers = {
    "Content-Type": "application/json",
    #"Host": "motion-controller-driver",
    "apikey": apikey
}
body = {
    "text": "an"
}
url = "http://localhost:8000/driver_api/param/"
value_url = "http://localhost:8000/driver_api/config/value/"


async def read_and_print(aioserial_instance: aioserial.AioSerial):
    while True:
        try:
            async with aiohttp.ClientSession() as session:
                # print((await aioserial_instance.read_async()).decode(errors='ignore'), end='', flush=True)
                data: bytes = await aioserial_instance.read_until_async(b"\n")
                #print(data.decode('utf-8', errors='ignore'), end='', flush=True)
                #print(data_string, end='', flush=True)
                #data_string = data.decode('utf-8', errors='ignore')
                #print(data_string)
                if b'\n' in data:
                    data_string = data.decode('utf-8', errors='ignore')
                    if ";" in data_string:
                        for d in data_string.split(";"):
                            #print(d.split("="))
                            ddd = d.split("=")
                            param_id = ddd[0]
                            value = ddd[1]
                            print("From machine: {} - {}".format(param_id, value))
                            body = {
                                "param_id": param_id,
                                "value": value,
                                "timestamp": datetime.now().isoformat(),
                            }
                            async with session.put("{}{}/".format(url, param_id), headers=headers, json=body) as resp:
                                #print(resp.status)
                                pass
                                #print(await resp.text())                    
                    else:
                        print(data_string)
        except Exception as e:
            print(e)
            return
        #    break        

"""async def post_async(url, session, headers, body):
<    async with session.post(url, headers=headers, json=body) as response:
        text = await response.text()
        return json.loads(text)
"""
def _to_compact_format(json_data):
    compact_formatted = ""
    is_first = True
    for d in json_data:
        if not is_first:
            compact_formatted += ";"    
        compact_formatted += "{}={}".format(d["param_id"], d["value"] + 1)
        is_first = False
    return compact_formatted

def _to_compact_param_format(d):
    return "P{}={}".format(d["param_id"], d["value"] + 1)

async def pull_and_push(aioserial_instance):
    while True:
        try:
            async with aiohttp.ClientSession() as session:
                async with session.get(value_url, headers=headers, json=body) as response:
                    text = await response.text()
                    json_data = json.loads(text)
                    lines = []
                    for d in json_data:
                        marker = 1
                        byte_array = marker.to_bytes(1, 'big')
                        byte_array += d["param_id"].to_bytes(2, 'big')
                        byte_array += d["value"].to_bytes(2, 'big')
                        byte_array += bytes("\n", 'utf-8')
                        print(byte_array)
                        lines.append(struct.pack("B", 2))

                        lines.append(byte_array)
                        #print(byte_array)
                        #print("To machine: {}".format(_to_compact_param_format(d)))
                        #lines.append(_as_bytes(_to_compact_param_format(d)))
                        #await aioserial_instance.write_async(_as_bytes(_to_compact_param_format(d)))
                    await aioserial_instance.writelines_async(lines)
            await asyncio.sleep(5) 
        except Exception as e:
            print("==============")
            print(e)
            return


async def write_and_print(aioserial_instance: aioserial.AioSerial):
    await asyncio.sleep(5)
    while True:
    #await asyncio.sleep(2)
    #print("send param")
    #await aioserial_instance.write_async(_as_bytes('P511=42'))
    #await aioserial_instance.write_async(_as_bytes("P511=99"))
    #await asyncio.sleep(2)
        marker = 2
        cmd_id = 41
    #encode('ascii')
    #b_cmd_id = struct.pack("h", cmd_id)
    #s_cmd_id = len(b_cmd_id)
    #byte_array = struct.pack("BBhc", marker, cmd_id, "\n".encode('ascii'))
        byte_array = marker.to_bytes(1, 'big')
        byte_array += cmd_id.to_bytes(2, 'big')
        byte_array += bytes("\n", 'utf-8')
        print("To machine: cmd {}".format(cmd_id))
        await aioserial_instance.writelines_async([byte_array])
        await asyncio.sleep(3)

        cmd_id = 34
        byte_array = marker.to_bytes(1, 'big')
        byte_array += cmd_id.to_bytes(2, 'big', signed=False)
        byte_array += bytes("\n", 'utf-8')
        print("To machine: cmd {}".format(cmd_id))
        await aioserial_instance.writelines_async([byte_array])
        await asyncio.sleep(3)

        cmd_id = 33
        byte_array = marker.to_bytes(1, 'big')
        byte_array += cmd_id.to_bytes(2, 'big', signed=False)
        byte_array += bytes("\n", 'utf-8')
        print("To machine: cmd {}".format(cmd_id))
        await aioserial_instance.writelines_async([byte_array])
        await asyncio.sleep(3)

        cmd_id = 42
        byte_array = marker.to_bytes(1, 'big')
        byte_array += cmd_id.to_bytes(2, 'big', signed=False)
        byte_array += bytes("\n", 'utf-8')
        print("To machine: cmd {}".format(cmd_id))
        await aioserial_instance.writelines_async([byte_array])
        await asyncio.sleep(3)

    """cmd_id = 15
    byte_array = marker.to_bytes(1, 'big')
    byte_array += cmd_id.to_bytes(2, 'big', signed=False)
    byte_array += bytes("\n", 'utf-8')
    print(byte_array)
    await aioserial_instance.writelines_async([byte_array])
    await asyncio.sleep(3)
    #await asyncio.sleep(2)
    #await aioserial_instance.write_async(_as_bytes("P511=39"))
    #await asyncio.sleep(2)
    cmd_id = 34
    byte_array = marker.to_bytes(1, 'big')
    byte_array += cmd_id.to_bytes(2, 'big')
    byte_array += bytes("\n", 'utf-8')
    print(byte_array)
    await aioserial_instance.writelines_async([byte_array])
    #await aioserial_instance.write_async(_as_bytes("C400"))
    """
    await asyncio.sleep(2)

def _as_bytes(string_value):
    string_value += "\n"
    return bytes(string_value, 'utf-8')


async def main():
    aioserial_instance = aioserial.AioSerial(port='COM6')
    a, b = await asyncio.gather(
        read_and_print(aioserial_instance),
        #write_and_print(aioserial_instance),
        #pull_and_push(aioserial_instance)
    )
    print(a, b)

# asyncio.run(read_and_print(aioserial.AioSerial(port='COM7')))
#while True:
try:
    asyncio.run(main())
except:
    pass
#asyncio.run(asyncio.gather( read_and_print(serial_instance), write_and_print(serial_instance)  ))