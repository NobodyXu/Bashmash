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
	
	void _not();
};
