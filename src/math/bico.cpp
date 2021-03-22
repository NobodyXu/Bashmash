#include "bico.h"
#include "fact.h"

NonNegativeInteger* bico(NonNegativeInteger* n, NonNegativeInteger* k) {
	NonNegativeInteger* z = new NonNegativeInteger(n);
	z->subtract(k);
	
	NonNegativeInteger* w = fact(k);
	w->multiply(fact(z));
	
	if (w->equalTo(0))
		throw exception();
	
	NonNegativeInteger* y = fact(n);
	y->divide(w);
	
	return y;
}
