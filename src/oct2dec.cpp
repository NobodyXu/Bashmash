#include "NonNegativeOctalInteger.h"
#include <utilities.h>

#include <iostream>
using namespace std;

extern "C" {
	#include <loadables.h>
	
	int oct2dec(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeOctalInteger* x = new NonNegativeOctalInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = to_string(x->toUnsignedLongLong());
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	PUBLIC struct builtin oct2dec_struct = {
		(char*)"oct2dec",
		oct2dec,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Octal to decimal conversion",
			(char*)"Converts a given non-negative octal integer to the decimal system.",
			(char*)NULL
		},
		
		"oct2dec <non_negative_octal_integer>",
		0
	};
	
	PUBLIC int oct2dec_builtin_load(char* name) {
		cout << "Done." << endl;
		return 1;
	}
	
	PUBLIC void oct2dec_builtin_unload(char* name) {
	}
}





#include "NonNegativeOctalInteger.h"

string oct2dec(NonNegativeOctalInteger* x) {
	string y = to_string(x->toUnsignedLongLong());
	return y;
}
