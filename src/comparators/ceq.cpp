#include "ceq.h"

string ceq(NonNegativeInteger* a, NonNegativeInteger* b) {
	return a->equalTo(b) ? "true" : "false";
}
