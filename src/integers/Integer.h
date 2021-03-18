#pragma once

#include <string>
using namespace std;

class Integer {
private:
	bool valid;
	
	unsigned long long fieldCount;
	long long* fields;
	
	bool isInteger(string x);
	
public:
	Integer(Integer* x);
	Integer(string x);
	
	long long toLongLong();
	bool isValid();
	
	bool lessThan(Integer* x);
	bool lessThanOrEqualTo(Integer* x);
	bool equalTo(Integer* x);
	bool greaterThan(Integer* x);
	bool greaterThanOrEqualTo(Integer* x);
	
	void _not();
};
