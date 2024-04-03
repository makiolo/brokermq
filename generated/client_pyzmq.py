import zmq
import time
from event import Mutation, Response
from google.protobuf.json_format import MessageToJson


def go():
    BATCH = 100000
    addr = 'tcp://localhost:5002'

    context = zmq.Context(1)
    dealer = context.socket(zmq.DEALER)
    dealer.set(zmq.ROUTING_ID, "client_pyzmq".encode('utf-8'))
    dealer.connect(addr)
    dealer.set(zmq.LINGER, 1000)
    dealer.set(zmq.SNDBUF, 2000000)
    dealer.set(zmq.RCVBUF, 2000000)
    dealer.set(zmq.SNDHWM, 2000000)
    dealer.set(zmq.RCVHWM, 2000000)

    # dealer.hwm = 1
    try:
        dataset = []
        begin = time.time()
        proto_serialize = 0
        proto_unserialize = 0
        mutation = Mutation()
        for i in range(BATCH):
            begin2 = time.time()
            mutation.id = 1
            mutation.name = "job_name"
            mutation.origin = "myorigin"
            mutation.destination = "calculate2"
            mutation.year = 2024
            mutation.year2 = 2025
            mutation.age = i
            msg = mutation.SerializeToString()
            proto_serialize = proto_serialize + (time.time() - begin2)
            dealer.send(msg, flags=zmq.NOBLOCK)
        res = Response()
        for i in range(BATCH):
            response = dealer.recv()  # Receive a message
            begin3 = time.time()
            res.ParseFromString(response)
            res_json = MessageToJson(res)
            proto_unserialize = proto_unserialize + (time.time() - begin3)
            dataset.append(res_json)
        elapsed = time.time() - begin
        elapsed_proto = proto_serialize + proto_unserialize
        print(elapsed)
        print(f'elapsed: {elapsed} seconds')
        print(f'elapsed proto: {elapsed_proto} seconds')
    finally:
        dealer.close()


if __name__ == '__main__':
    go()
