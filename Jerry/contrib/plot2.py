import random
import serial
import Gnuplot
import time
import os

rs = serial.Serial('/dev/ttyUSB0', 9600)

g = Gnuplot.Gnuplot()
data_file = open("plot.dat",'w')
i=0

while True:
    data = rs.readline()
    data=data.split(' ')
#    try:
    x = int(data[0])
    y = int(data[1])
    points.append([x,y]) 
    data_file.write((str("%d %d \n" % (x,y))))
    data_file.flush()
    g.plot(points)
    print((str("%d %d" % (x,y))))
#    except:
#    	pass

