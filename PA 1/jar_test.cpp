#include <cstdlib>
#include <time.h>
#include <fstream>
#include "vector_jar.h"
#include <string>

void writeJarToFile(VectorJar& J1, string fileName)
{
	//write the contents of a jar to a file
	ofstream ost(fileName.c_str());
	for(int i=0;i<J1.marble_number();i++)
	{
		if(J1.get_elem(i).get_color() == 0)
			ost<<"r ";
		else if(J1.get_elem(i).get_color() == 1)
			ost<<"b ";
		else if(J1.get_elem(i).get_color() == 2)
			ost<<"y ";
		else if(J1.get_elem(i).get_color() == 3)
			ost<<"g ";
		if(J1.get_elem(i).get_size() == 0)
			ost<<"s"<< '\n';
		else if(J1.get_elem(i).get_size() == 1)
			ost<<"m"<< '\n';
		else if(J1.get_elem(i).get_size() == 2)
			ost<<"l"<< '\n';
	}
}

void readJarFromFile(VectorJar& J2, string fileName)
{
	try{
		//read a jar from a file
		ifstream ist(fileName.c_str());
		string col;
		string sz;
		while(ist>>col>>sz)
		{
			int color;
			int size;

			if(col=="r") color = 0;
			else if(col=="b") color =1;
			else if(col=="y") color =2;
			else if(col=="g") color =3;

			if(sz == "s") size = 0;
			else if(sz == "m") size = 1;
			else if(sz == "l") size = 2;

			J2.add(Marble(Marble::Color (color),Marble::Size (size)));
		}
	}
	catch(...)
	{
		cout<< "Invalid input\n";
	}
}

int main()
{
	srand(time(0));  //get random seed
	int jarflag;
	char option;
	char color_rm;
	char size_rm;
	Marble::Color c;
	Marble::Size s;
	VectorJar jar1;
	VectorJar jar2;
	VectorJar jar3;
	string file;
	string file1 = "merge.out";
	string file2 = "intersection.out";
	string file3 = "completion.out"; //these strings are silly, but unix wouldnt let me compile without them
	bool done = false;

	std::cout << "Which kind of jar do you want to test? "
		"(1: vector jar; 2: list jar)" << '\n';
	std::cin >> jarflag;

	if(jarflag==1)
	{
		// jarflag = 1, do testing as instructed;
		// show a menu with choices to let the user to choose ways
		// to generate vector jar objects: VectorJar

		std::cout << "Howdy, please select an option from the menu by typing the corresponding letter.";
		std::cout << "\n\n(a) Enter the number of marbles to create a jar.\n"
			<< "(b) Print the jar to a file\n"
			<< "(c) Read a jar from a file (notation for colors: r, y, b, g; for sizes: s, m, l)\n"
			<< "(d) Remove a specific marble with color\n"
			<< "(e) Remove a specific marble with size\n"
			<< "(f) Test merge with 2 jars read from files, print the resulting jar to the file named \"merge.out\"\n"
			<< "(g) Test intersection with 2 jars read from ﬁles, print the resulting jar to the file named \"intersection.out\"\n"
			<< "(h) Test completion with 2 jars read from ﬁles, print the resulting jar to the file named \"completion.out\"\n"
			<< "(i) Exit the program\n"
			<< "Choice: ";

		while(!done){     //option i changes this to false which exits
			try{
				std::cin >> option;
				switch (option){
				case 'a': //creates jar and prints to file
					int marb;
					std::cout << "Enter the number of marbles (<=12) to be created in the jar: ";
					std::cin >> marb;
					if (marb == 0) {throw Jar::Empty_jar();}
					jar1 = VectorJar(marb);
					std::cout << "Jar has been generated\n";
					std::cout << "Printing contents of jar \n" << jar1;
					std::cout << "Enter the name of the file to print to: ";
					std::cin >> file;
					writeJarToFile(jar1,file);
					std::cout << "Jar written to file " << file << '\n';
					std::cout << "Enter another option from the menu or press i to quit" << '\n';
					break;

				case 'b': //creates a file out of the currently active jar
					if (jar1.marble_number() == 0) throw Jar::Empty_jar();
					std::cout << "Enter the name of the file to print to: ";
					std::cin >> file;
					writeJarToFile(jar1,file);
					std::cout << "Jar written to file " << file << '\n';
					std::cout << "Enter another option from the menu or press i to quit" << '\n';
					break;

				case 'c': //reads in a file and prints the contents
					std::cout << "Enter the name of the file to read ";
					std::cin >> file;
					readJarFromFile(jar2,file);
					cout<<jar2;
					std::cout << "Enter another option from the menu or press i to quit" << '\n';

					break;

				case 'd': //removes a marble with the specified color
					if (jar1.marble_number() == 0) throw Jar::Empty_jar();
					std::cout << "Enter the letter corresponding to the color of marble you wish to remove: ";
					std::cin >> color_rm;
					switch(color_rm)
					{
					case 'r':
						c = Marble::red;
						break;

					case 'b':
						c = Marble::blue;
						break;

					case 'y':
						c = Marble::yellow;
						break;

					case 'g':
						c = Marble::green;
						break;

					default:
						throw Marble::Bad_input();
						break;
					}

					jar1.remove(Marble(c));
					std::cout << "Here is the jar with a marble of color " << color_rm << " removed \n" << jar1;
					std::cout << "Enter another option from the menu or press i to quit" << '\n';

					break;

				case 'e':  //removes a marble with the specified size
					if (jar1.marble_number() == 0) throw Jar::Empty_jar();
					std::cout << "Enter the letter corresponding to the size of marble you wish to remove: ";
					std::cin >> size_rm;
					switch(size_rm)
					{
					case 's':
						s = Marble::small;
						break;

					case 'm':
						s = Marble::medium;
						break;

					case 'l':
						s = Marble::large;
						break;

					default:
						throw Marble::Bad_input();
						break;
					}

					jar1.remove(Marble(s));
					std::cout << "Here is the jar with a marble of size " << size_rm << " removed \n" << jar1;
					std::cout << "Enter another option from the menu or press i to quit" << '\n';
					break;

				case 'f': //merges the jars,similar to union of sets
					std::cout << "Merging jars now and writing to file merge.out" << '\n';
					jar1.clear();
					jar2.clear();
					jar3.clear();
					readJarFromFile(jar1,"jar1.in");
					readJarFromFile(jar2,"jar2.in");
					if (jar1.marble_number() == 0 || jar2.marble_number() == 0) throw Jar::Empty_jar();
					jar3.merge(jar1,jar2);
					writeJarToFile(jar3,file1);
					//std::cout << jar3 << '\n';
					std::cout << "Enter another option from the menu or press i to quit" << '\n';
					break;

				case 'g': //intersection of jars, similar to intersection of sets
					std::cout << "Intersecting jars now and writing to file intersection.out" << '\n';
					jar1.clear();
					jar2.clear();
					jar3.clear();
					readJarFromFile(jar1,"jar1.in");
					readJarFromFile(jar2,"jar2.in");
					if (jar1.marble_number() == 0 || jar2.marble_number() == 0) throw Jar::Empty_jar();
					jar3.intersection(jar1,jar2);
					writeJarToFile(jar3, file2);
					// std::cout << jar3 << '\n';
					std::cout << "Enter another option from the menu or press i to quit" << '\n';
					break;

				case 'h': //difference of jars, everything that is in the first that isn't in the second
					std::cout << "Computing difference of jars now and writing to file completion.out" << '\n';
					jar1.clear();
					jar2.clear();
					jar3.clear();
					readJarFromFile(jar1,"jar1.in");
					readJarFromFile(jar2,"jar2.in");
					if (jar1.marble_number() == 0 || jar2.marble_number() == 0) throw Jar::Empty_jar();
					jar3.difference(jar1,jar2);
					writeJarToFile(jar3,file3);
					//std::cout << jar3 << '\n';
					std::cout << "Enter another option from the menu or press i to quit" << '\n';
					break;
				case 'i':
					std::cout << "Exiting now!";
					done = true;
					break;

				default:
					std::cout << "Invalid entry, try again~" << '\n';
					break;
				}
			}
			catch(class Marble::Bad_input){
				cin.clear();
				cin.ignore(100,'\n');
				std::cout << "Bad input, Enter another option from the menu or press i to quit~" <<'\n';
				continue;
			}
			catch(class Jar::Empty_jar){
				cin.clear();
				cin.ignore(100,'\n');
				std::cout << "Error: Empty jar, Enter another option from the menu or press i to quit~" <<'\n';
				continue;
			}
		}
	}
	else if(jarflag==2)
	{
		// jarflag = 2, do testing as instructed;
		// show a menu with choices to let the user to choose
	}
	else
	{
		cout<<"wrong number entered"<<endl;
	}
	return 0;
}