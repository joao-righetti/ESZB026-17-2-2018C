#!/bin/bash
cd ~
contador=0
cd /sys/class/gpio
echo 16 > export
echo 20 > export
echo 21 > export
while [ $contador -lt 5 ]
do 
	cd gpio20	
	echo out > direction
	echo 1 > value
	sleep 2
	echo 0 > value
	cd ..
	cd gpio21	
	echo out > direction
	echo 1 > value
	sleep 1
	echo 0 > value
	cd ..
	cd gpio16	
	echo out > direction
	echo 1 > value
	sleep 1
	echo 0 > value
	cd ..
	let contador=contador+1
        sleep 1
	
done 
echo 16 > unexport
echo 20 > unexport
echo 21 > unexport
