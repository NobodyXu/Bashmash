#include "NonNegativeHexadecimalInteger.h"

#include <iostream>
#include <sstream>

void printUsage() {
	cout << "Usage: hex2oct <non_negative_hexadecimal_integer>" << endl;
}

string hex2oct(NonNegativeHexadecimalInteger* x) {
	ostringstream y;
	y << oct << x->toUnsignedLongLong();
	
	return y.str();
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
	
	string y = hex2oct(x);
	cout << y;
	
	return 0;
}
