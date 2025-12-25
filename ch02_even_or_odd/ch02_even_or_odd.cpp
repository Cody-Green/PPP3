// /PPP3/ch02_even_or_odd/ch02_even_or_odd.cpp
// 
// Purpose: Outputs whether or not an integer input is even or odd.
// Preconditions:
//			- n is given as a valid int value.
// Tests: ('_' represents a 'space' character)
//			- Input:"0\n" -> Output: 0 is neither even nor odd!
//			- Input:"42\n" -> Output: 42 is even!
//			- Input:"43\n" -> Output: 43 is odd!
//			- Input:"-0\n" -> Output: 0 is neither even nor odd!
//			- Input:"-42\n" -> Output: -42 is even!
//			- Input:"-43\n" -> Output: -43 is odd!
//			- Input:"69420\n" -> Output: 69420 is even!

#include "PPP.h"


int main()
try {
	int n = 0;
	std::cout << "Enter an integer and we will determine if it's even or odd: ";
	std::cin >> n;

	if (!n)
	{
		std::cout << n << " is neither even nor odd!\n\n";
		return 0;
	}

	//if n % 2 is 0 then we have an even number otherwise it's odd
	std::cout << n << " is " << (n % 2 == 0 ? "even!\n\n" : "odd!\n\n");
}

catch (std::exception& e)
{
	std::cerr << "Error: " << e.what() << '\n';
}

catch (...)
{
	std::cerr << "Error: Unknown Error!";
}