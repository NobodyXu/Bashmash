#include "oct2dec.h"

string oct2dec(NonNegativeOctalInteger* x) {
	string y = to_string(x->toUnsignedLongLong());
	return y;
}
