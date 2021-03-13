#include "bin2oct.h"
#include <sstream>

string bin2oct(NonNegativeBinaryInteger* x) {
	ostringstream y;
	y << oct << x->toUnsignedLongLong();
	
	return y.str();
}
