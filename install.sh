#!/bin/bash

if [ $EUID != 0 ]; then
	echo "You must run this installer as root."
	echo "Use this command: sudo ./install.sh"
	
	exit
fi

name="Bashmash"
version="0.4"

if ! command -v g++ &> /dev/null; then
	echo "You must install G++ to install $name $version."
	echo "Use this command: sudo apt install g++"
	
	exit
fi

echo "Installing $name $version..."
cd bash-loadables/bash

./configure
make

cd ..
make all -j $(nproc)

cd ..
g++ "src/Bashmash.cpp" "src/math/fact.cpp" "src/logic/not.cpp" "src/logic/or.cpp" "src/logic/and.cpp" "src/logic/xor.cpp" "src/comparators/cless.cpp" "src/comparators/cleq.cpp" "src/comparators/ceq.cpp" "src/comparators/cgreat.cpp" "src/comparators/cgreq.cpp" "src/converters/bin2oct.cpp" "src/converters/bin2dec.cpp" "src/converters/bin2hex.cpp" "src/converters/oct2bin.cpp" "src/converters/oct2dec.cpp" "src/converters/oct2hex.cpp" "src/converters/dec2bin.cpp" "src/converters/dec2oct.cpp" "src/converters/dec2hex.cpp" "src/converters/hex2bin.cpp" "src/converters/hex2oct.cpp" "src/converters/hex2dec.cpp" "src/integers/NonNegativeBinaryInteger.cpp" "src/integers/NonNegativeOctalInteger.cpp" "src/integers/NonNegativeInteger.cpp" "src/integers/NonNegativeHexadecimalInteger.cpp" -I"bash-loadables" -I"bash-loadables/bash/include" -o "/bin/bashmash" -shared -fPIC

if [ $? != 0 ]; then
	echo "Errors have occurred while installing $name $version."
	echo "Please fix the above errors and try again."
	
	exit
fi

echo "$name $version has been successfully installed."
