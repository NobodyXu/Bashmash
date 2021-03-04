#!/bin/bash

if [ $# != 1 ] || ! [[ $1 =~ ^[0-9]+$ ]]; then
	echo "Usage: fact <non_negative_integer>"
	exit
fi

if [ $1 == 0 ]; then
	echo -n "1"
	exit
fi

echo $(( $(seq -s "*" 1 $1) ))
