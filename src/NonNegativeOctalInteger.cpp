#include "NonNegativeOctalInteger.h"
#define BASE_OCTAL 8

NonNegativeOctalInteger::NonNegativeOctalInteger(string x) {
	fieldCount = 1;
	fields = new unsigned long long[1];
	
	if (!isNonNegativeOctalInteger(x)) {
		valid = false;
		return;
	}
	
	try {
		fields[0] = stoull(x, 0, BASE_OCTAL);
	} catch (exception& e) {
		valid = false;
		return;
	}
	
	valid = true;
}

unsigned long long NonNegativeOctalInteger::toUnsignedLongLong() {
	return fields[0];
}

bool NonNegativeOctalInteger::isNonNegativeOctalInteger(string x) {
	int length = x.length();
	for (int i = 0; i < length; i++) {
		char character = x.at(i);
		if (character < '0' || character > '7')
			return false;
	}
	
	return true;
}

bool NonNegativeOctalInteger::isValid() {
	return valid;
}
