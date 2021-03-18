#include "fact.h"

NonNegativeInteger* fact(NonNegativeInteger* x) {
	if (x->equalTo(0ULL))
		return new NonNegativeInteger(1);
		
	NonNegativeInteger* y = new NonNegativeInteger(1);
	for (NonNegativeInteger* i = new NonNegativeInteger(2); i->lessThanOrEqualTo(x); i->increment())
		y->multiply(i);
		
	return y;
}
