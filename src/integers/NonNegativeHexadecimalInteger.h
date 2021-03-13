#pragma once

#include <string>
using namespace std;

class NonNegativeHexadecimalInteger {
private:
	bool valid;
	
	unsigned long long fieldCount;
	unsigned long long* fields;
	
	bool isNonNegativeHexadecimalInteger(string x);
	
public:
	NonNegativeHexadecimalInteger(string x);
	unsigned long long toUnsignedLongLong();
	
	bool isValid();
	bool equalTo(unsigned long long x);
};
