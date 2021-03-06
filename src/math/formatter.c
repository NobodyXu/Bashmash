#include "include/formatter.h"

const char* cutLeadingZeroes(const char* x) {
	char character;
	
	if (*x == '-')
		x++;
	
	const char* i;
	for (i = x; (character = *i) != '\0'; i++) {
		if (character != '0')
			return i;
	}
	
	return x;
}
