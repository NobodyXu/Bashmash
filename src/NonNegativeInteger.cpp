#include "NonNegativeInteger.h"

NonNegativeInteger::NonNegativeInteger(unsigned long long x) {
	fieldCount = 1;
	fields = new unsigned long long[1];
	
	fields[0] = x;
	valid = true;
}

NonNegativeInteger::NonNegativeInteger(string x) {
	fieldCount = 1;
	fields = new unsigned long long[1];
	
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

bool NonNegativeInteger::isValid() {
	return valid;
}

bool NonNegativeInteger::lessThanOrEqualTo(NonNegativeInteger* x) {
	return fields[0] <= x->toUnsignedLongLong();
}

bool NonNegativeInteger::equalTo(unsigned long long x) {
	return fields[0] == x;
}

void NonNegativeInteger::increment() {
	fields[0]++;
}

void NonNegativeInteger::multiply(NonNegativeInteger* x) {
	fields[0] *= x->toUnsignedLongLong();
}
