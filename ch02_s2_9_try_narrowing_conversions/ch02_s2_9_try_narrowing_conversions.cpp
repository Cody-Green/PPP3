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

// TESTS:
// - INPUT: 69.420 42.69 EOF
//			OUTCOME: i is assined the value of 69 and 42 (loss of precision, truncates fractional component)
// - INPUT: 420 6900 EOF
//			OUTCOME: The value of c is machine dependant and not portable (loss of information, data mutation)

#include ".\HEADERS\PPP.h"

int main()
{
	double d = 0;
	while (std::cin >> d)
	{
		int i = d;
		char c = i;
		std::cout << "d == " << d
			<< " i == " << i
			<< " c == " << c
			<< " char( " << c << " )\n";
	}
}