#include "NonNegativeBinaryInteger.h"

#include <iostream>
#include <bitset>

void printUsage() {
	cout << "Usage: bin2dec <non_negative_binary_integer>" << endl;
}

string bin2dec(NonNegativeBinaryInteger* x) {
	string y = to_string(x->toUnsignedLongLong());
	return y;
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
	
	string y = bin2dec(x);
	cout << y;
	
	return 0;
}
