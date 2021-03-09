#include "NonNegativeOctalInteger.h"

#include <iostream>
#include <sstream>

void printUsage() {
	cout << "Usage: oct2hex <non_negative_octal_integer>" << endl;
}

string oct2hex(NonNegativeOctalInteger* x) {
	ostringstream y;
	y << hex << x->toUnsignedLongLong();
	
	return y.str();
}

int main(int argc, char** argv) {
	if (argc != 2) {
		printUsage();
		return 1;
	}
	
	NonNegativeOctalInteger* x = new NonNegativeOctalInteger(argv[1]);
	if (!x->isValid()) {
		printUsage();
		return 1;
	}
	
	string y = oct2hex(x);
	cout << y;
	
	return 0;
}
