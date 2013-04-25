#include <iostream>
#include <string>
#include "Graph.h"
using namespace std;

int main()
{       // you can use the following code to test your graph. 
        // you can also change your input file to do more testing
        // verify the results

		string str("random_sparse.txt");
		Graph graph(str);
		graph.PrintGraph();
		return 0;
}