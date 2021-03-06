#include "include/decrementer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char* decrement(const char* x, int length, int* shift) {
	char* y = (char*)malloc(length);
	int i = length - 1;
	
	const char* px = x + i;
	char* py = y + i;
	
	int c = 1;
	
	for (; i >= 0; i--) {
		char character = *px - c;
		
		if (character >= '0' && character <= '9') {
			*py = character;
			c = 0;
			
			px--;
			py--;
			
			continue;
		}
		
		*py = '9';
		
		px--;
		py--;
	}
	
	if (*y == '0' && length != 1) {
		*shift = 1;
		return y + 1;
	}
	
	*shift = 0;
	return y;
}

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("Usage: decrementer <value>\n");
		return 1;
	}
	
	const char* x = argv[1];
	int len = strlen(x);
	int shift;
	
	printf("%s\n", decrement(x, len, &shift));
	return 0;
}
