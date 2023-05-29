#include <string>

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

class Binary_tree
{

public:

	//=====TREE=====
	std::string value;
	Binary_tree* left_child;
	Binary_tree* right_child;

	//-----DEFAULT FUNCTIONS-----
	void print(Binary_tree* Node);
	void add_node(Binary_tree* Node, std::string new_value);
	int find_distance(Binary_tree* Node, std::string name, int level);
	int max_depth(Binary_tree* Node);

	//-----ORDERS------
	void direct_order(Binary_tree* Node);
	void symmetric_order(Binary_tree* Node);
};

#endif // !BINARY_TREE_H