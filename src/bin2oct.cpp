#include "NonNegativeBinaryInteger.h"
#include <utilities.h>

#include <iostream>
#include <sstream>

using namespace std;
extern "C" {
	#include <loadables.h>
	
	int bin2oct(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeBinaryInteger* x = new NonNegativeBinaryInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		ostringstream y;
		y << oct << x->toUnsignedLongLong();
		
		cout << y.str();
		return EXECUTION_SUCCESS;
	}
	
	PUBLIC struct builtin bin2oct_struct = {
		(char*)"bin2oct",
		bin2oct,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Binary to octal conversion",
			(char*)"Converts a given non-negative binary integer to the octal system.",
			(char*)NULL
		},
		
		"bin2oct <non_negative_binary_integer>",
		0
	};
	
	PUBLIC int bin2oct_builtin_load(char* name) {
		cout << "Done." << endl;
		return 1;
	}
	
	PUBLIC void bin2oct_builtin_unload(char* name) {
	}
}
