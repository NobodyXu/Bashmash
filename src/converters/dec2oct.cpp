#include "dec2oct.h"
#include <sstream>

string dec2oct(NonNegativeInteger* x) {
	ostringstream y;
	y << oct << x->toUnsignedLongLong();
	
	return y.str();
}
