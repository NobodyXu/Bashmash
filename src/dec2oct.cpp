#include "NonNegativeInteger.h"
#include <utilities.h>

#include <iostream>
#include <sstream>

using namespace std;
extern "C" {
	#include <loadables.h>
	
	int dec2oct(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeInteger* x = new NonNegativeInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		ostringstream y;
		y << oct << x->toUnsignedLongLong();
		
		cout << y.str();
		return EXECUTION_SUCCESS;
	}
	
	PUBLIC struct builtin dec2oct = {
		(char*)"dec2oct",
		dec2oct,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Decimal to octal conversion",
			(char*)"Converts a given non-negative decimal integer to the octal system.",
			(char*)NULL
		},
		
		"dec2oct <non_negative_integer>",
		0
	};
	
	PUBLIC int dec2oct_builtin_load(char* name) {
		cout << "Done." << endl;
		return 1;
	}
	
	PUBLIC void dec2oct_builtin_unload(char* name) {
	}
}
