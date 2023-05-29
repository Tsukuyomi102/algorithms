#include"RBTree.h"
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	RBTree<int> tree;
	int menu = 1;
	while (menu > 0)
	{
		std::cout << '\n' << "Input the function, that you wanna check:" << '\n'
			<< "1 - Autofill 10 nodes in tree" << '\n'
			<< "2 - Insert node" << '\n'
			<< "3 - Symmetric order" << '\n'
			<< "4 - Width order" << '\n'
			<< "5 - Find the averange of value of the tree" << '\n'
			<< "6 - Find the distance from root to entered element" << '\n'
			<< "7 - Show the tree" << '\n'
			<< "0 - Exit" << '\n';
		std::cin >> menu;
		if (menu == 1)
		{
			vector<int> nums{ 10,40,30,60,90,70,20,50,80,100 };
			for (auto num : nums)
				tree.insert(num);
		}

		if (menu == 2)
		{
			int key = 0;
			std::cout << "Input the number that you wanna add at tree: ";
			std::cin >> key;
			tree.insert(key);
		}

		if (menu == 3)
		{
			tree.inOrder();
			std::cout << '\n';
		}

		if (menu == 4)
		{
			tree.BFS();
			std::cout << '\n';
		}

		if (menu == 5)
		{
			std::cout << "The averange: " << tree.average();
		}

		if (menu == 6)
		{
			int key = 0;
			std::cout << "Input the number, that depth you wanna find: ";
			std::cin >> key;
			if (tree.find_distance(key) == -1)
			{
				std::cout << "Entered number not exist in tree";
			}
			
			else
			{
				std::cout << "The depth of you number = " << tree.find_distance(key) + 1;
			}
		}

		if (menu == 7)
		{
			std::cout << "0 - Black, 1 - Red" << '\n';
			tree.print();
		}
	}
}