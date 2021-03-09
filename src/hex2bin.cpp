#include "NonNegativeHexadecimalInteger.h"

#include <iostream>
#include <bitset>

void printUsage() {
	cout << "Usage: hex2bin <non_negative_hexadecimal_integer>" << endl;
}

string hex2bin(NonNegativeHexadecimalInteger* x) {
	if (x->equalTo(0))
		return "0";
		
	bitset<64> bin(x->toUnsignedLongLong());
	string y = bin.to_string();
	
	y.erase(0, y.find_first_not_of('0'));
	return y;
}

int main(int argc, char** argv) {
	if (argc != 2) {
		printUsage();
		return 1;
	}
	
	NonNegativeHexadecimalInteger* x = new NonNegativeHexadecimalInteger(argv[1]);
	if (!x->isValid()) {
		printUsage();
		return 1;
	}
	
	string y = hex2bin(x);
	cout << y;
	
	return 0;
}
