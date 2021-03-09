#include "NonNegativeHexadecimalInteger.h"
#include <iostream>

void printUsage() {
	cout << "Usage: hex2dec <non_negative_hexadecimal_integer>" << endl;
}

string hex2dec(NonNegativeHexadecimalInteger* x) {
	string y = to_string(x->toUnsignedLongLong());
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
	
	string y = hex2dec(x);
	cout << y;
	
	return 0;
}
