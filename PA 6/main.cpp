/*********************************/
/*Arnaldo A Villarreal
/*CSCE 221 -510
/*Assignment 6, 04-30-2013
/**********************************/
#include "Graph.h"

int main()
{
	cout << "Howdy, please enter the name of a test file to read" << endl;
	string file;
	cin >> file;

	Graph G(file);

	int source = 0;
	int end = 0;

	cout << "Enter the source vertex" << endl;
	cin >> source;

	cout << "Enter the ending vertex" << endl;
	cin >> end;

	source = source-1;
	end = end -1;

	cout << "The input graph is: \n";
	G.PrintGraph();

	G.dijkstra(source, end);

	return 0;
}