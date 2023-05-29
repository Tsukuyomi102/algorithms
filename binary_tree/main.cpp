#include <iostream>
#include <string>

#include "binary_tree.h"

Binary_tree* help_filling(std::string data)
{
	Binary_tree* object = new Binary_tree();
	object->value = data;
	object->left_child = NULL;
	object->right_child = NULL;

	return (object);
}

int main()
{
	Binary_tree Tree = Binary_tree();
	Binary_tree* Node = new Binary_tree();

	Node = help_filling("Egor");
	Node->left_child = help_filling("Olga");
	Node->right_child = help_filling("Alex");
	Node->left_child->left_child = help_filling("Zina");
	Node->left_child->right_child = help_filling("Evgeniy");
	Node->right_child->left_child = help_filling("Marina");
	Node->right_child->right_child = help_filling("Sergey");
	Node->left_child->left_child->left_child = help_filling("Motya");
	Node->left_child->left_child->right_child = help_filling("Sergey");
	Node->left_child->right_child->left_child = help_filling("Anna");
	Node->left_child->right_child->right_child = help_filling("Ivan");
	Node->right_child->left_child->left_child = help_filling("Zina");
	Node->right_child->left_child->right_child = help_filling("Vitaliy");

	int menu = 1;
	while (menu > 0)
	{
		std::cout << '\n' <<
			"1 - Add new element" << '\n' <<
			"2 - The direct order" << '\n' <<
			"3 - The symmetric order" << '\n' <<
			"4 - Find the depth from root to entered name" << '\n' <<
			"5 - Find the max depth of Tree" << '\n' <<
			"6 = Show the tree" << '\n' <<
			"0 - quit from programm" << '\n';
		std::cout << "Input the number of task: ";
		std::cin >> menu;

		if (menu == 1)
		{
			Tree.print(Node);
			std::cout << "Input the new element that you wanna add: ";
			std::string new_name;
			std::cin >> new_name;
			
			Tree.add_node(Node, new_name);
			Tree.print(Node);
		}

		if (menu == 2)
		{
			Tree.print(Node);
			std::cout << '\n';
			Tree.direct_order(Node);
		}

		if (menu == 3)
		{
			Tree.print(Node);
			std::cout << '\n';
			Tree.symmetric_order(Node);
		}

		if (menu == 4)
		{
			Tree.print(Node);
			std::cout << "Input the name, that depth you wanna find: ";
			std::string find_name;
			std::cin >> find_name;
			if (Tree.find_distance(Node, find_name, 0) == -1)
			{
				std::cout << "Entered name not exist in the Tree";
			}
			else
			{
				std::cout << "The depth of your name = " << Tree.find_distance(Node, find_name, 0) + 1;
			}
		}

		if (menu == 5)
		{
			Tree.print(Node);
			if (Tree.max_depth(Node) == -1)
			{
				std::cout << "The tree not exist";
			}
			else
			{
				std::cout << "The max depth of this tree = " << Tree.max_depth(Node);
			}
		}

		if (menu == 6)
		{
			Tree.print(Node);
		}
	}
}