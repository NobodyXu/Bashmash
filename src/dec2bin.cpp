#include "NonNegativeInteger.h"

#include <iostream>
#include <bitset>

void printUsage() {
	cout << "Usage: dec2bin <non_negative_integer>" << endl;
}

string dec2bin(NonNegativeInteger* x) {
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
	
	NonNegativeInteger* x = new NonNegativeInteger(argv[1]);
	if (!x->isValid()) {
		printUsage();
		return 1;
	}
	
	string y = dec2bin(x);
	cout << y;
	
	return 0;
}
