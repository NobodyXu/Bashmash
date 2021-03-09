#include "NonNegativeBinaryInteger.h"

#include <iostream>
#include <sstream>

void printUsage() {
	cout << "Usage: bin2hex <non_negative_binary_integer>" << endl;
}

string bin2hex(NonNegativeBinaryInteger* x) {
	ostringstream y;
	y << hex << x->toUnsignedLongLong();
	
	return y.str();
}

int main(int argc, char** argv) {
	if (argc != 2) {
		printUsage();
		return 1;
	}
	
	NonNegativeBinaryInteger* x = new NonNegativeBinaryInteger(argv[1]);
	if (!x->isValid()) {
		printUsage();
		return 1;
	}
	
	string y = bin2hex(x);
	cout << y;
	
	return 0;
}
