#include<iostream>
#include<time.h>

#include "binTree.h"

using namespace std;

int main() {

	srand(time(nullptr));

	BinTree<int> tree;

	int size = 20;
	int min = 0;
	int max = 99;

	for (int i = 0; i < size; i++) {
		tree.add((rand() % (max - min)) + min);
	}

	tree.print_tree_level();

	cout << endl << endl;
	cout << "Num " << tree.calc_level(4);

	system("pause");

	return 0;
}