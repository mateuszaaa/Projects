import random
import serial
import time

rs = serial.Serial('/dev/ttyUSB0', 9600)
rs.write("s".encode('utf-8'))
data_file = open("usart.dat",'w')

while True:
    recived = rs.readline()
    recived = recived.decode("utf-8")

    print (speed)
    data_file.write(str("%d\n"%speed))
    data_file.flush()

#    except:
#        print 
#        pass
#    dataFile.write(str(i) + ' ' + str(reading0)+'\n') # write sample number and reading to the file
#    dataFile.flush() 
#dataFile.close()

