import subprocess
import time
import serial
import re
#                 b   g    r
cmd_init  = "rgb(126, 000, 000)"
cmd_low  = "rgb(000, 126, 000)"
cmd_med  = "rgb(000, 080, 255)"
cmd_high = "rgb(000, 000, 126)"

commandTab = ["wmic", "cpu", "get", "loadpercentage", "/value"]
serialName = "COM3" # '/dev/ttyUSB0'
ser = serial.Serial(serialName)
ser.write(str(cmd_init).encode())

def extract(s):
    s1 = s[s.find('=')+1:]
    s2 = s1[0:s1.find("\\")]
    return s2

while True:
  localtime = time.localtime()
  result = time.strftime("%H:%M:%S", localtime)
  print(result, end = "  ", flush=True)
  myOut = subprocess.check_output(commandTab, shell=True)
  print(extract(str(myOut)+"%"), flush=True)
  cpuloadStr = str(myOut)

  digits = re.findall(r'\d+', cpuloadStr)
  print("cpuload")
  if len(digits) == 0:
    cpuload = 101
    print("encoding error, message: ")
    print(cpuloadStr)
  else:
    cpuload = int(digits[0])
  print(cpuload)

  if cpuload == 101:
    ser.write(extract(str(cmd_init)).encode())
  elif cpuload > 10:
    ser.write(extract(str(cmd_high)).encode())
  elif cpuload > 5:
    ser.write(extract(str(cmd_med)).encode())
  else:
    ser.write(extract(str(cmd_low)).encode())

  time.sleep(3)

ser.close()

# >>> import serial
# >>> ser = serial.Serial('/dev/ttyUSB0')  # open serial port
# >>> print(ser.name)         # check which port was really used
# >>> ser.write(b'hello')     # write a string
# >>> ser.close()             # close port
