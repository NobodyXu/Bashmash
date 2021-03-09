#include "NonNegativeHexadecimalInteger.h"
#define BASE_HEXADECIMAL 16

NonNegativeHexadecimalInteger::NonNegativeHexadecimalInteger(string x) {
	fieldCount = 1;
	fields = new unsigned long long[1];
	
	if (!isNonNegativeHexadecimalInteger(x)) {
		valid = false;
		return;
	}
	
	try {
		fields[0] = stoull(x, 0, BASE_HEXADECIMAL);
	} catch (exception& e) {
		valid = false;
		return;
	}
	
	valid = true;
}

unsigned long long NonNegativeHexadecimalInteger::toUnsignedLongLong() {
	return fields[0];
}

bool NonNegativeHexadecimalInteger::isNonNegativeHexadecimalInteger(string x) {
	int length = x.length();
	for (int i = 0; i < length; i++) {
		char character = x.at(i);
		if ((character < '0' || character > '9') && (character < 'A' || character > 'F') && (character < 'a' || character > 'f'))
			return false;
	}
	
	return true;
}

bool NonNegativeHexadecimalInteger::isValid() {
	return valid;
}

bool NonNegativeHexadecimalInteger::equalTo(unsigned long long x) {
	return fields[0] == x;
}
