import serial.tools.list_ports
import webbrowser
import time
import pyautogui
import os

ports = serial.tools.list_ports.comports()

serialInst = serial.Serial()

portList = []

for onePort in ports:
    portList.append(str(onePort))
    print(str(onePort))
val = input("select Port: COM")

print(val)

for x in range(0,len(portList)):
    if portList[x].startswith("COM" + str(val)):
        portVar = "COM" + str(val)
        print(portList[x])
    
serialInst.baudrate = 9600
serialInst.port = portVar
serialInst.open()

while True:
    if serialInst.in_waiting:
        packet = serialInst.readline()
        variable = packet.decode('utf')
        if "first" in variable :
            webbrowser.open("youtube.com")
            
            time.sleep(1)
        elif "second" in variable :
            pyautogui.click(751,35)
            pyautogui.keyDown('ctrl')
            pyautogui.press('w')
            pyautogui.keyUp('ctrl')
