#include "hex2oct.h"
#include <sstream>

string hex2oct(NonNegativeHexadecimalInteger* x) {
	ostringstream y;
	y << oct << x->toUnsignedLongLong();
	
	return y.str();
}
