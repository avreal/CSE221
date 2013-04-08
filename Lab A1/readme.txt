--Files

Marble.h
	This is the header file for the lab. The class definition, function declarations,overloaded operator declaration, and constructor declarations are contanied within.
Marble.cpp
	This file contains all constructor, function, and overloaded operator definitions.
Marble_main.cpp
    This contains the main function which creates 4 marble objects from the constructors, and tests user input marbles for equality.

--Compiling and Running

Upon extracting the folder, use 'cd (directory)' to enter the folder containing the source files. Compile the program by typing the command 'g++ marble.cpp marble_main.cpp -o marble.out', this will generate the exectubale file called "marble.out". To run this file, type './marble.out'.

--Input Format

The format of input must be precise or else an exception will be thrown and you will have to retype the marbles. When inputting a marble, input the letter coresseponding to the color you want (r,b,y,g), then hit enter. Then enter the letter or number corresponding to the size of the marble. You may input one of (s,m,l) or one of (1,2,3). Hit enter again to complete the initialization of the marble.

Colors				Size

r = red				s or 1 = small
b = blue			m or 2 = medium
y = yellow			l or 3 = large
g = green

For example, to create a blue small marble you would input:

b
s

--Crashes & Exceptions
In all test cases done, the program will not crash due to bad input. However, when given improper input, the program will throw an exception that clears the buffer, then goes back to the initialization of the user input marbles.
