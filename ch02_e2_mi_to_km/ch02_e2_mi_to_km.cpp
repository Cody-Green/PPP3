// /PPP3/ch02_e02_mi_to_km/ch02_e02_mi_to_km.cpp

// PURPOSE: 
// - Calculate and display the conversion from Miles to Kilometers.
// - Demonstrates the use of arithmetic operations and console output
//	 using the input and output streams.
// - mi => km = mi * 1.609.

// PRECONDITIONS:
// - Input of valid double type numeric values
// - On non-numeric input, the program reports an error and terminates.

// TESTS:
// - INPUT: 1 Enter
//			OUTCOME: 1 mile = 1.609 kilometers
// - INPUT: 5240 Enter
//			OUTCOME: 5240 mile = 8431.16 kilometers

#include "PPP.h"

int main()
{
	double mi{ 0 };
	const double factor{ 1.609 };

	std::cout << "This program will convert Miles to Kilometers\n"
			<< "Please enter a distance in Miles:\n"
			<< ":=> ";

	if (!(std::cin >> mi))
	{
		std::cerr << "Error: Unable to process input!";
		return 1;
	}

	std::cout << mi << " mile = " << (mi * factor) << " kilometers\n\n";
	
	return 0;
}