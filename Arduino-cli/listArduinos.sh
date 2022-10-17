#!/bin/bash


cmd_output=$(arduino-cli board list)
number_arduinos=$(arduino-cli board list | grep -o dev | wc -l)
echo $cmd_output
echo $number_arduinos
if  [ $number_arduinos -eq 0 ] ; then
	echo 'No Arduino Boards Detected - Check physical connection'
elif [ $number_arduinos -eq 1 ] ; then
	echo 'One board detected at'
	device=$(arduino-cli board list | sed -n '/^[/]/p' | awk '{print $1}');
	echo $device
elif [ $number_arduinos -gt 1 ] ; then
	echo 'More than 1 board detected at'
	device=$(arduino-cli board list | sed -n '/^[/]/p' | awk '{print $1}');
	echo $device
fi

