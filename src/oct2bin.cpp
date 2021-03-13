#include "NonNegativeOctalInteger.h"
#include <utilities.h>

#include <iostream>
#include <bitset>

using namespace std;
extern "C" {
	#include <loadables.h>
	
	int oct2bin(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeOctalInteger* x = new NonNegativeOctalInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		if (x->equalTo(0)) {
			cout << "0";
			return EXECUTION_SUCCESS;
		}
		
		bitset<64> bin(x->toUnsignedLongLong());
		string y = bin.to_string();
		
		y.erase(0, y.find_first_not_of('0'));
		cout << y;
		
		return EXECUTION_SUCCESS;
	}
	
	PUBLIC struct builtin oct2bin_struct = {
		(char*)"oct2bin",
		oct2bin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Octal to binary conversion",
			(char*)"Converts a given non-negative octal integer to the binary system.",
			(char*)NULL
		},
		
		"oct2bin <non_negative_octal_integer>",
		0
	};
	
	PUBLIC int oct2bin_builtin_load(char* name) {
		cout << "Done." << endl;
		return 1;
	}
	
	PUBLIC void oct2bin_builtin_unload(char* name) {
	}
}
