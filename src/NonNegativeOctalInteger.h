#pragma once

#include <string>
using namespace std;

class NonNegativeOctalInteger {
private:
	bool valid;
	
	unsigned long long fieldCount;
	unsigned long long* fields;
	
	bool isNonNegativeOctalInteger(string x);
	
public:
	NonNegativeOctalInteger(string x);
	unsigned long long toUnsignedLongLong();
	
	bool isValid();
	bool equalTo(unsigned long long x);
};
