// /Chapter_02/src/ch02_floating_point_arithmatic_operations.cpp
// 
// **IMPORTANT** Uncomment file to use -> (ctrl + a) -> (ctrl + k) (ctrl + u)
// **IMPORTANT** Re-comment after use -> (ctrl + a) -> (ctrl + k) (ctrl + c)
// 
// Purpose: Output various results of floating point arithmatic using many of the available arithmatic operators.
// Preconditions:
//			- n is given as a valid non-zero double value.
// Tests: ('_' represents a 'space' character)
//			- Input: "42\n" -> Output:
//										- n                        == 42
//										- n + 1                    == 43
//										- three times n            == 126
//										- twice n                  == 84
//										- n squared                == 1764
//										- half of n                == 21
//										- square root of n         == 6.48074
//			- Input: "42.42\n" -> Output:
//										- n                        == 42.42
//										- n + 1                    == 43.42
//										- three times n            == 127.26
//										- twice n                  == 84.84
//										- n squared                == 1799.46
//										- half of n                == 21.21
//										- square root of n         == 6.51306
//			- Input: "-42\n" -> Output:
//										- n                        == -42
//										- n + 1                    == -41
//										- three times n            == -126
//										- twice n                  == -84
//										- n squared                == 1764
//										- half of n                == -21
//										- square root of n         == -nan(ind)
//			- Input: "-42.42\n" -> Output:
//										- n                        == -42.42
//										- n + 1                    == -41.42
//										- three times n            == -127.26
//										- twice n                  == -84.84
//										- n squared                == 1799.46
//										- half of n                == -21.21
//										- square root of n         == -nan(ind)
//			- Input: "0\n" -> Output: Error: Zero is not a valid value! (neccessary, to avoid potential divide by zero crashes)


#include "./HEADERS/PPP.h"

int main()
try {
	std::cout << "Please enter a floating-point value: ";
	double n = 0;
	std::cin >> n;
	if (n == 0)
	{
		PPP::error("Zero is not a valid value! (neccessary, to avoid potential divide by zero crashes)");
	}
	std::cout
		<< "n\t\t\t "					<< "== " << n
		<< "\nn + 1\t\t\t "				<< "== " << (n + 1)
		<< "\nthree times n\t\t "		<< "== " << (3 * n)
		<< "\ntwice n\t\t\t "			<< "== " << (n + n)
		<< "\nn squared\t\t "			<< "== " << (n * n)
		<< "\nhalf of n\t\t "			<< "== " << (n / 2)
		<< "\nsquare root of n\t "		<< "== " << std::sqrt(n)
		<< '\n';
}

catch (std::exception& e)
{
	std::cerr << "Error: " << e.what() << '\n';
}

catch (...)
{
	std::cerr << "Error: Unknown Error!";
}