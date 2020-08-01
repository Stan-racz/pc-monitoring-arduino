import psutil 
import time
while True:
    print('memory % used:', psutil.virtual_memory()[2])
    #print(psutil.sensors_temperatures())
    print(psutil.cpu_percent(interval=0))
    time.sleep(1)