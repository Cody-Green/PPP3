// //ch02_Section_2_3_name_and_age_to_month.cpp
// 
// **IMPORTANT** Uncomment file to use -> (ctrl + a) -> (ctrl + k) (ctrl + u)
// **IMPORTANT** Re-comment after use -> (ctrl + a) -> (ctrl + k) (ctrl + c)
// 
// Purpose: Output the age in months of a given input of a given name (first name), surname (last name) and an age.
// Preconditions:
//			- given_name, surname are single tokens (they do not include spaces) and are not the string "0"
//			- age is a valid integer number greater than or equal to 0
// Tests: ('_' represents a 'space' character)
//			- Input: "Cody '_' Green '_' 41 \n" -> Output: Hello, Cody Green is 492 months old!
//			- Input: "'_' '_' 42 \n ctrl+z (^Z)" -> Output: ERROR: Last name was empty, you do have a last name do you not?
//			- Input: "Cody '_' Green '_' -41 \n" -> Output: ERROR: No one is zero years old or less!

import std;

int main()
try {
	std::cout << "Please enter your full name and age:\n";
	std::string given_name{ " " }; // initialize to "0" 
	std::string surname { " " }; // initialize to "0"
	double age = 0; // initialize to zero
	std::cin >> given_name >> surname >> age;		// read a string followed by an integer
	
	if (given_name == " ") 
	{
		throw std::runtime_error("First name was empty, you do have a first name do you not?");
	}

	if (surname == " ")
	{
		throw std::runtime_error("Last name was empty, you do have a last name do you not?");
	}

	if (age <= 0)
	{
		throw std::runtime_error("No one is zero years old or less!");
	}

	std::cout << "Hello, " << given_name << " " << surname << " is " << age * 12 << " months old!\n";
}

catch (std::exception& e)
{
	std::cerr << "ERROR: " << e.what() << '\n';
	return 1;
}

catch (...)
{
	std::cerr << "ERROR: Unknown Error!\n";
	return 2;
}