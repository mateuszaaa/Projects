import random
import serial
import time
def processMeasure(measure):
    if measure == '\n':
        speed = 0
    else:
        speed = int(measure)
    return speed


rs = serial.Serial('/dev/ttyUSB0', 9600)
rs.write("s".encode('utf-8'))
data_file = open("usart.dat",'w')

while True:
    recived = rs.readline()
    recived = recived.decode("utf-8")
    speed = processMeasure(recived)
    print (speed)
    data_file.write(str("%d\n"%speed))
    data_file.flush()

