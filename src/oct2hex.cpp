#include "NonNegativeOctalInteger.h"
#include <utilities.h>

#include <iostream>
#include <sstream>

using namespace std;
extern "C" {
	#include <loadables.h>
	
	int oct2hex(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeOctalInteger* x = new NonNegativeOctalInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		ostringstream y;
		y << hex << x->toUnsignedLongLong();
	
		cout << y.str();
		return EXECUTION_SUCCESS;
	}
	
	PUBLIC struct builtin oct2hex_struct = {
		(char*)"oct2hex",
		oct2hex,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Octal to hexadecimal conversion",
			(char*)"Converts a given non-negative octal integer to the hexadecimal system.",
			(char*)NULL
		},
		
		"oct2hex <non_negative_octal_integer>",
		0
	};
	
	PUBLIC int oct2hex_builtin_load(char* name) {
		cout << "Done." << endl;
		return 1;
	}
	
	PUBLIC void oct2hex_builtin_unload(char* name) {
	}
}
