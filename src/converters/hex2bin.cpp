#include "hex2bin.h"
#include <bitset>

string hex2bin(NonNegativeHexadecimalInteger* x) {
	bitset<64> bin(x->toUnsignedLongLong());
	string y = bin.to_string();
	
	y.erase(0, y.find_first_not_of('0'));
	return y;
}
