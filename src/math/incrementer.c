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
		char* oy = y + 2;
		
		if (*oy == '0') {
			if (length == 2)
				return oy;
					
			*oy = '-';
			*shift = 2;
			
			return oy;
		} else {
			oy--;
			*oy = '-';
			
			*shift = 1;
			return oy;
		}
	}

	*shift = 1;
	return y + 1;
}

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("Usage: incrementer <value>");
		return 1;
	}
	
	const char* x = argv[1];
	int len = strlen(x);
	int shift;
	
	printf("%s\n", increment(x, len, &shift));
	return 0;
}
