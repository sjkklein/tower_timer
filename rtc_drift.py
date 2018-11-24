import serial
from datetime import datetime
from time import sleep

arduino = serial.Serial('/dev/ttyS7', 115200, timeout=.1)
last_time=datetime.now()
while True:
	data = arduino.readline()[:-2] #the last bit gets rid of the new-line chars
	if(data):
		now = datetime.now()
		delta= now - last_time
		last_time = now
		print str(delta.total_seconds())
	
