import subprocess

def extract(s):
    s1 = s[s.find('=')+1:]
    # print(s1)
    # print(s1.find("\\"))
    s2 = s1[0:s1.find("\\")]
    print(s2)
    return s2


command = "wmic cpu get loadpercentage /value"
commandTab = ["wmic", "cpu", "get", "loadpercentage", "/value"]

#  subprocess.run(["wmic", "cpu", "get", "loadpercentage"], shell=True)
# subprocess.run(commandTab, shell=True)

myOut = subprocess.check_output(commandTab, shell=True)
percent = extract(str(myOut))
print(percent)