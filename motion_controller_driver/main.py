import asyncio

import aioserial

print("Kessler Machine Controller Serial Driver")

async def read_and_print(aioserial_instance: aioserial.AioSerial):
    while True:
        # print((await aioserial_instance.read_async()).decode(errors='ignore'), end='', flush=True)
        data: bytes = await aioserial_instance.read_async()
        print(data.decode(errors='ignore'), end='', flush=True)
        #if b'\n' in data:
        #    aioserial_instance.close()
        #    break        


async def write_and_print(aioserial_instance: aioserial.AioSerial):
    await asyncio.sleep(8)
    while True:
        await asyncio.sleep(2)
        print("send param")
        #await aioserial_instance.write_async(b'P511=42\n')
        await aioserial_instance.write_async(_as_bytes("P511=42"))
        await asyncio.sleep(2)
        await aioserial_instance.write_async(_as_bytes("C401"))
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