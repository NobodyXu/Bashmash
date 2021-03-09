#include "NonNegativeInteger.h"

#include <iostream>
#include <sstream>

void printUsage() {
	cout << "Usage: dec2oct <non_negative_integer>" << endl;
}

string dec2oct(NonNegativeInteger* x) {	
	ostringstream y;
	y << oct << x->toUnsignedLongLong();
	
	return y.str();
}

int main(int argc, char** argv) {
	if (argc != 2) {
		printUsage();
		return 1;
	}
	
	NonNegativeInteger* x = new NonNegativeInteger(argv[1]);
	if (!x->isValid()) {
		printUsage();
		return 1;
	}
	
	string y = dec2oct(x);
	cout << y;
	
	return 0;
}
