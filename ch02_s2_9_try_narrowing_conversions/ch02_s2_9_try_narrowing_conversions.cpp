// /PPP3/ch02_s2_9_try_narrowing_conversions/ch02_s2_9_try_narrowing_conversions.cpp

// PURPOSE: 
// - Demonstrate the potential dangers of information and/or precision loss
// inherent with implicit narrowing conversions.
// - Show the result of assigning a value stored in a larger memory allocated type
// to a variable of a smaller memory allocated type.
// - double => int (precision loss) and int => char (machine dependant, information loss).

// PRECONDITIONS:
// - Input of valid double type numeric values or EOF.
// - User terminates program by executing an EOF (Windows: Ctrl+Z then Enter)
// - On non-numeric input, the program reports an error and terminates.

// TESTS:
// - INPUT: 69.420 42.69 EOF
//			OUTCOME: i is assined the value of 69 and 42 (loss of precision, truncates fractional component)
// - INPUT: 420 6900 EOF
//			OUTCOME: The value of c is machine dependant and not portable (loss of information, data mutation)

#include "PPP.h"

int main()
{

	double tt_double{ 0 };
	
	std::cout << "Enter numbers (space/newline separated).\n"
		<< "End with EOF (Windows: Ctrl+Z then Enter).\n"
		<< "=> ";

	while (std::cin >> tt_double)
	{
		const int tt_int = static_cast<int>(tt_double);
		const char tt_char = static_cast<char>(tt_int);
		const int tt_char_code = static_cast<unsigned char>(tt_char);

		std::cout << "\n- tt_double: " << tt_double
			<< "\n- tt_int: " << tt_int
			<< "\n- tt_char_code: " << tt_char_code
			<< "\n- tt_char( " << tt_char << " )\n";
	}

	if (std::cin.eof())
		return 0; // intended termination

	// User entered a non-numeric input - terminate with 420
	std::cerr << "INPUT ERROR: Expected numeric value or EOF\n";
	return 1;
}