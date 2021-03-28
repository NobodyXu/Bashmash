#include "bico.h"
#include "fact.h"

NonNegativeInteger* bico(NonNegativeInteger* n, NonNegativeInteger* k) {
	//z = n - k
	NonNegativeInteger* z = new NonNegativeInteger(n);
	z->subtract(k);
	
	//w = k! * z!
	NonNegativeInteger* w = fact(k);
	w->multiply(fact(z));
	
	if (w->equalTo(0))
		throw exception();
	
	//y = n! / w
	NonNegativeInteger* y = fact(n);
	y->divide(w);
	
	return y;
}
