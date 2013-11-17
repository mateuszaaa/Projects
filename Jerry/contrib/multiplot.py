import random
import serial
import time
import Gnuplot
import copy


rs = serial.Serial('/dev/ttyUSB0', 230400)
data_file = open("plot.dat",'w')
script_file = open("multiplot.gnuplot",'w')
script_output = ""


while(rs.readline() != "__start__\n"):
    pass
print "recived start symbol"

script_output+="set key autotitle columnhead\nplot "

titles = rs.readline()
for i,t in enumerate(titles.split(" ")[:-1]):
    script_output+=str(" 'plot.dat' using 1:%d with lines title '%s'," % (i+2,t) )
script_file.write(script_output[:-1]+"\nreread;")

titles = "time" + titles

print ("recived titles")
print titles


script_file.flush()

#j=0
time =  0
while True:
    data = rs.readline()
    print data
    data_file.write(str(time)+" "+data)
    data_file.flush()
    time+=1

