import asyncio
import aiohttp
import aioserial
from datetime import datetime

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


async def read_and_print(aioserial_instance: aioserial.AioSerial):
    while True:
        # print((await aioserial_instance.read_async()).decode(errors='ignore'), end='', flush=True)
        data: bytes = await aioserial_instance.read_until_async(b"\n")
        #print(data.decode('utf-8', errors='ignore'), end='', flush=True)
        #print(data_string, end='', flush=True)
        #data_string = data.decode('utf-8', errors='ignore')
        #print(data_string)
        if b'\n' in data:
            data_string = data.decode('utf-8', errors='ignore')
            if ";" in data_string:
                async with aiohttp.ClientSession() as session:
                    for d in data_string.split(";"):
                        #print(d.split("="))
                        ddd = d.split("=")
                        param_id = ddd[0]
                        value = ddd[1]
                        print("{} - {}".format(param_id, value))
                        body = {
                            "param_id": param_id,
                            "value": value,
                            "timestamp": datetime.now().isoformat(),
                        }
                        async with session.put("{}{}/".format(url, param_id), headers=headers, json=body) as resp:
                            print(resp.status)
                            print(await resp.text())                    

        #    break        

async def post_async(url, session, headers, body):
    async with session.post(url, headers=headers, json=body) as response:
        text = await response.text()
        return json.loads(text)

async def write_and_print(aioserial_instance: aioserial.AioSerial):
    await asyncio.sleep(8)
    while True:
        await asyncio.sleep(2)
        #print("send param")
        #await aioserial_instance.write_async(b'P511=42\n')
        await aioserial_instance.write_async(_as_bytes("P511=99"))
        await asyncio.sleep(2)
        await aioserial_instance.write_async(_as_bytes("C401"))
        await asyncio.sleep(2)
        await aioserial_instance.write_async(_as_bytes("P511=101"))
        await asyncio.sleep(2)
        await aioserial_instance.write_async(_as_bytes("C400"))
       # await asyncio.sleep(1)

def _as_bytes(string_value):
    string_value += "\n"
    return bytes(string_value, 'utf-8')


async def main():
    aioserial_instance = aioserial.AioSerial(port='COM7')
    a, b = await asyncio.gather(
        read_and_print(aioserial_instance),
        write_and_print(aioserial_instance)
    )
    print(a, b)

# asyncio.run(read_and_print(aioserial.AioSerial(port='COM7')))
asyncio.run(main())
#asyncio.run(asyncio.gather( read_and_print(serial_instance), write_and_print(serial_instance)  ))