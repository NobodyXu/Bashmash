#include "oct2hex.h"
#include <sstream>

string oct2hex(NonNegativeOctalInteger* x) {
	ostringstream y;
	y << hex << x->toUnsignedLongLong();
	
	return y.str();
}
