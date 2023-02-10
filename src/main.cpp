#include <iostream>
#include "../include/FusionTree.hpp"
using namespace std;
int main ()
{
	FusionTree tree;

	tree.insert(1);
	tree.insert(5);
	tree.insert(5);
	tree.insert(15);
	tree.insert(16);
	tree.insert(20);
	tree.insert(25);
	tree.insert(4);
	tree.insert(6);
	tree.insert(9);

	tree.init ();
	cout << "6 -> " << tree.successor (6) << "\n";
	cout << tree.predecessor(6) << " <- 6 \n";
	cout << tree.predecessor(5) << " <- 5 \n";
	cout << "5 -> " << tree.successor(5) << "\n";


	return 0;
} 
