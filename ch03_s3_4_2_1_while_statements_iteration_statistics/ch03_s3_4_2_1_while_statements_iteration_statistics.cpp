//PPP3/ch03_s3_4_2_1_while_statements_iteration_statistics/ch03_s3_4_2_1_while_statements_iteration_statistics.cpp

//PURPOSE:
// - Demonstrate iteration using a while statement.

//PRECONDITIONS:
// - Input a sequence of (space\endline separated) valid double type values followed by EOF.
// - Any non valid double type prints an error and terminates the program.

//TESTS:
// - Input: 2 4 7 1 [EOF]
//		Output: 
//				Number of values read: 4
//				Sum: 14
//				Smallest : 1
//				Largest : 7
// - Input: 420.69 -69 42.69 69.42 [EOF]
//		Output: 
//				Number of values read: 4
//				Sum: 463.8
//				Smallest : -69
//				Largest : 420.69

#include "PPP.h"

int main()
{
	double user_input{ 0 };
	int input_count{ 0 };
	double sum{ 0 };
	double smallest_input{ 0 };
	double largest_input{ 0 };

	std::cout << "Usage: Input a series of numbers (space/newline separated).\nEnd with EOF.\n=> ";

	while (std::cin >> user_input)
	{

		if (input_count == 0)
		{
			smallest_input = largest_input = user_input;
		}
		else
		{
			if (user_input < smallest_input)
			{
				smallest_input = user_input;
			}

			if (user_input > largest_input)
			{
				largest_input = user_input;
			}
		}

		input_count++;
		sum += user_input;
	}

	if (input_count == 0)
	{
		std::cerr << "Error: No valid input was recieved!\n\n";

		return 1;
	}

	if (!(std::cin.eof()))
	{
		std::cerr << "Error: Invalid input!\n\n";

		return 1;
	}

	std::cout <<
		"\nNumber of values read: " << input_count << '\n'
		<< "Sum: " << sum << '\n'
		<< "Smallest:  " << smallest_input << '\n'
		<< "Largest: " << largest_input << "\n\n";

	return 0;
}