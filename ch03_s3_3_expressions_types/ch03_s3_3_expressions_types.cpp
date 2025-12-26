// /PPP3/ch03_s3_3_expressions_types/ch03_s3_3_expressions_types.cpp

// PURPOSE: 
// - Demonstrate the use of expressions using mixed arithmetic operators and common types.
// - Demonstrate the difference between integer division and floating-point division.

// PRECONDITIONS:
// - Input three values, int => double => int and assign them to the variables a, b, c, respectively.
// - Invalid inputs display an error and terminate the program.

// TESTS:
// - Input: 6 7.6 7 [Enter] (int double int)
//		Output:
//				-6 + 7.6 + 7 = 20.6
//				- 6 * 7.6 * 7 = 319.2
//				- 6 / 7 = 0 (integer division - strips fractional part - possible loss of precision)
//				- 6 / 7.6 = 0.789474 (floating - point division - maintains fractional part - no loss of precision)
// - Input: 9 8.9 8 [Enter] (int double int)
//		Output:
//				-9 + 8.9 + 8 = 25.9
//				- 9 * 8.9 * 8 = 640.8
//				- 9 / 8 = 1 (integer division - strips fractional part - possible loss of precision)
//				- 9 / 8.9 = 1.01124 (floating - point division - maintains fractional part - no loss of precision)

#include "PPP.h"

int main()
{
	int	 a{ 0 };
	int	 c{ 0 };
	double b{ 0 };
	
	std::cout << "Input: int, double, int: ";
	if (!(std::cin >> a >> b >> c))
	{
		std::cerr << "\n\nError: Unable to process input!\nTerminating program!\n\n";

		return 1;
	}

	std::cout << "- " << a << " + " << b << " + " << c << " = " << a + b + c << '\n';
	std::cout << "- " << a << " * " << b << " * " << c << " = " << a * b * c << '\n';
	
	if (b && c)
	{
		std::cout << "- " << a << " / " << c << " = " << a / c << " (integer division "
			<< " - strips fractional part"
			<< " - possible loss of precision)\n"
			<< "- " << a << " / " << b << " = " << a / b << " (floating-point division"
			<< " - maintains fractional part"
			<< " - no loss of precision)\n\n";
	}
	else
	{
		std::cerr << "\n\nError: Division by zero!";

		return 1;
	}
}