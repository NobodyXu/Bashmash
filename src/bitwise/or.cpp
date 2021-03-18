#include "or.h"

NonNegativeInteger* _or(NonNegativeInteger* a, NonNegativeInteger* b) {
	NonNegativeInteger* y = new NonNegativeInteger(a);
	y->_or(b);
	
	return y;
}
