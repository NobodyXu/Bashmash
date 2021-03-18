#pragma once

#include <string>
using namespace std;

class NonNegativeInteger {
private:
	bool valid;

	unsigned long long fieldCount;
	unsigned long long* fields;
	
	bool isNonNegativeInteger(string x);
	
public:
	NonNegativeInteger(NonNegativeInteger* x);

	NonNegativeInteger(unsigned long long x);
	NonNegativeInteger(string x);
	
	unsigned long long toUnsignedLongLong();
	string toString();
	
	bool isValid();
	
	bool lessThan(NonNegativeInteger* x);
	bool lessThanOrEqualTo(NonNegativeInteger* x);
	
	bool equalTo(NonNegativeInteger* x);
	bool equalTo(unsigned long long x);
	
	bool greaterThan(NonNegativeInteger* x);
	bool greaterThanOrEqualTo(NonNegativeInteger* x);
	
	void _or(NonNegativeInteger* x);
	void _and(NonNegativeInteger* x);
	void _xor(NonNegativeInteger* x);
	
	void increment();
	void multiply(NonNegativeInteger* x);
};
