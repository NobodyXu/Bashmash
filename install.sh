#!/bin/bash

name="Bashmash"
version="0.2"

cppSources=("src/fact.cpp" "src/dec2bin.cpp")
cppDestinations=("/bin/fact" "/bin/dec2bin")

cppFiles=${#cppSources[@]}

for (( i = 0; i < $cppFiles; i++ )); do
	source="${cppSources[$i]}"
	destination="${cppDestinations[$i]}"
	
	echo -n "$source..."
	g++ "$source" "src/NonNegativeInteger.cpp" "-Isrc" -o "$destination"
	
	if [ $? == 0 ]; then
		chmod +x "$destination"
		if [ $? == 0 ]; then
			echo "Done"
		fi
	fi
done
