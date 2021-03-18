#include "integers/NonNegativeBinaryInteger.h"
#include "integers/NonNegativeOctalInteger.h"
#include "integers/NonNegativeInteger.h"
#include "integers/NonNegativeHexadecimalInteger.h"

#include "math/fact.h"

#include "bitwise/not.h"
#include "bitwise/or.h"
#include "bitwise/and.h"
#include "bitwise/xor.h"

#include "comparators/cless.h"
#include "comparators/cleq.h"
#include "comparators/ceq.h"
#include "comparators/cgreq.h"
#include "comparators/cgreat.h"

#include "converters/bin2oct.h"
#include "converters/bin2dec.h"
#include "converters/bin2hex.h"

#include "converters/oct2bin.h"
#include "converters/oct2dec.h"
#include "converters/oct2hex.h"

#include "converters/dec2bin.h"
#include "converters/dec2oct.h"
#include "converters/dec2hex.h"

#include "converters/hex2bin.h"
#include "converters/hex2oct.h"
#include "converters/hex2dec.h"

#include <iostream>
using namespace std;

extern "C" {
	#include <utilities.h>
	
	int fact_builtin(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeInteger* x = new NonNegativeInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = to_string(fact(x)->toUnsignedLongLong());
		cout << y;
		
		return EXECUTION_SUCCESS;
	}
	
	int not_builtin(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		Integer* x = new Integer(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = to_string(_not(x)->toLongLong());
		cout << y;
		
		return EXECUTION_SUCCESS;
	}
	
	int or_builtin(WORD_LIST* wordList) {
		const char* argv[2];
		if (to_argv(wordList, 2, argv) == -1)
			return EX_USAGE;
			
		NonNegativeInteger* a = new NonNegativeInteger(argv[0]);
		if (!a->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		NonNegativeInteger* b = new NonNegativeInteger(argv[1]);
		if (!b->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = to_string(_or(a, b)->toUnsignedLongLong());
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	int and_builtin(WORD_LIST* wordList) {
		const char* argv[2];
		if (to_argv(wordList, 2, argv) == -1)
			return EX_USAGE;
			
		NonNegativeInteger* a = new NonNegativeInteger(argv[0]);
		if (!a->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		NonNegativeInteger* b = new NonNegativeInteger(argv[1]);
		if (!b->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = to_string(_and(a, b)->toUnsignedLongLong());
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	int xor_builtin(WORD_LIST* wordList) {
		const char* argv[2];
		if (to_argv(wordList, 2, argv) == -1)
			return EX_USAGE;
			
		NonNegativeInteger* a = new NonNegativeInteger(argv[0]);
		if (!a->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		NonNegativeInteger* b = new NonNegativeInteger(argv[1]);
		if (!b->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = to_string(_xor(a, b)->toUnsignedLongLong());
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	int cless_builtin(WORD_LIST* wordList) {
		const char* argv[2];
		if (to_argv(wordList, 2, argv) == -1)
			return EX_USAGE;
			
		Integer* a = new Integer(argv[0]);
		if (!a->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		Integer* b = new Integer(argv[1]);
		if (!b->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = cless(a, b);
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	int cleq_builtin(WORD_LIST* wordList) {
		const char* argv[2];
		if (to_argv(wordList, 2, argv) == -1)
			return EX_USAGE;
			
		Integer* a = new Integer(argv[0]);
		if (!a->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		Integer* b = new Integer(argv[1]);
		if (!b->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = cleq(a, b);
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	int ceq_builtin(WORD_LIST* wordList) {
		const char* argv[2];
		if (to_argv(wordList, 2, argv) == -1)
			return EX_USAGE;
			
		Integer* a = new Integer(argv[0]);
		if (!a->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		Integer* b = new Integer(argv[1]);
		if (!b->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = ceq(a, b);
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	int cgreq_builtin(WORD_LIST* wordList) {
		const char* argv[2];
		if (to_argv(wordList, 2, argv) == -1)
			return EX_USAGE;
			
		Integer* a = new Integer(argv[0]);
		if (!a->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		Integer* b = new Integer(argv[1]);
		if (!b->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = cgreq(a, b);
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	int cgreat_builtin(WORD_LIST* wordList) {
		const char* argv[2];
		if (to_argv(wordList, 2, argv) == -1)
			return EX_USAGE;
			
		Integer* a = new Integer(argv[0]);
		if (!a->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		Integer* b = new Integer(argv[1]);
		if (!b->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = cgreat(a, b);
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	int bin2oct_builtin(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeBinaryInteger* x = new NonNegativeBinaryInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = bin2oct(x);
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	int bin2dec_builtin(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeBinaryInteger* x = new NonNegativeBinaryInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = bin2dec(x);
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	int bin2hex_builtin(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeBinaryInteger* x = new NonNegativeBinaryInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = bin2hex(x);
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	int oct2bin_builtin(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeOctalInteger* x = new NonNegativeOctalInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = oct2bin(x);
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	int oct2dec_builtin(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeOctalInteger* x = new NonNegativeOctalInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = oct2dec(x);
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	int oct2hex_builtin(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeOctalInteger* x = new NonNegativeOctalInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = oct2hex(x);
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	int dec2bin_builtin(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeInteger* x = new NonNegativeInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = dec2bin(x);
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	int dec2oct_builtin(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeInteger* x = new NonNegativeInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = dec2oct(x);
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	int dec2hex_builtin(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeInteger* x = new NonNegativeInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = dec2hex(x);
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	int hex2bin_builtin(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeHexadecimalInteger* x = new NonNegativeHexadecimalInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = hex2bin(x);
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	int hex2oct_builtin(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeHexadecimalInteger* x = new NonNegativeHexadecimalInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = hex2oct(x);
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	int hex2dec_builtin(WORD_LIST* wordList) {
		const char* argv[1];
		if (to_argv(wordList, 1, argv) == -1)
			return EX_USAGE;
			
		NonNegativeHexadecimalInteger* x = new NonNegativeHexadecimalInteger(argv[0]);
		if (!x->isValid()) {
			builtin_usage();
			return EX_USAGE;
		}
		
		string y = hex2dec(x);
		cout << y;
	
		return EXECUTION_SUCCESS;
	}
	
	PUBLIC struct builtin fact_struct = {
		(char*)"fact",
		fact_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Factorial",
			(char*)"Calculates a factorial.",
			(char*)NULL
		},
		
		"fact <non_negative_integer>",
		0
	};
	
	PUBLIC struct builtin not_struct = {
		(char*)"not",
		not_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"NOT",
			(char*)"Performs a bitwise NOT operation.",
			(char*)NULL
		},
		
		"not <integer>",
		0
	};
	
	PUBLIC struct builtin or_struct = {
		(char*)"or",
		or_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"OR",
			(char*)"Performs a bitwise OR operation.",
			(char*)NULL
		},
		
		"or <non_negative_integer> <non_negative_integer>",
		0
	};
	
	PUBLIC struct builtin and_struct = {
		(char*)"and",
		and_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"AND",
			(char*)"Performs a bitwise AND operation.",
			(char*)NULL
		},
		
		"and <non_negative_integer> <non_negative_integer>",
		0
	};
	
	PUBLIC struct builtin xor_struct = {
		(char*)"xor",
		xor_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"XOR",
			(char*)"Performs a bitwise XOR operation.",
			(char*)NULL
		},
		
		"xor <non_negative_integer> <non_negative_integer>",
		0
	};
	
	PUBLIC struct builtin cless_struct = {
		(char*)"cless",
		cless_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Less than",
			(char*)"Checks if the first number is less than the second one.",
			(char*)NULL
		},
		
		"cless <integer> <integer>",
		0
	};
	
	PUBLIC struct builtin cleq_struct = {
		(char*)"cleq",
		cleq_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Less than or equal to",
			(char*)"Checks if the first number is less than or equal to the second one.",
			(char*)NULL
		},
		
		"cleq <integer> <integer>",
		0
	};
	
	PUBLIC struct builtin ceq_struct = {
		(char*)"ceq",
		ceq_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Equal to",
			(char*)"Checks if the first number is equal to the second one.",
			(char*)NULL
		},
		
		"ceq <integer> <integer>",
		0
	};
	
	PUBLIC struct builtin cgreq_struct = {
		(char*)"cgreq",
		cgreq_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Greater than or equal to",
			(char*)"Checks if the first number is greater than or equal to the second one.",
			(char*)NULL
		},
		
		"cgreq <integer> <integer>",
		0
	};
	
	PUBLIC struct builtin cgreat_struct = {
		(char*)"cgreat",
		cgreat_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Greater than",
			(char*)"Checks if the first number is greater than the second one.",
			(char*)NULL
		},
		
		"cgreat <integer> <integer>",
		0
	};
	
	PUBLIC struct builtin bin2oct_struct = {
		(char*)"bin2oct",
		bin2oct_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Binary to octal",
			(char*)"Converts a given non-negative binary integer to the octal system.",
			(char*)NULL
		},
		
		"bin2oct <non_negative_binary_integer>",
		0
	};
	
	PUBLIC struct builtin bin2dec_struct = {
		(char*)"bin2dec",
		bin2dec_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Binary to decimal",
			(char*)"Converts a given non-negative binary integer to the decimal system.",
			(char*)NULL
		},
		
		"bin2dec <non_negative_binary_integer>",
		0
	};
	
	PUBLIC struct builtin bin2hex_struct = {
		(char*)"bin2hex",
		bin2hex_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Binary to hexadecimal",
			(char*)"Converts a given non-negative binary integer to the hexadecimal system.",
			(char*)NULL
		},
		
		"bin2hex <non_negative_binary_integer>",
		0
	};
	
	PUBLIC struct builtin oct2bin_struct = {
		(char*)"oct2bin",
		oct2bin_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Octal to binary",
			(char*)"Converts a given non-negative octal integer to the binary system.",
			(char*)NULL
		},
		
		"oct2bin <non_negative_octal_integer>",
		0
	};
	
	PUBLIC struct builtin oct2dec_struct = {
		(char*)"oct2dec",
		oct2dec_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Octal to decimal",
			(char*)"Converts a given non-negative octal integer to the decimal system.",
			(char*)NULL
		},
		
		"oct2dec <non_negative_octal_integer>",
		0
	};
	
	PUBLIC struct builtin oct2hex_struct = {
		(char*)"oct2hex",
		oct2hex_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Octal to hexadecimal",
			(char*)"Converts a given non-negative octal integer to the hexadecimal system.",
			(char*)NULL
		},
		
		"oct2hex <non_negative_octal_integer>",
		0
	};
	
	PUBLIC struct builtin dec2bin_struct = {
		(char*)"dec2bin",
		dec2bin_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Decimal to binary",
			(char*)"Converts a given non-negative decimal integer to the binary system.",
			(char*)NULL
		},
		
		"dec2bin <non_negative_decimal_integer>",
		0
	};
	
	PUBLIC struct builtin dec2oct_struct = {
		(char*)"dec2oct",
		dec2oct_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Decimal to octal",
			(char*)"Converts a given non-negative decimal integer to the octal system.",
			(char*)NULL
		},
		
		"dec2oct <non_negative_decimal_integer>",
		0
	};
	
	PUBLIC struct builtin dec2hex_struct = {
		(char*)"dec2hex",
		dec2hex_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Decimal to hexadecimal",
			(char*)"Converts a given non-negative decimal integer to the hexadecimal system.",
			(char*)NULL
		},
		
		"dec2hex <non_negative_decimal_integer>",
		0
	};
	
	PUBLIC struct builtin hex2bin_struct = {
		(char*)"hex2bin",
		hex2bin_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Hexadecimal to binary",
			(char*)"Converts a given non-negative hexadecimal integer to the binary system.",
			(char*)NULL
		},
		
		"hex2bin <non_negative_hexadecimal_integer>",
		0
	};
	
	PUBLIC struct builtin hex2oct_struct = {
		(char*)"hex2oct",
		hex2oct_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Hexadecimal to octal",
			(char*)"Converts a given non-negative hexadecimal integer to the octal system.",
			(char*)NULL
		},
		
		"hex2oct <non_negative_hexadecimal_integer>",
		0
	};
	
	PUBLIC struct builtin hex2dec_struct = {
		(char*)"hex2dec",
		hex2dec_builtin,
		
		BUILTIN_ENABLED,
		(char*[]) {
			(char*)"Hexadecimal to decimal",
			(char*)"Converts a given non-negative hexadecimal integer to the decimal system.",
			(char*)NULL
		},
		
		"hex2dec <non_negative_hexadecimal_integer>",
		0
	};
	
	PUBLIC int fact_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC int not_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC int or_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC int and_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC int xor_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC int cless_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC int cleq_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC int ceq_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC int cgreq_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC int cgreat_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC int bin2oct_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC int bin2dec_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC int bin2hex_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC int oct2bin_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC int oct2dec_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC int oct2hex_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC int dec2bin_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC int dec2oct_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC int dec2hex_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC int hex2bin_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC int hex2oct_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC int hex2dec_builtin_load(char* name) {
		return 1;
	}
	
	PUBLIC void fact_builtin_unload(char* name) {
	}
	
	PUBLIC void not_builtin_unload(char* name) {
	}
	
	PUBLIC void or_builtin_unload(char* name) {
	}
	
	PUBLIC void and_builtin_unload(char* name) {
	}
	
	PUBLIC void xor_builtin_unload(char* name) {
	}
	
	PUBLIC void cless_builtin_unload(char* name) {
	}
	
	PUBLIC void cleq_builtin_unload(char* name) {
	}
	
	PUBLIC void ceq_builtin_unload(char* name) {
	}
	
	PUBLIC void cgreq_builtin_unload(char* name) {
	}
	
	PUBLIC void cgreat_builtin_unload(char* name) {
	}
	
	PUBLIC void bin2oct_builtin_unload(char* name) {
	}
	
	PUBLIC void bin2dec_builtin_unload(char* name) {
	}
	
	PUBLIC void bin2hex_builtin_unload(char* name) {
	}
	
	PUBLIC void oct2bin_builtin_unload(char* name) {
	}
	
	PUBLIC void oct2dec_builtin_unload(char* name) {
	}
	
	PUBLIC void oct2hex_builtin_unload(char* name) {
	}
	
	PUBLIC void dec2bin_builtin_unload(char* name) {
	}
	
	PUBLIC void dec2oct_builtin_unload(char* name) {
	}
	
	PUBLIC void dec2hex_builtin_unload(char* name) {
	}
	
	PUBLIC void hex2bin_builtin_unload(char* name) {
	}
	
	PUBLIC void hex2oct_builtin_unload(char* name) {
	}
	
	PUBLIC void hex2dec_builtin_unload(char* name) {
	}
}
