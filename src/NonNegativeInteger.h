#pragma once

#include <string>
using namespace std;

class NonNegativeInteger {
private:
	bool valid;

	unsigned long long fieldCount;
	unsigned long long* fields;
	
public:
	NonNegativeInteger(unsigned long long x);
	NonNegativeInteger(string x);
	
	unsigned long long toUnsignedLongLong();
	string toString();
	
	bool isValid();
	
	bool lessThanOrEqualTo(NonNegativeInteger* x);
	bool equalTo(unsigned long long x);
	
	void increment();
	void multiply(NonNegativeInteger* x);
};
