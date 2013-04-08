#include <iostream>
#include "vector_jar.h"
#include <cstdlib>

//Constructors
VectorJar::VectorJar(int len)
{
	while (len>12 || len < 0){
		std::cout << "Invalid number of marbles, must be <= 12, Enter another number : ";
		std::cin >> len;
	}
   for (int i = 0; marble_number() < len; i++){
   	Marble temp;
      if(!is_in_jar(temp)) 
      vec.push_back(temp);
	}
}

VectorJar::VectorJar()
{
	vec = std::vector<Marble>();
}

//assessors
const Marble& VectorJar::get_elem(int i) const
{
	return vec[i];
}



//functions
void VectorJar::add(const Marble& m)
{
	if(!is_in_jar(m)) vec.push_back(m);
}

void VectorJar::remove(const Marble& m)
{
	for (int i = 0; i < vec.size(); i++) //may have to do size()-1
		{
			if (m == vec[i])
				vec.erase(vec.begin()+i); //may have to put -1 here
		}
}

Marble VectorJar::remove_any()
{

	if (vec.empty()) throw Empty_jar();

	int n = rand()%vec.size();
   Marble m = (get_elem(n));
   vec.erase(vec.begin()+n);
   
   return m;

}

void VectorJar::clear()
{
   vec.clear();
}

bool VectorJar::is_empty() const
{
	return vec.empty();
}

bool VectorJar::is_in_jar(const Marble& m) const
{
	for (int i=0;i<vec.size();i++)
	{
		if(m==vec[i])
		{
			return true;
		}
	}
	return false;
}

int VectorJar::marble_number() const
{
	return vec.size();
}

int VectorJar::marble_nsize(Marble::Size s) const
{
	int same_size = 0;

	for(int i=0;i<vec.size(); i++)
	{
		if (s==vec[i].get_size())
		{
			same_size++;
		}
	}
	return same_size;
}

int VectorJar::marble_ncolor(Marble::Color c) const
{
	int same_color = 0;

	for(int i=0;i<vec.size(); i++)
	{
		if (c==vec[i].get_color())
		{
			same_color++;
		}
	}
	return same_color;
}

void VectorJar::merge(const Jar& jar1, const Jar& jar2)
{

	for (int i=0;i<jar1.marble_number();i++)
	{
		this->add(jar1.get_elem(i)); //watch out for this
	}
	
	for (int i=0;i<jar2.marble_number();i++)
	{
		this->add(jar2.get_elem(i));
	}

}

void VectorJar::intersection(const Jar& jar1, const Jar& jar2)
{

	for (int i=0;i<jar1.marble_number();i++)
	{
		if (jar1.is_in_jar(jar2.get_elem(i))) 
		this->add(jar2.get_elem(i)); //watch out for this
	}
	
}

void VectorJar::difference(const Jar& jar1, const Jar& jar2)
{
	for (int i=0;i<jar1.marble_number();i++)
	{
		if (!jar2.is_in_jar(jar1.get_elem(i))) 
		this->add(jar1.get_elem(i)); //watch out for this
	}
}

//overloaded << operator

ostream& operator<<(ostream& os, const VectorJar& jar)
{
        for(int i=0; i<jar.marble_number(); i++)
                os<<jar.get_elem(i) << '\n';
        os<< '\n';
}




// finish other constructions and functions by yourself 

