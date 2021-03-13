#include "NonNegativeHexadecimalInteger.h"
#include <utilities.h>

#include <iostream>
#include <sstream>

using namespace std;
extern "C" {
	#include <loadables.h>
	
	int hex2oct(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeHexadecimalInteger* x = new NonNegativeHexadecimalInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		ostringstream y;
		y << oct << x->toUnsignedLongLong();
	
		cout << y.str();
		return EXECUTION_SUCCESS;
	}
	
	PUBLIC struct builtin hex2oct_struct = {
		(char*)"hex2oct",
		hex2oct,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Hexadecimal to octal conversion",
			(char*)"Converts a given non-negative hexadecimal integer to the octal system.",
			(char*)NULL
		},
		
		"hex2oct <non_negative_hexadecimal_integer>",
		0
	};
	
	PUBLIC int hex2oct_builtin_load(char* name) {
		cout << "Done." << endl;
		return 1;
	}
	
	PUBLIC void hex2oct_builtin_unload(char* name) {
	}
}





#include "NonNegativeHexadecimalInteger.h"
#include <sstream>

string hex2oct(NonNegativeHexadecimalInteger* x) {
	ostringstream y;
	y << oct << x->toUnsignedLongLong();
	
	return y.str();
}
