#include "cgreq.h"

string cgreq(NonNegativeInteger* a, NonNegativeInteger* b) {
	return a->greaterThanOrEqualTo(b) ? "true" : "false";
}
