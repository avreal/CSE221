#include <iostream>
#include <string>
#include "BinaryTree.h"
#include <fstream>
#include <cstdlib>

void readPrintBinaryTree(std::string fileName)
{
	int key;
	int totalSearch = 0;
	int remove;
	int counter = 0;
	BinaryTree tree = BinaryTree();
	std::ifstream ist(fileName.c_str());
	std::ifstream pst(fileName.c_str());
	std::ifstream xst(fileName.c_str());

	while(ist>>key)
	{
		counter++;
	}

	if(counter>16)
	{
		std::cout << "More than 16 input elements, tree will be output to file" << '\n';
		std::cout << "Enter filename to print to" << '\n';
		std::string output;
		std::cin >> output;
		std::ofstream ost(output.c_str());

		while(pst>>key)
		{
			tree.insert(key);
			int search = tree.searchCost(tree.getRoot());
			ost << key << "[" << search << "] ";
			totalSearch += search;
		}
		ost << '\n' << "Average search cost: " << totalSearch/counter << '\n';
		ost << '\n' << "Number of Nodes: " << tree.size() << '\n';
		std::cout << '\n' << "Number of Nodes: " << tree.size() << '\n';


		std::cout << "Enter a value to delete from the tree." << '\n';
		std::cin >> remove;
		tree.remove(remove);
		std::cout << "Average search cost: " << tree.printavgSearchCost(tree.getRoot())/tree.height();
		std::cout << '\n' << "Number of Nodes: " << tree.size() << '\n';

	}

	if(counter<16){
		while(pst>>key)
		{
			tree.insert(key);
			int search = tree.searchCost(tree.getRoot());
			std::cout << key << " [" << search << "] ";
			totalSearch += search;
		}
		std::cout << '\n' << "Average search cost: " << totalSearch/counter << '\n';
		std::cout << '\n' << "Number of Nodes: " << tree.size() << '\n';

		std::cout << "Enter a value to delete from the tree." << '\n';
		std::cin >> remove;
		tree.remove(remove);
		std::cout << "New tree contains these elements" << '\n';
		tree.printBinaryTree(tree.getRoot());
		std::cout << "Average search cost: " << tree.printavgSearchCost(tree.getRoot())/tree.height(); 
		std::cout << '\n' << "Number of Nodes: " << tree.size() << '\n';
	}
}
int main()

{
	std::string file;

	std::cout << "Howdy, enter the name of the file you wish to read." << '\n';
	std::cin >> file;
	readPrintBinaryTree(file);

}