#!/bin/bash
# Converts decimal numbers to binary (max value upto 4095)

if [ $# != 1 ] || ! [[ $1 =~ ^[0-9]+$ ]]; then
	echo "Usage: dec2bin <non_negative_integer>"
	exit
fi

D2B=({0..1}{0..1}{0..1}{0..1}{0..1}{0..1}{0..1}{0..1}{0..1}{0..1}{0..1}{0..1})

echo $((10#${D2B[$1]}))
