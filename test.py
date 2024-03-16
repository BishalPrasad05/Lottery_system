import asyncio
import time


def hello():
    print('Hello, world!')
    time.sleep(5)
    print('Hello, again!')


print('Start')
hello()
print('End')
