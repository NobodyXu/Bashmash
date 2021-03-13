#include "bin2hex.h"
#include <sstream>

string bin2hex(NonNegativeBinaryInteger* x) {
	ostringstream y;
	y << hex << x->toUnsignedLongLong();
	
	return y.str();
}
