import serial
import numpy as np
import psutil 
import time


while True:
	cpuPercent = str(psutil.cpu_percent(interval=0)) + "\n"
	memPercent = str(psutil.virtual_memory()[2]) + "%\n"
	with serial.Serial('COM4', 9600) as ser:
		x = ser.readline(20).decode('utf-8')
		print(x)

		ser.write(memPercent.encode())
		ser.write(cpuPercent.encode())
		
		y = ser.readline(5).decode('utf-8')
		ser.reset_input_buffer()
		print(y)
		time.sleep(5)
