import threading 
from queue import Queue
import random 
import time
from datetime import datetime


qf=Queue(maxsize = 1)
qa=Queue(maxsize = 1)

def ctime():
    myobj = datetime.now()
    s=" "+str(myobj.hour)+":"+str(myobj.minute)+":"+str(myobj.second)
    return s
    
def req() :
    time.sleep(random.randint(0,3))
    return True

def GetData():
    d=input(f"\n{ctime()} [ SENDER ] enter data to send : ")
    time.sleep(random.randint(0,1))
    return d

def MakeFrame(data):
    f=f"Frame: {data}"
    time.sleep(random.randint(0,1))
    return f

def SendFrame(frame):
    print(f"\n{ctime()} [ SENDER ] {frame} send to reciever")
    time.sleep(random.randint(0,1))
    qf.put(frame)

def ReceiveAck():
    ack=qa.get()
    time.sleep(random.randint(0,1))
    print(f"\n{ctime()} [ SENDER ] recieved {ack} from receiver")
    

def ReceiveFrame():
    print(f"\n{ctime()} [ RECEIVER ] frame recieved at receiver ")
    return qf.get()

def ExtractData(frame):
    print(f"\n{ctime()} [ RECEIVER ] data extracted at receiver ")
    data=frame.split(' ')[1]
    return data

def DeliverData(data):
    print(f"\n{ctime()} [ RECEIVER ] {data} delivered to network layer at receiver ")

def SendAck():
    print(f"\n{ctime()} [ RECEIVER ] ACK send to sender")
    qa.put("ACK")


def sender():
    canSend=True
    while True:
        RequestToSend=req()
        if RequestToSend and canSend :
            data=GetData()
            frame=MakeFrame(data)
            SendFrame(frame)
            canSend=False
        if qa.full() :
            ReceiveAck()
            canSend=True



def receiver():
    while True:
        if qf.full() :
            frame=ReceiveFrame()
            time.sleep(random.randint(0,1))
            data=ExtractData(frame)
            time.sleep(random.randint(1,2))
            DeliverData(data)
            time.sleep(random.randint(0,1))
            SendAck()



start_time=time.time()
sender_thread=threading.Thread(target=sender,args=())
receiver_thread=threading.Thread(target=receiver,args=())
sender_thread.start()
receiver_thread.start()
