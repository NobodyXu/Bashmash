#pragma once

#include <string>
using namespace std;

class NonNegativeBinaryInteger {
private:
	bool valid;

	unsigned long long fieldCount;
	unsigned long long* fields;
	
	bool isNonNegativeBinaryInteger(string x);
	
public:
	NonNegativeBinaryInteger(string x);
	unsigned long long toUnsignedLongLong();
	
	bool isValid();
};
