//PPP3/ch03_4_1_selection_classification/ch03_s3_4_1_selection_classification.cpp

//PURPOSE: 
// - Demonstrate selection based on user input (zero, positive, negative)

//PRECONDITIONS: 
// - Input is a valid double type value.
// - Invalid input displays an error and terminates the program.

//TESTS: 
// - Input: 420.69 [Enter]
//		Output: 420.69 is positive.
// - Input: -420.69 [Enter]
//		Output: -420.69 is negative.
// - Input: 0 [Enter]
//		Output:0 is zero.

#include "PPP.h"

int main()
{
	double user_input{ 0 };

	std::cout << "Usage: Enter valid floating-point number.\nInput: ";
	if (!(std::cin >> user_input))
	{
		std::cerr << "Error: Invalid input!\n\n";

		return 1;
	}

	if (user_input == 0)
	{
		std::cout << user_input << " is zero.\n\n";
	}
	else if (user_input > 0)
	{
		std::cout << user_input << " is positive.\n\n";
	}
	else
	{
		std::cout << user_input << " is negative.\n\n";
	}

	return 0;
}