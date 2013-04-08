/* Arnaldo A Villarreal
	CSCE 221-510
	HW 1 #3 code
	01-26-13
*/

#include <iostream>
#include "Stopwatch.h"

//Algorithms to be tested

int F_iterative_1(int n)
{
	int F0 = 0, F1 = 1, F;
	if (n == 0 || n == 1) return n;
	for (int i = 2; i <= n; i++) {
		F = F0 +F1;
		F0 = F1;
		F1 = F;
	}
	return F;
}

int Fib_recursive_2(int n)
{
		if (n == 0 || n == 1) return n;
		return Fib_recursive_2(n-1) + Fib_recursive_2(n-2);
}

//Function to test Algorithms for output and time
void Algorithm1(int n)
{
	Stopwatch a;
	a.reset();
	a.start();
	for (int i = 0; i < 10000000; i++) F_iterative_1(n);
	a.stop();

	std::cout << "Value for n = " << n << ": " << F_iterative_1(n) << '\n';
	std::cout << "Time in seconds: " << a.sec() / 10000000  << '\n';
}

void Algorithm2(int n)
{
	Stopwatch a;
	a.reset();
	a.start();
	for (int i = 0; i < 10000000; i++) Fib_recursive_2(n);
	a.stop();

	std::cout << "Value for n = " << n << ": " << Fib_recursive_2(n) << '\n';
	std::cout << "Time in seconds: " << a.sec() / 10000000<< '\n';
}

int main()
{
	//Algorithm 1 testing
	std::cout << "Testing algorithm 1 for n = 2,3,4,5,and 12" << '\n';
	Algorithm1(2);
	Algorithm1(3);
	Algorithm1(4);
	Algorithm1(5);
	Algorithm1(12);

	//Algorithm 2 testing
	std::cout << "Testing algorithm 2 for n = 2,3,4,5,and 12" << '\n';
	Algorithm2(2);
	Algorithm2(3);
	Algorithm2(4);
	Algorithm2(5);
	Algorithm2(12);

}
