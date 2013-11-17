import random
import serial
import time

GO_FORWARD_500_TICKS = 0x01;
PREFEORM_MEASURE = 0x02;

current_distance = 20000

rs = serial.Serial('/dev/ttyUSB0', 9600)
data_file = open("ir_linearyzacja.dat",'w')

while (True):
    print "current distance :",current_distance 
    print "move robot 500 ticks forward"
    raw_input()
    rs.write(chr(0x01))
    current_distance -= 500

    print "get measures"
    raw_input()
    rs.write(chr(0x02))
    data = int( rs.readline() )
    print "distance measures"+ str(current_distance) +" value : " +str(data)
    data_file.write((str("%d %d \n" % (current_distance,data))))
    data_file.flush()


