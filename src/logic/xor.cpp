#include "xor.h"

NonNegativeInteger* _xor(NonNegativeInteger* a, NonNegativeInteger* b) {
	NonNegativeInteger* y = new NonNegativeInteger(a);
	y->_xor(b);
	
	return y;
}
