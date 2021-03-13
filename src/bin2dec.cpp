#include "NonNegativeBinaryInteger.h"
#include <utilities.h>

#include <iostream>
using namespace std;

extern "C" {
	#include <loadables.h>
	
	int bin2dec(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeBinaryInteger* x = new NonNegativeBinaryInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = to_string(x->toUnsignedLongLong());
		cout << y;
		
		return EXECUTION_SUCCESS;
	}
	
	PUBLIC struct builtin bin2dec_struct = {
		(char*)"bin2dec",
		bin2dec,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Binary to decimal conversion",
			(char*)"Converts a given non-negative binary integer to the decimal system.",
			(char*)NULL
		},
		
		"bin2dec <non_negative_binary_integer>",
		0
	};
	
	PUBLIC int bin2dec_builtin_load(char* name) {
		cout << "Done." << endl;
		return 1;
	}
	
	PUBLIC void bin2dec_builtin_unload(char* name) {
	}
}
