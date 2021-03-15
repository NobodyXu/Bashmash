#include "not.h"

NonNegativeInteger* _not(NonNegativeInteger* x) {
	NonNegativeInteger* y = new NonNegativeInteger(x);
	y->_not();
	
	return y;
}
