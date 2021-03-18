#include "cgreat.h"

string cgreat(Integer* a, Integer* b) {
	return a->greaterThan(b) ? "true" : "false";
}
