//PPP3/ch03_s3_4_1_selection/ch03_s3_4_1_selection.cpp

//PURPOSE:
// - Demonstrate the process of input selection using if statements.

//PRECONDITIONS:
// - Inputs a valid double value followed by one of several valid operator characters
//	followed by a valid double character
// - Invalid inputs display an error and terminate the program.

//TESTS: 
// - Input: 69.420 + 420.69 [Enter]
//		Output: (69.42 + 420.69) = 490.11
// - Input: 69 / 0 [Enter]
//		Output: Error: Illegal divide by zero operation!
// - Input: 420 ^ 69 [Enter]
//		Output: Error: Unknown operator
#include "PPP.h"

int main()
{
	double first_value{ 0 };
	char selected_operator{ 0 };
	double second_value{ 0 };

	std::cout << "Usage: [first value] [+, -, *, /] [second value]\nInput: ";
	if (!(std::cin >> first_value >> selected_operator >> second_value))
	{
		std::cerr << "Error: Invalid input!\n\n";

		return 1;
	}

	if (selected_operator == '+')
	{
		std::cout << "(" << first_value << " + " << second_value << ") = "
			<< first_value + second_value << "\n\n";
	}
	else if (selected_operator == '-')
	{
		std::cout << "(" << first_value << " - " << second_value << ") = "
			<< first_value - second_value << "\n\n";
	}
	else if (selected_operator == '*')
	{
		std::cout << "(" << first_value << " * " << second_value << ") = "
			<< first_value * second_value << "\n\n";
	}
	else if (selected_operator == '/')
	{
		if (second_value == 0)
		{
			std::cerr << "Error: Illegal divide by zero operation!\n\n";

			return 1;
		}
		else
		{
			std::cout << "(" << first_value << " / " << second_value << ") = "
				<< first_value / second_value << "\n\n";
		}
	}
	else
	{
		std::cerr << "Error: Unknown operator\n\n";
	}

	return 0;
}