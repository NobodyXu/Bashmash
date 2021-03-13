#include "NonNegativeInteger.h"

#include <iostream>
#include <utilities.h>

using namespace std;
extern "C" {
	#include <loadables.h>
	
	int fact(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
		
		NonNegativeInteger* x = new NonNegativeInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		if (x->equalTo(0)) {
			cout << "1";
			return EXECUTION_SUCCESS;
		}
		
		NonNegativeInteger* y = new NonNegativeInteger(1);
		for (NonNegativeInteger* i = new NonNegativeInteger(2); i->lessThanOrEqualTo(x); i->increment())
			y->multiply(i);
		
		cout << y->toUnsignedLongLong();
		return EXECUTION_SUCCESS;
	}
	
	PUBLIC struct builtin fact_struct = {
		(char*)"fact",
		fact,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Factorial",
			(char*)"Outputs a factorial of a given non-negative integer.",
			(char*) NULL
		},
		
		"fact <non_negative_integer>",
		0
	};
	
	PUBLIC int fact_builtin_load(char* name) {
		cout << "Done." << endl;
		return 1;
	}
	
	PUBLIC void fact_builtin_unload(char* name) {
	}
}
