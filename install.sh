#!/bin/bash

name="Bashmash"
version="0.2"

scriptSources=("src/dec2bin.sh")
scriptDestinations=("/bin/dec2bin")

cppSources=("src/fact.cpp")
cppDestinations=("/bin/fact")

scripts=${#scriptSources[@]}
cppFiles=${#cppSources[@]}

echo "Installing $name $version..."
for (( i = 0; i < $scripts; i++ )); do
	source="${scriptSources[$i]}"
	destination="${scriptDestinations[$i]}"
	
	echo -n "$source..."
	cp "$source" "$destination"
	
	if [ $? == 0 ]; then
		chmod +x "$destination"
		if [ $? == 0 ]; then
			echo "Done"
		fi
	fi
done

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
