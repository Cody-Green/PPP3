// /Chapter_02/src/ch02_Section_2_5_1_detect_repeated_words.cpp
// 
// **IMPORTANT** Uncomment file to use -> (ctrl + a) -> (ctrl + k) (ctrl + u)
// **IMPORTANT** Re-comment after use -> (ctrl + a) -> (ctrl + k) (ctrl + c)
// 
// Purpose: Outputs detected repeat words.
// Preconditions: Input is valid character stream input.
// Tests:
//			- Input:"She she laughed "he he he!" because what he did did not look very very good good\n(ctrl + z)" -> Output:
//																															- Repeated word: did
//																															- Repeated word: very
//																															- Repeated word: good

import std;

int main()
{
	std::string current = "";
	std::string previous = "";

	while (std::cin >> current)
	{

		if (!previous.empty() && previous == current)
		{
			std::cout << "Repeated word: " << current << '\n';
		}

		previous = current;
	}
}