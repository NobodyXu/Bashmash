#include "NonNegativeBinaryInteger.h"
#define BASE_BINARY 2

NonNegativeBinaryInteger::NonNegativeBinaryInteger(string x) {
	fieldCount = 1;
	fields = new unsigned long long[1];
	
	if (!isNonNegativeBinaryInteger(x)) {
		valid = false;
		return;
	}
	
	try {
		fields[0] = stoull(x, 0, BASE_BINARY);
	} catch (exception& e) {
		valid = false;
		return;
	}
	
	valid = true;
}

unsigned long long NonNegativeBinaryInteger::toUnsignedLongLong() {
	return fields[0];
}

bool NonNegativeBinaryInteger::isNonNegativeBinaryInteger(string x) {
	int length = x.length();
	for (int i = 0; i < length; i++) {
		char character = x.at(i);
		if (character != '0' && character != '1')
			return false;
	}
		
	return true;
}

bool NonNegativeBinaryInteger::isValid() {
	return valid;
}
