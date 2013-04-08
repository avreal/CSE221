/*Arnaldo A Villarreal
  CSCE 221-510
  01-22-13
*/

#include "marble.h"
#include <cstdlib> //This is needed for rand function

//Constructors
Marble::Marble(){
    color = Marble::Color(random_color());
    size = Marble::Size(random_size());
}

Marble::Marble(Color c){
    set_color(c);
    size = Marble::Size(random_size());
}

Marble::Marble(Size s){
    size = s;
    color = Marble::Color(random_color());
}

Marble::Marble(Color c, Size s){
    color = c;
    size = s;
}

//Functions for random color and size
int Marble::random_color()
{
    return rand() % 4;
}

int Marble::random_size()
{
    return rand() % 3;
}

//Getters
Marble::Color Marble::get_color() const
{

    return color;
}

Marble::Size Marble::get_size() const
{

    return size;
}

//Setters
void Marble::set_color(Color c)
{
    this->color = c;
}

void Marble::set_size(Size s)
{
    this->size = s;
}

//input stream operator overload
istream& operator>>(istream& is, Marble& m)
{
char color, size;

is >> color;
if (!is) return is;

switch(color)
{

    case 'r':
    m.set_color(Marble::red);
    break;

    case 'b':
    m.set_color(Marble::blue);
    break;

    case 'y':
    m.set_color(Marble::yellow);
    break;

    case 'g':
    m.set_color(Marble::green);
    break;

    default:
    {
    throw Marble::Bad_input();
    break;
    }
}

is >> size;
if (!is) return is;

switch(size)
{

    case 's':
    case '1':
    m.set_size(Marble::small);
    break;

    case 'm':
    case '2':
    m.set_size(Marble::medium);
    break;

    case 'l':
    case '3':
    m.set_size(Marble::large);
    break;

    default:
    {
    throw Marble::Bad_input();
    break;
    }
}

return is;
}

//output stream overloaded operator
ostream& operator<<(ostream& os, const Marble& m)
{
    int sz = m.get_size();
    string szString;
    switch (sz)
    {
        case 0:
        {
            szString = "small";
            break;
        }

        case 1:
        {
            szString = "medium";
            break;
        }

        case 2:
        {
            szString = "large";
            break;
        }

        default:
        {
            throw("Invalid Size\n");
        }
    }	

    int col = m.get_color();
    string cString;
    switch (col)
    {
        case 0:
        {
            cString = "red";
            break;
        }
        case 1:
        {
            cString = "blue";
            break;
        }
        case 2:
        {
            cString = "yellow";
            break;
        }
        case 3:
        {
            cString = "green";
            break;
        }
        default:
        {
            throw("Unknown color\n");
        }
    }

    return os << "(" << cString <<
        "," << szString << ')';

}

//overloaded equality test operator
bool operator==(const Marble& m1, const Marble& m2)
{
    return (m1.get_size() == m2.get_size() && m1.get_color() == m2.get_color());
}
