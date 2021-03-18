#include "ceq.h"

string ceq(Integer* a, Integer* b) {
	return a->equalTo(b) ? "true" : "false";
}
