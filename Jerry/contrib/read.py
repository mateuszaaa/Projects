import random
import serial
import time


rs = serial.Serial('/dev/ttyUSB0', 9600)
while True:
    data = rs.readline() 
    print data,
#    except:
#        pass

