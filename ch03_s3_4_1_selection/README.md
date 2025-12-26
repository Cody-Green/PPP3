# Drill_001

## So, here is your first drill:

1. Figure out how to compile and run a program on your machine. This may be a good time
	to get a bit of help from someone who has done that before.

2. If you use an IDE, set up an empty console C++ project called hello_world. Otherwise, if
	you plan to use the command line, get a command window, figure out how to use an edi-
	tor to type in your code, and see §0.3.1.

3. Type in hello_world.cpp, exactly as specified below, sav e it in your practice directory
	(folder), and include it in your hello_world project.

        import std;
        int main()		// C++ programs start by executing the function main
        {
            std::cout << "Hello, World!\n";		// output "Hello, World!"
        }

	What if you don’t hav e an up-to-date C++ implementation that supports module std?
	Then, use a less elegant and less efficient technique that has worked since the early days
	of C: #include a header file as is explained in §7.7.2:
        
        #include<iostream>
        int main()		// C++ programs start by executing the function main
        {
            std::cout << "Hello, World!\n";		// output "Hello, World!"
        }


4.	Compile and run the ‘‘Hello, World!’’ program. An IDE will have a compile-and-run
	button. Even something as simple as ‘‘Hello, World!’’ very rarely compiles and runs in a
	first attempt to use a new programming language or a new programming environment.
	Find the problem and fix it! This is a point where asking for help from a more experi-
	enced person is sensible, but be sure to understand what you are shown so that you can do
	it all by yourself before proceeding further.

5. By now, you have probably encountered some errors and had to correct them. Now is the
	time to get a bit better acquainted with your compiler’s error-detection and error-reporting
	facilities! Try the eight programs from §1.3 to see how your programming environment
	reacts. Think of at least five more errors you might have made typing in your program
	(e.g., leave the Caps Lock key on while typing a word, or type a comma instead of a
	semicolon) and try each to see what happens when you try to compile and run those ver-
	sions.

## Review Questions:
1. [Q]: What is the purpose of the "Hello, World!" program?
    * [A]: The purpose of the "Hello, World!" program is to display the text _Hello, World!_ to the monitor.

2. [Q]: Name the four parts of a function.
    * [A]:
         *  1: The return type
	    *  2: The function name
	    *  3: The parameters list
        *  4: The body of the function -> a list of statments executed in order.

3. [Q]: Name a function that must appear in every C++ program.
	* [A]: The function that must appear in every C++ program is the "main()" function.

4. [Q]: In the "Hello, World!" program, what is the purpose of the line _return 0;_?
	* [A]: The purpose of the line _return 0_ is to return the integer 0 to the operating system; 
		typically a return of 0 indicates that the program returned without error.

5. [Q] What is the purpse of the compiler?
	* [A] The purpose of the compiler is to convert _source code_ into _object code_ / _machine code_.

6. [Q] What is the purpose of the _import_ statement?
	* [A] The purpose of the _import_ statement is to provide access to a module.

7. [Q] What is the purpose of the _'#include'_ directive?
	* [A] The purpose of the _'#include'_ directive is to include the code of the specified file.

8. [Q] That does a _.cpp_ suffix at the end of a file name signify in C++?
	* [A] The _.cpp_ suffix at the end of a file name signifies a C++ source code file.

9. [Q] What does the linker do for your program?
	* [A] The linker links all of the object files and converts them into an executable file.

10. [Q] What is the difference between a _source file_ and an _object file_?
	* [A] The difference between a _source file_ and an _object file_ is that a source file contains the
		_source code_ in _plain text_ and the _object file_ contains the _source code_ converted to _machine code_

11. [Q] What is an _executable_?
	* [A] An executable is a file that can run a program; it is the result of compiling and linking source code.

12. [Q] What is an IDE and what does it do for you?
	* [A] An IDE is an Integrated Development Environment; it's purpose is to provide the neccessary components required to:
		write source code, compile, link and debug programs.

13. [Q] How do you get a compiled program to run?
	* [A] To get a compiled program to run you must run the compiled executable from the File System of the operating system.

14. [Q] What is a comment?
	* [A] A comment is a bit of human readable text behind either _//_ or enclosed between _/* */_; the purpose of comments is to
		doccument the purpose and function of your code so you or others can understand it's purpose and function at a later date.

15. [Q] What is the purpose of a _drill_?
	* [A] The purpose of a _drill_ is to practice the concepts that are being taught in the chapter.

16. [Q] If you understand everything in the textbook, why is it neccessary to practice?
	* [A] It is neccessary to practice, even when you understand everything in the textbook because the only way to learn
		is to actually put your understanding into practice.

## Terms:

|Term|Description|Example|
|-:|-|:-:|
|//|comment|`//This is a comment`|
|executable|file that can be run on the computer|executable.exe|
|main()|entry point of a C++ program|`int main() { }`|
|function|named collection of statements that can return a result and take parameters|_return-type_ _**name**_( _parameters_ ) { _function-body_ }|
|object code|compiled machine readable code representation of the source code|code.obj or code.o|
|C++|programming language||
|header file|code that can be imported into a source code file|header.h|
|output|what gets displayed on the monitor|_Hello, World!_|
|comment|human readable text in the source code that is ignored by the compiler;|`//this is a comment` 
|| used to doccument and describe the code for future reading|`/* This too, is a commment */`
|IDE|Integrated Development Environment is usually an application that facilitates writing, compiling, linking and debugging code in one place|Visual Studio 2022|
|program|||
|compiler|application that converts source code files into object files|MSVC|
|import|appends the imported code to the top of the source code||
|source code|human readable code written in a programming language|code.cpp|
|compile-time|the time during compilation||
|error|a problem with the syntax or semantics of a program||
|library|a collection of source code to use seperately from a main source file||
|statement||
|cout|the character output stream|`std::cout << "Hello, World!\n";`|
|linker||
|module||
|#include||
|std||
|command line||
|bug||
|debugging||

