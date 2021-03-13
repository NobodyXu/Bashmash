#include "hex2dec.h"

string hex2dec(NonNegativeHexadecimalInteger* x) {
	string y = to_string(x->toUnsignedLongLong());
	return y;
}
