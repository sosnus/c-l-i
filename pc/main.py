import subprocess
import time
import serial

commandTab = ["wmic", "cpu", "get", "loadpercentage", "/value"]
serialName = "COM6" # '/dev/ttyUSB0'
ser = serial.Serial(serialName)

def extract(s):
    # print(s)
    s1 = s[s.find('=')+1:]
    s2 = s1[0:s1.find("\\")]
    return s2


# time.sleep(5)


# myOut = subprocess.check_output(commandTab, shell=True)
# percent = extract(str(myOut))
# print(percent)


while True:
  localtime = time.localtime()
  result = time.strftime("%H:%M:%S", localtime)
  print(result, end = "  ", flush=True)
  myOut = subprocess.check_output(commandTab, shell=True)
  print(extract(str(myOut)+"%"), flush=True)
  ser.write(extract(str(myOut)).encode())
  time.sleep(5)

ser.close()

# >>> import serial
# >>> ser = serial.Serial('/dev/ttyUSB0')  # open serial port
# >>> print(ser.name)         # check which port was really used
# >>> ser.write(b'hello')     # write a string
# >>> ser.close()             # close port