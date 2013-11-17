import random
import serial
import time


rs = serial.Serial('/dev/ttyUSB0', 9600)
rs.write("s".encode('utf-8'))
i=0
while True:
#    print( rs.readline().encode('utf-8') ) 
    data = int(rs.readline()) 
    i+=1
    print((str("%d %d" % (i,data))))

