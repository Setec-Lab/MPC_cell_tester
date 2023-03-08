import serial
import datetime
import csv
import time
import struct
import numpy as np
import matplotlib.pyplot as plt
from drawnow import drawnow
from serial.serialutil import *
#import string

pub_flag = 0
date = datetime.datetime.now()
date_string = date.strftime("%d_%m_%y_%H_%M")
file_name = "data_" + date_string + ".csv"
print("Saving to: ",end='')
print(file_name)

##Principal
ser2 = serial.Serial('COM4', baudrate=57600, bytesize=8, parity='N', stopbits=1, timeout=1.5, xonxoff=0, rtscts=0)
ser2.close()
ser2.open()
buffer2 = b'\x00'
time.sleep(1)
# ser1.write(b'\x73') #turn it on
ser2.read_until(b'\x01\x02') #discard it




def data_fig():
      ax1 = plt.subplot(211)
      plt.plot(time_data,vbat_data)
      plt.setp(ax1.get_xticklabels(), fontsize=6)     
      # share x only
      ax2 = plt.subplot(212, sharex=ax1)
      plt.plot(time_data,ibat_data)
      # make these tick labels invisible
      plt.setp(ax2.get_xticklabels(), visible=False)


plt.ion()
fig = plt.figure()

time_data = []
vbus_data = []
vbat_data = []
ibat_data = []
dc_data = []


while True:
      ##Principal
      ser2.read_until(b'\x01\x02')
      buffer2 = ser2.read(2)
      minutes = int.from_bytes(buffer2, "big")
      buffer2 = ser2.read(2)
      seconds = int.from_bytes(buffer2, "big")
      buffer2 = ser2.read(2)
      vbus = float(int.from_bytes(buffer2, "big"))
      buffer2 = ser2.read(2)
      vbat = float(int.from_bytes(buffer2, "big")-40)
      buffer2 = ser2.read(2)
      ibat = float(int.from_bytes(buffer2, "big"))
      buffer2 = ser2.read(2)
      dc = float(int.from_bytes(buffer2, "big"))
      print("vbus = ",end=' ')
      print(vbus,end='\t')
      print("vbat = ",end=' ')
      print(vbat,end='\t')
      print("ibat = ",end=' ')
      print(ibat,end='\t')
      print("dc = ",end=' ')
      print(dc,end='\t')
      date = datetime.datetime.now()
      time_stamp = date.strftime("%d/%m/%y %H:%M:%S")




      
      #data.append([time_stamp, speed, status ,pub_speed])
      with open(file_name,'a+',newline='') as f:
            writer = csv.writer(f, dialect='excel')
            writer.writerow([time_stamp, vbus, vbat, ibat, dc])
## PLOTS bateria 2
      vbus_data.append(vbus)
      #vbus_data = vbus_data[-20:] 
      vbat_data.append(vbat)
      ibat_data.append(ibat)
      dc_data.append(dc)
      #iloa_data = iloa_data[-20:] 
      time_float = minutes + (seconds / 60)
      time_data.append(time_float)
      #time_data = time_data[-20:] 
      drawnow(data_fig)



ser.close()

