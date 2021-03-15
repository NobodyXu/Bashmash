#include "NonNegativeInteger.h"

NonNegativeInteger::NonNegativeInteger(NonNegativeInteger* x) {
	fieldCount = 1;
	fields = new unsigned long long[1];
	
	fields[0] = x->toUnsignedLongLong();
	valid = true;
}

NonNegativeInteger::NonNegativeInteger(unsigned long long x) {
	fieldCount = 1;
	fields = new unsigned long long[1];
	
	fields[0] = x;
	valid = true;
}

NonNegativeInteger::NonNegativeInteger(string x) {
	fieldCount = 1;
	fields = new unsigned long long[1];
	
	if (!isNonNegativeInteger(x)) {
		valid = false;
		return;
	}
	
	try {
		fields[0] = stoull(x);
	} catch (exception& e) {
		valid = false;
		return;
	}
	
	valid = true;
}

unsigned long long NonNegativeInteger::toUnsignedLongLong() {
	return fields[0];
}

string NonNegativeInteger::toString() {
	return to_string(fields[0]);
}

bool NonNegativeInteger::isNonNegativeInteger(string x) {
	int length = x.length();
	for (int i = 0; i < length; i++) {
		char character = x.at(i);
		if (character < '0' || character > '9')
			return false;
	}
	
	return true;
}

bool NonNegativeInteger::isValid() {
	return valid;
}

bool NonNegativeInteger::lessThanOrEqualTo(NonNegativeInteger* x) {
	return fields[0] <= x->toUnsignedLongLong();
}

bool NonNegativeInteger::equalTo(unsigned long long x) {
	return fields[0] == x;
}

void NonNegativeInteger::_not() {
	fields[0] = ~fields[0];
}

void NonNegativeInteger::_or(NonNegativeInteger* x) {
	fields[0] |= x->toUnsignedLongLong();
}

void NonNegativeInteger::_and(NonNegativeInteger* x) {
	fields[0] &= x->toUnsignedLongLong();
}

void NonNegativeInteger::_xor(NonNegativeInteger* x) {
	fields[0] ^= x->toUnsignedLongLong();
}

void NonNegativeInteger::increment() {
	fields[0]++;
}

void NonNegativeInteger::multiply(NonNegativeInteger* x) {
	fields[0] *= x->toUnsignedLongLong();
}
