//PPP3/ch03_s3_4_2_1_while_statements_iteration_statistics/ch03_s3_4_2_1_while_statements_iteration_statistics.cpp

//PURPOSE:
// - Demonstrate iteration using a while statement.

//PRECONDITIONS:
// - Input valid double type values [Enter] [EOF].
// - Any non valid double type terminates the program.

//TESTS:
// - Input: 2 4 7 1 [Enter] [EOF]
//		Output: 
//				Number of values read: 1
//				Sum: 2
//				Smallest : 2
//				Largest : 2
//				
//				Number of values read : 2
//				Sum : 6
//				Smallest : 2
//				Largest : 4
//				
//				Number of values read : 3
//				Sum : 13
//				Smallest : 2
//				Largest : 7
//				
//				Number of values read : 4
//				Sum : 14
//				Smallest : 1
//				Largest : 7

#include "PPP.h"

int main()
{
	double user_input{ 0 };
	int input_count{ 0 };
	double sum{ 0 };
	double smallest_input{ 0 };
	double largest_input{ 0 };

	std::cout << "Any non-number terminates the program.\n" 
		<< "Usage: Input a series of floating-point numbers, press [Enter] to continue.\n"
		<< "INPUT: ";

	while (std::cin >> user_input)
	{

		if (input_count == 0)
		{
			smallest_input = user_input;
			largest_input = user_input;
		}

		input_count++;
		sum += user_input;

		if (user_input >= largest_input)
		{
			largest_input = user_input;
		}
		
		if (user_input <= smallest_input)
		{
			smallest_input = user_input;
		}
		std::cout <<
			"Number of values read: " << input_count << '\n'
			<< "Sum: " << sum << '\n'
			<< "Smallest:  " << smallest_input << '\n'
			<< "Largest: " << largest_input << "\n\n";
	}

	return 0;
}