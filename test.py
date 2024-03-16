import asyncio


async def hello():
    print('Hello, world!')
    await asyncio.sleep(5)
    print('Hello, again!')

print('Start')
asyncio.run(hello())
print('End')
