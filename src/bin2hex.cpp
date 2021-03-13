#include "NonNegativeBinaryInteger.h"
#include <utilities.h>

#include <iostream>
#include <sstream>

using namespace std;
extern "C" {
	#include <loadables.h>
	
	int bin2hex(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
	
		NonNegativeBinaryInteger* x = new NonNegativeBinaryInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		ostringstream y;
		y << hex << x->toUnsignedLongLong();
	
		cout << y.str();
		return EXECUTION_SUCCESS;
	}
	
	PUBLIC struct builtin bin2hex_struct = {
		(char*)"",
		bin2hex,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Binary to hexadecimal conversion",
			(char*)"Converts a given non-negative binary integer to the hexadecimal system.",
			(char*)NULL
		},
		
		"bin2hex <non_negative_binary_integer>",
		0
	};
	
	PUBLIC int bin2hex_builtin_load(char* name) {
		cout << "Done." << endl;
		return 1;
	}
	
	PUBLIC void bin2hex_builtin_unload(char* name) {
	}
}
