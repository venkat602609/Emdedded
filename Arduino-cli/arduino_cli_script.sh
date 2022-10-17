#!/usr/bin/bash

if [[ $# -eq 0 ]] ; then 
	echo 'No Arguments Supplied please use --help or -h for help';
	exit 1;
fi

if [ $1 == '--help' ] || [ $1 == '-h' ] ; then
	echo 'Usage compile/flash followed by .ino folder path' 
	echo '-c or --compile  compile only'
	echo '-f or --flash    compile and flash';
	echo '-h or --help     show help';
	exit 1;
elif [ $1 == '--compile' ] || [ $1 == '-c' ] ; then
        echo 'Compiling '$2
	arduino-cli compile --fqbn arduino:avr:uno $2
        exit 1;
elif [ $1 == '--flash' ] || [ $1 == '-f' ] ; then
        echo 'Compiling and flashing '$2
        arduino-cli compile --fqbn arduino:avr:uno $2
	#fishin compiling

	cmd_output=$(arduino-cli board list)
	number_arduinos=$(arduino-cli board list | grep -o dev | wc -l)
	#echo $cmd_output
	echo $number_arduinos
	if  [ $number_arduinos -eq 0 ] ; then
        	echo 'No Arduino Boards Detected - Check physical connection';
	elif [ $number_arduinos -eq 1 ] ; then
        	echo 'One board detected at'
        	device=$(arduino-cli board list | sed -n '/^[/]/p' | awk '{print $1}');
		echo $device
		echo 'uploading program!!!';
		arduino-cli upload -p $device --fqbn arduino:avr:uno $2	
	elif [ $number_arduinos -gr 1] ; then
		echo 'More than 1 board detected'
	fi
        exit 1;
else
	echo 'Unsuppored command use --help for usage instructions'
fi 


