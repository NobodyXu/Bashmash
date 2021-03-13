#include "bin2dec.h"

string bin2dec(NonNegativeBinaryInteger* x) {
	string y = to_string(x->toUnsignedLongLong());
	return y;
}
