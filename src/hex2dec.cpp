#include "NonNegativeHexadecimalInteger.h"
#include <utilities.h>

#include <iostream>
using namespace std;

extern "C" {
	#include <loadables.h>
	
	int hex2dec(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeHexadecimalInteger* x = new NonNegativeHexadecimalInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = to_string(x->toUnsignedLongLong());
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	PUBLIC struct builtin hex2dec_struct = {
		(char*)"hex2dec",
		hex2dec,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Hexadecimal to decimal conversion",
			(char*)"Converts a given non-negative hexadecimal integer to the decimal system.",
			(char*)NULL
		},
		
		"hex2dec <non_negative_hexadecimal_integer>",
		0
	};
	
	PUBLIC int hex2dec_builtin_load(char* name) {
		cout << "Done." << endl;
		return 1;
	}
	
	PUBLIC void hex2dec_builtin_unload(char* name) {
	}
}
