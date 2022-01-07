import subprocess
import time

commandTab = ["wmic", "cpu", "get", "loadpercentage", "/value"]

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
  time.sleep(5)