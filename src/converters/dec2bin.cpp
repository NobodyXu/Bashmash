#include "dec2bin.h"
#include <bitset>

string dec2bin(NonNegativeInteger* x) {
	bitset<64> bin(x->toUnsignedLongLong());
	string y = bin.to_string();
	
	y.erase(0, y.find_first_not_of('0'));
	return y;
}
