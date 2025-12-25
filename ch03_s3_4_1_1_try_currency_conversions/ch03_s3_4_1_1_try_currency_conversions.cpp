// /PPP3/ch03_s3_4_1_1_try_currency_conversions/ch03_s3_4_1_1_try_currency_conversions.cpp

// PURPOSE: 
// - Demonstrate the use of branching logic using if statements.
// - Prompt the user to select one of a few selections and make
//	programatic decisions based on the selection.
// - Takes a user prompt of a currency type and converts selected currency
//	to Canadian dollar.

// PRECONDITIONS:
// - Input valid char type for first selection =>
//	Input valid double type for second selection.
// - On invalid input, the program reports an error and terminates.

// TESTS:
// - INPUT: 69420 [Enter] y [Enter]
//			OUTCOME: 69420 Yen => Canadian Dollars: $610.896
// - INPUT: 420.69 [Enter] k [Enter]
//			OUTCOME: 420.69 Kroner => Canadian Dollars: $58.8966
// - INPUT: 69.42 [Enter] p [Enter]
//			OUTCOME: 69.42 Brittish Pounds => Canadian Dollars is: $128.427

#include "PPP.h"

int main()
{
	constexpr double y_factor = 0.0088;
	constexpr double k_factor = 0.14;
	constexpr double p_factor = 1.85;
	char currency_type = ' ';
	double currency_value{ 0 };

	std::cout << "\nEnter the value to convert: ";
	if (!(std::cin >> currency_value))
	{
		std::cerr << "\n\nError: Unable to process input!\nTerminating program!\n\n";

		return 1;
	}

	std::cout << "Currency type (y)en, (k)roner or (p)ound: ";
	if (!(std::cin >> currency_type))
	{
		std::cerr << "\n\nError: Unable to process input!\nTerminating program!\n\n";

		return 1;
	}

	if (currency_type == 'y')
	{
		std::cout << currency_value << " Yen => Canadian Dollars: $" << currency_value * y_factor << '\n';
		return 0;
	}
	else if (currency_type == 'k')
	{
		std::cout << currency_value << " Kroner => Canadian Dollars: $" << currency_value * k_factor << '\n';
		return 0;
	}
	else if (currency_type == 'p')
	{
		std::cout << currency_value << " Brittish Pounds => Canadian Dollars is: $" << currency_value * p_factor << '\n';
		return 0;
	}
	else
	{
		std::cerr << "Error: Unknown currency!";
		return 1;
	}

	return 1;
}