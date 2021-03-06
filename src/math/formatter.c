#include "include/formatter.h"

const char* cutLeadingZeroes(const char* x) {
	char character;
	int s = 0;
	
	if (*x == '-')
		s = 1;
	
	char* i;
	for (i = (char*)x + s; (character = *i) != '\0'; i++) {
		if (character != '0') {
			if (s) {
				char* y = i - 1;
			
				*y = '-';
				return y;
			}
			
			return i;
		}
	}

	return i - 1;
}
