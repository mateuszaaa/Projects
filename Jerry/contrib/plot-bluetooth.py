import random
import serial
import time


rs = serial.Serial('/dev/rfcomm0', 9600)
rs.write("s".encode('utf-8'))
data_file = open("plot.dat",'w')
i=0
while True:
#    print( rs.readline().encode('utf-8') ) 
    data = int(rs.readline()) 
    i+=1
    data_file.write((str("%d %d \n" % (i,data))))
    data_file.flush()
    print((str("%d %d" % (i,data))))

