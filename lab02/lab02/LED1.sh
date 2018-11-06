#!/bin/bash
cd ~
contador=0
i=0
tempo=2 
while [ $contador -lt 5 ];
do 
	cont=0
	while [ $cont -lt 3 ];
	do
   		if [ $i == 0 ]; then
			LED_GPIO=20
			i=i+1
			tempo=2
		elif [ $i == 1 ]; then
			LED_GPIO=21
			i=i+1
			tempo=1
		elif [ $i == 2 ]; then
			LED_GPIO=16
			i=i-2
			tempo=1
		fi
  	
	cd /sys/class/gpio
	echo $LED_GPIO > export
	cd gpio$LED_GPIO	
	echo out > direction
	echo 1 > value
	sleep $tempo
	echo 0 > value
	cd ..
	echo $LED_GPIO > unexport 
	let contador=contador+1
        sleep 1
	let cont=cont+1
	done
done 
