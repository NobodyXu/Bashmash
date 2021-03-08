#include "Number.h"

Number::Number(unsigned long long value) {
	fieldCount = 1;
	fields = new unsigned long long[1];
	
	fields[0] = value;
}
