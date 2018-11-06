import sys
from time import sleep
path16 = "/sys/class/gpio/gpio16/"
path20 = "/sys/class/gpio/gpio20/"
path21 = "/sys/class/gpio/gpio21/"
contador=0
while (contador<5)
	fo = open( path20 + "1","w")
	sleep 2
	fo = open( path20 + "0","w")
	fo = open( path21 + "1","w")
	sleep 1
	fo = open( path21 + "0","w")
	fo = open( path16 + "1","w")
	sleep 1
	fo = open( path16 + "0","w")
	contador=contador+1
        sleep 1
	
print("fim")
