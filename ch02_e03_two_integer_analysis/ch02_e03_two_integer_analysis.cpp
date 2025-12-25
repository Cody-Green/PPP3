// PURPOSE: Read two integers and report ordering and basic arithmetic results.

// PRECONDITIONS: Input valid integer numbers for val1 and val2.
// TESTS:
// - Input: 3 7 -> identifies smaller/larger, prints sum/diff/product, ratio 3/7
// - Input: 5 0 -> prints sum/diff/product, reports division by zero

#include "PPP.h"

int main()
{
	int val1{ 0 };
	int val2{ 0 };

	std::cout << "Please enter the first integer value:\n"
		<< ":=> ";

	if (!(std::cin >> val1))
	{
		std::cout << "\n\nError: Unable to process input!\nTerminating program!\n\n";
		return 1;
	}

	std::cout << "Please enter the second integer value:\n"
		<< ":=> ";

	if (!(std::cin >> val2))
	{
		std::cout << "\n\nError: Unable to process input!\nTerminating program!\n\n";
		return 1;
	}

	if (val1 == val2)
	{
		std::cout << val1 << " and " << val2 << " are equal!\n";
	}
	else if (val1 < val2)
	{
		std::cout << val1 << " is the smaller of the two!\n";
		std::cout << val2 << " is the larger of the two!\n";
	}
	else
	{
		std::cout << val1 << " is the larger of the two!\n";
		std::cout << val2 << " is the smaller of the two!\n";
	}

	std::cout << "The sum of " << val1 << " and " << val2 << " is: "
		<< "( " << val1 << " + " << val2 << " ) = " << (val1 + val2) << '\n'
		<< "The difference between " << val1 << " and " << val2 << " is: "
		<< "( " << val1 << " - " << val2 << " ) = " << (val1 - val2) << '\n'
		<< "The product of " << val1 << " and " << val2 << " is: "
		<< "( " << val1 << " * " << val2 << " ) = " << (val1 * val2) << '\n';

	if (val2 == 0)
	{
		std::cout << "unable to divide by zero, illegal operation!\n\n";
	}
	else
	{
		std::cout << "The ratio of " << val1 << " and " << val2 << " is: "
			<< "( " << val1 << " / " << val2 << " ) = " << (val1 / val2) << '\n';
	}
}