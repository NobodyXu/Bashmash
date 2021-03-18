#include "cgreq.h"

string cgreq(Integer* a, Integer* b) {
	return a->greaterThanOrEqualTo(b) ? "true" : "false";
}
