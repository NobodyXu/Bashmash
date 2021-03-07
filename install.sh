#!/bin/bash

name="Bashmash"
version="0.1"

scriptSources=("src/fact.sh" "src/dec2bin.sh")
scriptDestinations=("/bin/fact" "/bin/dec2bin")

scripts=${#scriptSources[@]}
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

