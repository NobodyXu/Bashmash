#include "cless.h"

string cless(Integer* a, Integer* b) {
	return a->lessThan(b) ? "true" : "false";
}
