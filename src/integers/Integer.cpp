#include "Integer.h"

Integer::Integer(Integer* x) {
	fieldCount = 1;
	fields = new long long[1];
	
	fields[0] = x->toLongLong();
	valid = true;
}

Integer::Integer(string x) {
	fieldCount = 1;
	fields = new long long[1];
	
	if (!isInteger(x)) {
		valid = false;
		return;
	}
	
	try {
		fields[0] = stoll(x);
	} catch (exception& e) {
		valid = false;
		return;
	}
	
	valid = true;
}

long long Integer::toLongLong() {
	return fields[0];
}

bool Integer::isInteger(string x) {
	int length = x.length();
	for (int i = 0; i < length; i++) {
		char character = x.at(i);
		if ((character < '0' || character > '9') && character != '-')
			return false;
	}
	
	return true;
}

bool Integer::isValid() {
	return valid;
}

void Integer::_not() {
	fields[0] = ~fields[0];
}
