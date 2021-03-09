#include "NonNegativeOctalInteger.h"
#include <iostream>

void printUsage() {
	cout << "Usage: oct2dec <non_negative_octal_integer>" << endl;
}

string oct2dec(NonNegativeOctalInteger* x) {
	string y = to_string(x->toUnsignedLongLong());
	return y;
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
	
	string y = oct2dec(x);
	cout << y;
	
	return 0;
}
