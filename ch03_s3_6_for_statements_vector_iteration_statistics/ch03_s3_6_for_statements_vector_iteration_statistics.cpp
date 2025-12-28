//PPP3/ch03_s3_6_for_statements_vector_iteration_statistics/ch03_s3_4_2_1_for_statements_vector_iteration_statistics.cpp

//PURPOSE:
// - Demonstrate iteration using a vector.

//PRECONDITIONS:
// - Input a sequence of (space\endline separated) valid double type values followed by
//	non-numeric input or EOF.
// - Any non valid double type terminates the program.

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
//				Sum: 463.80
//				Smallest : -69
//				Largest : 420.69

#include <iostream>
#include <vector>


int main()
{
	std::cout << "Usage: Input a series of numbers (space/newline separated).\n"
		<< "End with non-numeric input or EOF.\n = > ";
	
	std::vector<double> user_inputs;
	for(double user_input; std::cin >> user_input;)
	{
		user_inputs.push_back(user_input);
	}

	if (user_inputs.size() == 0)
	{
		std::cerr << "Error: No valid input was received!\n\n";

		return 1;
	}

	double sum{ 0 };
	double smallest_value = user_inputs[0];
	double largest_value = user_inputs[0];

	for (double value : user_inputs)
	{
		sum += value;
		if (value < smallest_value)
		{
			smallest_value = value;
		}
		if (value > largest_value)
		{
			largest_value = value;
		}

	}

	std::cout <<
		"\nNumber of values read: " << user_inputs.size() << '\n'
		<< "Sum: " << sum << '\n'
		<< "Smallest:  " << smallest_value << '\n'
		<< "Largest: " << largest_value << "\n\n";

	return 0;
}