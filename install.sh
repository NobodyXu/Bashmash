#!/bin/bash

name="Bashmash"
version="0.2"

cppSources=("src/fact.cpp" "src/bin2oct.cpp" "src/bin2dec.cpp" "src/bin2hex.cpp" "src/oct2bin.cpp" "src/oct2dec.cpp" "src/oct2hex.cpp" "src/dec2bin.cpp" "src/dec2oct.cpp" "src/dec2hex.cpp")
cppDestinations=("/bin/fact" "/bin/bin2oct" "/bin/bin2dec" "/bin/bin2hex" "/bin/oct2bin" "/bin/oct2dec" "/bin/oct2hex" "/bin/dec2bin" "/bin/dec2oct" "/bin/dec2hex")

cppLibraries=("src/NonNegativeInteger.cpp" "src/NonNegativeBinaryInteger.cpp" "src/NonNegativeBinaryInteger.cpp" "src/NonNegativeBinaryInteger.cpp" "src/NonNegativeOctalInteger.cpp" "src/NonNegativeOctalInteger.cpp" "src/NonNegativeOctalInteger.cpp" "src/NonNegativeInteger.cpp" "src/NonNegativeInteger.cpp" "src/NonNegativeInteger.cpp")
cppFiles=${#cppSources[@]}

echo "Installing $name $version..."
error="false"

for (( i = 0; i < $cppFiles; i++ )); do
	source="${cppSources[$i]}"
	destination="${cppDestinations[$i]}"
	
	library="${cppLibraries[$i]}"
	
	echo -n "$source..."
	g++ "$source" "$library" "-Isrc" -o "$destination"
	
	if [ $? != 0 ]; then
		error="true"
		continue
	fi
	
	if [ $? == 0 ]; then
		chmod +x "$destination"
		if [ $? == 0 ]; then
			echo "Done"
		fi
	fi
done

if [ "$error" == "true" ]; then
	echo "Errors have occurred while installing $name $version."
	echo "Make sure that you've installed G++ and that you're installing as root."
	
	exit
fi

echo "$name $version has been successfully installed."
