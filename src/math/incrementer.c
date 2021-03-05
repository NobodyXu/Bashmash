#include "include/incrementer.h"
#include <stdlib.h>

const char* increment(const char* x, int length, int* shift) {
	char* y = (char*)malloc(length + 1);
	int i = length - 1;
	
	const char* px = x + i;
	char* py = y + length;
	
	int j = 1;
	for (; i >= 0; i--) {
		char character = *px + j;
	
		if (character >= '0' && character <= '9') {
			*py = character;
			
			*shift = 1;
			j = 0;
			
			px--;
			py--;
			
			continue;
		}
		
		*py = '0';
		if (i == 0) {
			*(py - 1) = '1';
			*shift = 0;
			
			return y;
		}
		
		px--;
		py--;
	}
	
	return y + 1;
}
