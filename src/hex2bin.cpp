#include "NonNegativeHexadecimalInteger.h"
#include <utilities.h>

#include <iostream>
#include <bitset>
using namespace std;

extern "C" {
	#include <loadables.h>
	
	int hex2bin(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeHexadecimalInteger* x = new NonNegativeHexadecimalInteger(argv[0]);
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
	
	PUBLIC struct builtin hex2bin_struct = {
		(char*)"",
		hex2bin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Hexadecimal to binary conversion",
			(char*)"Converts a given non-negative hexadecimal integer to the binary system.",
			(char*)NULL
		},
		
		"hex2bin <non_negative_hexadecimal_integer>",
		0
	};
	
	PUBLIC int hex2bin_builtin_load(char* name) {
		cout << "Done." << endl;
		return 1;
	}
	
	PUBLIC void hex2bin_builtin_unload(char* name) {
	}
}
