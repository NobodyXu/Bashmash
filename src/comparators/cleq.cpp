#include "cleq.h"

string cleq(NonNegativeInteger* a, NonNegativeInteger* b) {
	return a->lessThanOrEqualTo(b) ? "true" : "false";
}
