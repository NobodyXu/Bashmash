#!/bin/bash

name="Bashmash"
version="0.5"

if (! command -v g++ &> /dev/null) && (! command -v clang++ &>/dev/null); then
	echo "You must install g++ or clang++ to install $name $version."
	echo "Use this command: sudo apt install clang++ g++"
	
	exit
fi

echo "Installing $name $version..."

make -j $(nproc) && sudo make install
if [ $? != 0 ]; then
	echo "Errors have occurred while installing $name $version."
	echo "Please fix the above errors and try again."
	
	exit
fi

echo "$name $version has been successfully installed."
