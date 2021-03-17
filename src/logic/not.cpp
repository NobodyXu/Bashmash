#include "not.h"
#include <sstream>

string _not(NonNegativeInteger* x) {
	NonNegativeInteger* y = new NonNegativeInteger(x);
	if (y->equalTo(0xFFFFFFFFFFFFFFFFL))
		return "-18446744073709551616";
	
	y->increment();
	ostringstream yString;
	
	yString << "-" << y->toUnsignedLongLong();
	return yString.str();
}
