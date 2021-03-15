#include "and.h"

NonNegativeInteger* _and(NonNegativeInteger* a, NonNegativeInteger* b) {
	NonNegativeInteger* y = new NonNegativeInteger(a);
	y->_and(b);
	
	return y;
}
