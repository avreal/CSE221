/*Arnaldo A Villarreal
  CSCE 221-510
  01-22-13
*/

#include <cstdlib>
#include "marble.h"
#include <time.h>

int main() 
{

    srand(time(0));

    //Initialize 4 marbles
	Marble m1;
    Marble m2(Marble::red);
    Marble m3(Marble::small);
    Marble m4(Marble::blue, Marble::large);
    char quit;

    //Generate marbles with the constructors defines in marble.h
    std::cout << "The following 4 marbles are made with the constuctors in marble.h\n";
    std::cout << "Color and size random: " << m1 << '\n';
    std::cout << "Given color and size random: " << m2 << '\n';
    std::cout << "Random color and given size: " << m3 << '\n';
    std::cout << "Given color and given size: " << m4 << "\n\n";

    //Prompt user to make 2 marbles, will then ask the user if they want to continue or quit.
    while(true){
        try{
            std::cout << "Enter a marble using r,b,y,g for color (followed by ENTER) and s,m,l for size (also followed by ENTER)" << "\n";
            Marble m5;
            cin >> m5;

            std:: cout << "This marble is " << m5 << '\n';

            std::cout << "Now enter another marble" << '\n';
            Marble m6;
            cin >> m6;

            std:: cout << "This marble is " << m6 << "\n\n";

            if (m5==m6)
                std::cout << "Equal" << "\n\n";
            else 
                std::cout << "Not equal" << "\n\n";

            std::cout << "Enter q to quit or c to compare more marbles" << '\n';
            cin >> quit;

            if (quit == 'q')
            {       std::cout << "Exiting" << '\n';
                break;
            }

            else if (quit == 'c')
                continue; 
            else
                throw Marble::Bad_input();
            }

        //clear bufer and go to beginning of loop
        catch(class Marble::Bad_input){
        cin.clear();
        cin.ignore(100,'\n');
        std::cout << "Bad input, try a new set of marbles~" << '\n';
        continue;
        }
       
    }
}
