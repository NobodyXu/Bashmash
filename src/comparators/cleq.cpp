#include "cleq.h"

string cleq(Integer* a, Integer* b) {
	return a->lessThanOrEqualTo(b) ? "true" : "false";
}
