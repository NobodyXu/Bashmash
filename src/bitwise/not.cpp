#include "not.h"

Integer* _not(Integer* x) {
	Integer* y = new Integer(x);
	y->_not();
	
	return y;
}
