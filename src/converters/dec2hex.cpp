#include "dec2hex.h"
#include <sstream>

string dec2hex(NonNegativeInteger* x) {
	ostringstream y;
	y << hex << x->toUnsignedLongLong();
	
	return y.str();
}
