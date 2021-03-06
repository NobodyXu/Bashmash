#include "include/incrementer.h"
#include <stdlib.h>

const char* increment(const char* x, int length, int* shift) {
	char* y = (char*)malloc(length + 1);
	int i = length - 1;
	
	const char* px = x + i;
	char* py = y + length;
	
	int c = 1;
	int s = 0;
	
	if (*x == '-') {
		c = -1;
		s = 1;
	}
	
	for (; i >= s; i--) {
		char character = *px + c;
	
		if (character >= '0' && character <= '9') {
			*py = character;
			c = 0;
			
			px--;
			py--;
			
			continue;
		}
		
		*py = s ? '9' : '0';
		if (i == s) {
			if (s)
				*(py - 1) = '-';
			else
				*(py - 1) = '1';
			
			*shift = 2;
			return y + 2;
		}
		
		px--;
		py--;
	}
	
	if (s) {
		if (*(y + 2) == '0') {
			if (length == 2)
				return y + 2;
					
			*(y + 2) = '-';
			*shift = 2;
			
			return y + 2;
		} else {
			*(y + 1) = '-';
			*shift = 1;
			
			return y + 1;
		}
	}

	*shift = 1;
	return y + 1;
}
