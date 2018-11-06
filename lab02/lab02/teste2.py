#!/usr/bin/python3


import RPi.GPIO as GPIO
import sys
import time
GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)
GPIO.setup(36, GPIO.OUT)
GPIO.setup(38, GPIO.OUT)
GPIO.setup(40, GPIO.OUT)
cont=0
while(cont<5):	
	GPIO.output(38,1)
	time.sleep(2)
	GPIO.output(38,0)
	GPIO.output(40,1)
	time.sleep(1)
	GPIO.output(40,0)
	GPIO.output(36,1)
	time.sleep(1)
	GPIO.output(36,0)
	time.sleep(1)
	cont=cont+1







