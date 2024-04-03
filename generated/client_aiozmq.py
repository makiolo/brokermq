import asyncio
import aiozmq
import zmq
import time
from event import Mutation, Response
from google.protobuf.json_format import MessageToJson

async def go():
    BATCH = 1000000
    addr = 'tcp://localhost:5002'
    dealer = await aiozmq.create_zmq_stream(zmq.DEALER, connect=addr)
    dealer.set_read_buffer_limits(2000000, 2000000)
    try:
        dataset = []
        begin = time.time()
        for i in range(BATCH):
            mutation = Mutation()
            mutation.id = 1
            mutation.name = "job_name"
            mutation.origin = "myorigin"
            mutation.destination = "calculate2"
            mutation.year = 2024
            mutation.year2 = 2025
            mutation.age = i
            msg = [mutation.SerializeToString(), ]
            dealer.write(msg)
        for i in range(BATCH):
            response = await dealer.read()  # Receive a message
            chunk = None
            for chunk in response:
                if chunk != b'':
                    break
            else:
                raise Exception('Invalid Response: {}'.format(response))
            res = Response()
            res.ParseFromString(chunk)
            res_json = MessageToJson(res)
            dataset.append(res_json)
            assert(res.code == 202)
        elapsed = time.time() - begin
        print(elapsed)
        print(f'elapsed: {elapsed} seconds')
    finally:
        dealer.close()

asyncio.run(go())
