#!/bin/bash

name="Bashmash"
version="0.2"

cppSources=("src/fact.cpp" "src/dec2bin.cpp" "src/bin2dec.cpp")
cppDestinations=("/bin/fact" "/bin/dec2bin" "/bin/bin2dec")

cppLibraries=("src/NonNegativeInteger.cpp" "src/NonNegativeInteger.cpp" "src/NonNegativeBinaryInteger.cpp")
cppFiles=${#cppSources[@]}

for (( i = 0; i < $cppFiles; i++ )); do
	source="${cppSources[$i]}"
	destination="${cppDestinations[$i]}"
	
	library="${cppLibraries[$i]}"
	
	echo -n "$source..."
	g++ "$source" "$library" "-Isrc" -o "$destination"
	
	if [ $? == 0 ]; then
		chmod +x "$destination"
		if [ $? == 0 ]; then
			echo "Done"
		fi
	fi
done
