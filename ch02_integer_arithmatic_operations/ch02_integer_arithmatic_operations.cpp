// /PPP3/ch02_integer_arithmatic_operations/ch02_integer_arithmatic_operations.cpp
// 
// Purpose: Output various results of integer arithmatic using many of the available arithmatic operators, also trying various modulo results.
// Preconditions:
//			- n is given as a valid non-zero int value.
// Tests: ('_' represents a 'space' character)
//			- Input: "42\n" -> Output:
//										- n                        == 42
//										- n + 1                    == 43
//										- three times n            == 126
//										- twice n                  == 84
//										- n squared                == 1764
//										- half of n                == 21
//										- square root of n         == 6.48074
//										- n modulo 1               == 0
//										- n % 2                    == 0
//										- n mod 3                  == 0
//										- n mod 4                  == 2
//										- n mod 5                  == 2
//			- Input: "42.42\n" -> Output:
//										- n                        == 42
//										- n + 1                    == 43
//										- three times n            == 126
//										- twice n                  == 84
//										- n squared                == 1764
//										- half of n                == 21
//										- square root of n         == 6.48074
//										- n modulo 1               == 0
//										- n % 2                    == 0
//										- n mod 3                  == 0
//										- n mod 4                  == 2
//										- n mod 5                  == 2
//			- Input: "-42\n" -> Output:
//										- n                        == -42
//										- n + 1                    == -41
//										- three times n            == -126
//										- twice n                  == -84
//										- n squared                == 1764
//										- half of n                == -21
//										- square root of n         == -nan(ind)
//										- n modulo 1               == 0
//										- n % 2                    == 0
//										- n mod 3                  == 0
//										- n mod 4                  == -2
//										- n mod 5                  == -2
//			- Input: "-42.42\n" -> Output:
//										- n                        == -42
//										- n + 1                    == -41
//										- three times n            == -126
//										- twice n                  == -84
//										- n squared                == 1764
//										- half of n                == -21
//										- square root of n         == -nan(ind)
//										- n modulo 1               == 0
//										- n % 2                    == 0
//										- n mod 3                  == 0
//										- n mod 4                  == -2
//										- n mod 5                  == -2
//			- Input: "0\n" -> Output: Error: Zero is not a valid value! (neccessary, to avoid potential divide by zero crashes)


#include "./HEADERS/PPP.h"

int main()
try {
	std::cout << "Please enter an integer value: ";
	int n = 0;
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
		<< "\nn modulo 1\t\t "			<< "== " << (n % 1)
		<< "\nn % 2\t\t\t "				<< "== " << (n % 2)
		<< "\nn mod 3\t\t\t "			<< "== " << (n % 3)
		<< "\nn mod 4\t\t\t "			<< "== " << (n % 4)
		<< "\nn mod 5\t\t\t "			<< "== " << (n % 5)
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