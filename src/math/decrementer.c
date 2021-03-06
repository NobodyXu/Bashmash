#include "include/decrementer.h"
#include <stdlib.h>

const char* decrement(const char* x, int length, int* shift) {
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
		char character = *px - c;
		
		if (character >= '0' && character <= '9') {
			*py = character;
			c = 0;
			
			px--;
			py--;
			
			continue;
		}
		
		*py = s ? '0' : '9';
		if (i == s) {
			if (s) {
				*(py - 2) = '-';
				*(py - 1) = '1';
			
				*shift = 0;
				return y;
			} else {
				*(py - 1) = '-';
				*py = '1';
				
				*shift = 0;
				return y;
			}
		}
		
		px--;
		py--;
	}
	
	if (s) {
		char* oy = y + 1;
		*oy = '-';
		
		*shift = 1;
		return oy;
	}
	
	if (*(y + 1) == '0' && length != 1) {
		*shift = 2;
		return y + 2;
	}
	
	*shift = 1;
	return y + 1;
}
