#include "cless.h"

string cless(NonNegativeInteger* a, NonNegativeInteger* b) {
	return a->lessThan(b) ? "true" : "false";
}
