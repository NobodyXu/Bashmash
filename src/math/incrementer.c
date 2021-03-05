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
		
		py--;
	}
	
	for (; i >= s; i--) {
		char character = *px + c;
	
		if (character >= '0' && character <= '9') {
			*py = character;
			
			*shift = 1;
			c = 0;
			
			px--;
			py--;
			
			if (s) {
				if (*(y + 1) == '0') {
					if (length == 2)
						return y + 1;
						
					*(y + 1) = '-';
				} else
					*y = '-';
			}
			
			continue;
		}
		
		*py = s ? '9' : '0';
		if (i == s) {
			if (s)
				*(py - 1) = '-';
			else
				*(py - 1) = '1';
			
			*shift = 0;
			return y;
		}
		
		px--;
		py--;
	}

	if (s && *(y + 1) != '-')
		return y;
	else
		return y + 1;
}
