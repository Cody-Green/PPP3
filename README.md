# Chapter_02

## How to build and run the programs
1. Uncomment the file you wish to run (ctrl + a) -> (ctrl + k) -> (ctrl + u) -> (Esc) then build the program (F6) if it successfully builds run the program in debug mode (F5) or without debug (ctrl + F5)
2. When finnished re-comment the file (ctrl + a) -> (ctrl + k) -> (ctrl + c) -> (Esc)

## List of programs (with links to the source files)
1. [ch02_Section_2_3_name_and_age_to_month.cpp](/Chapter_02/src/ch02_Section_2_3_name_and_age_to_month.cpp) :-> Outputs the age in months of a given input of a given name (first name), surname (last name) and an age
2. [ch02_floating_point_arithmatic_operations.cpp](/Chapter_02/src/ch02_floating_point_arithmatic_operations.cpp) :-> Outputs various results of floating point arithmatic using many of the available arithmatic operators.
3. [ch02_integer_arithmatic_operations.cpp](/Chapter_02/src/ch02_integer_arithmatic_operations.cpp) :-> Outputs various results of integer arithmatic using many of the available arithmatic operators, also trying various modulo results
4. [ch02_even_or_odd.cpp](/Chapter_02/src/ch02_even_or_odd.cpp) :-> Outputs whether or not an integer input is even or odd.
5. [ch02_Section_2_5_1_detect_repeated_words.cpp](/Chapter_02/src/ch02_Section_2_5_1_detect_repeated_words.cpp) :-> Outputs whether or not an integer input is even or odd.

## Review

1. [Q]: What is meant by the term _prompt_?
	* [A]: The term prompt means to _prompt_ the user for input.
		* [C]: The term _prompt_ means to output a string literal using the character output stream _cout_ requesting input from the user, this input can be stored into a variable using the character input stream _cin_.

2. [Q]: Which _operator_ do you use to read into a _variable_?
	* [A]: The _operator_ we use to read into a _variable_ is the >> used with cin stream.

3. [Q]: What notations can you use to _initialize_ an _object_?
	* [A]: The notations that can be used are as follows:
		* Type variable_name = value;
		* Type variable_name {value};
		* Type variable_name = {value};
		* Type variable_name (value);

4. [Q]: If you want the user to input an integer value into your program for a variable named number, what are two lines of code you could write to ask the user to do it and to imput the value into your program?
	* [A]: The two lines you could write to ask the user to enter an integer value into the program are as follows:
		* std::cout << "Please enter an integer number:\n";
		* std::cin >> number;

5. [Q]: What is `\n` called and what purpose does it serve?
	* [A]: The `\n` is called an escape character and this particular escape character injects a new line into to character stream or string literal on Windows this is a carriage return
		* [C]: The `\n` is the "Newline" or "Line Feed" character, where as the `\r` is the "Carriage Return" character. On the Windows OS the C++ library converts a `\n` character to a `\r\n` character also known as the CRLF (Carriage Return Line Feed).