#include "cgreat.h"

string cgreat(NonNegativeInteger* a, NonNegativeInteger* b) {
	return a->greaterThan(b) ? "true" : "false";
}
