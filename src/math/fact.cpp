#include "fact.h"

NonNegativeInteger* fact(NonNegativeInteger* n) {
	if (n->equalTo(0ULL))
		return new NonNegativeInteger(1);
		
	NonNegativeInteger* y = new NonNegativeInteger(1);
	for (NonNegativeInteger* i = new NonNegativeInteger(2); i->lessThanOrEqualTo(n); i->increment())
		y->multiply(i);
		
	return y;
}
