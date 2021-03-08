#include "NonNegativeInteger.h"
#include <iostream>

void printUsage() {
	cout << "Usage: fact <non_negative_integer>" << endl;
}

NonNegativeInteger* fact(NonNegativeInteger* x) {
	if (x->equalTo(0))
		return new NonNegativeInteger(1);
		
	NonNegativeInteger* y = new NonNegativeInteger(1);
	for (NonNegativeInteger* i = new NonNegativeInteger(2); i->lessThanOrEqualTo(x); i->increment())
		y->multiply(i);
	
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
	
	NonNegativeInteger* y = fact(x);
	cout << y->toString();
	
	return 0;
}
