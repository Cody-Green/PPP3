// /PPP3/ch02_s2_9_try_narrowing_conversions/ch02_s2_9_try_narrowing_conversions.cpp

// PURPOSE: 
// - Demonstrate the potential dangers of information and/or precision loss
// inherent with implicit narrowing conversions.
// - Show the result of assigning a value stored in a larger memory allocated type
// to a variable of a smaller memory allocated type.
// - double => int (precision loss) and int => char (machine dependant, information loss).

// PRECONDITIONS:
// - Continuous User input of valid double type compatible numbers.
// - User terminates program by executing an EOF (Windows: [ctrl + z] => [ENTER] (CRLF))
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
	
	std::cout << "Enter a series of [SPACE] seperated numbers followed by [ENTER]\n"
			  << "Terminate the program with an EOF input (Windows: [ctrl + z] = >[ENTER]\n"
			  << "=>: ";

	while (std::cin >> tt_double)
	{
		const int tt_int = static_cast<int>(tt_double);
		const char tt_char = static_cast<char>(tt_int);
		const int tt_char_code = static_cast<unsigned char>(tt_char);

		std::cout << "\n- test_type_double: " << tt_double
			<< "\n- test_type_int: " << tt_int
			<< "\n- test_type_character_code: " << tt_char_code
			<< "\n- test_type_char( " << tt_char << " )\n";
	}

	if (std::cin.eof())
	{
		return 69; // intended termination
	}

	// User entered a non-numeric input - terminate with 420
	std::cerr << "INPUT ERROR: Expected numeric value or EOF\n";
	return 420;
}