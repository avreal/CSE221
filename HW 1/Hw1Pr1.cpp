/* Arnaldo A Villarreal
	CSCE 221-510
	HW 1 #1 code
	01-26-13
*/

#include <iostream>
#include <vector>
#include <math.h>

//Binary Search
void BinarySearch(std::vector<int>& A, int size, int x) 
{
	int mid;
	int low = 0;
	int high = size - 1;
	int counter = 0;
	
	while (low <= high) {

		mid = (low + high)/2;
	
		if (A[mid] < x){	
			low = mid + 1;
			std::cout << "Guessing " << A[mid]<< ". The number is higher, trying again!" << '\n';
			counter++;
		}

		else if (A[mid] > x) {
			high = mid - 1;
			std::cout << "Guessing " << A[mid] << ". The number is lower, trying again!" << '\n';
			counter++;
		}

		else {
		std::cout << "The number has been found! Your number is " << mid + 1 << ". It took "<< counter << " tries!\n";// found
		break;
		}

	}
}

int main()
{
	int k = 0; //2^k will be the range 1a2a3a4a
	int i = 1; //used to initialize the vector
	int n = 0; //the number to be guessed
	int low = 1; //lower bound for range


	std::cout << "Howdy, please enter a number k, which will be used to establish a range of values for the guessing game from 1 to 2^k." << '\n';
	std::cin >> k;

	//establish the high number with the user input k
	int high = pow(2,k);

	std::cout << "Now enter the number which the other player (computer) needs to guess" << '\n';
	std::cin >> n;

	//initialize a vector which acts as a container of consecutive integers which can be searched.
	std::vector<int> v(1);
	v[0] = 1;

	while (i < (pow(2,k))) {
			v.push_back(i+1);
			i++;
	}

	//Run the search and print results	
	BinarySearch(v,high,n);
}
