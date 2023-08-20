#include <iostream>
#include <Windows.h>
#include "BinaryTree.h"

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	BinaryTree tree;
	tree.insert(5);
	tree.insert(3);
	tree.insert(8);
	tree.insert(2);
	tree.insert(4);
	tree.insert(12);
	tree.insert(-1);

	TreeNode * node = tree.search(4);
	if (node != nullptr)
	{
		std::cout << "Елемент знайдено:" << node->data << "\n";
	}
	cout << "Inorder traversal: ";
	tree.inorder();
	cout << std::endl;
	return 0;

}