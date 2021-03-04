#include "include/checker.h"

BOOL isInteger(const char* x) {
	char character;
	for (; (character = *x) != '\0'; x++) {
		if (character < '0' || character > '9')
			return FALSE;
	}
	
	return TRUE;
}
