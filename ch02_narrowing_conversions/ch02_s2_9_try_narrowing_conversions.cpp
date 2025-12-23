// /PPP3/ch02_narrowing_conversions/ch02_narrowing_conversions.cpp
// 
// Purpose: Continuously retrieves valid double type input from the character input stream, when the user inputs a new line the program displays the double value assigned to a double, int, char type variable respectively through the character output stream.
// Preconditions: input d is expected to be any valid positive or negative double type value.
// Tests:
//			- Input:2 3 -> \n -> (ctrl + z) -> \n" -> Output:
//																	- d == 2 i == 2 c ==  char(  )
//																	- d == 3 i == 3 c ==  char(  )
//			- Input:128 3000 -> \n -> (ctrl + z) -> \n" -> Output:
//																		- d == 128  i == 128  c == Ç char( Ç )
//																		- d == 3000 i == 3000 c == ╕ char( ╕ )
//			- Input:-128 -3 -> \n -> (ctrl + z) -> \n" -> Output:
//																	- d == -128 i == -128 c == Ç char( Ç )
//																	- d == -3   i == -3   c == ² char( ² )
//			- Input:56 89 128 -> \n -> (ctrl + z) -> \n" -> Output:
//																	d == 56  i == 56  c == 8 char( 8 )
//																	d == 89  i == 89  c == Y char( Y )
//																	d == 128 i == 128 c == Ç char( Ç )
//			- Input:56.89 89.128 -> \n -> (ctrl + z) -> \n" -> Output:
//																	d == 56.89  i == 56 c == 8 char( 8 )
//																	d == 89.128 i == 89 c == Y char( Y )


#include ".\HEADERS\PPP.h"

int main()
{
	double d = 0;
	while (std::cin >> d)
	{
		int i = d;
		char c = i;
		std::cout << "d == " << d
			<< " i == " << i
			<< " c == " << c
			<< " char( " << c << " )\n";
	}
}