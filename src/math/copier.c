#include "include/copier.h"

const char* copy(const char* x, int length) {
	char* y = (char*)malloc(length);
	
	int i;
	char* dst = y;
	
	for (i = 0; i < length; i++) {
		*y = *x;
		
		x++;
		dst++;
	}
	
	return oldY;
}
