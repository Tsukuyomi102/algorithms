//RBTree.h
#include"RBTNode.h"
#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

template<class T>
class  RBTree
{
public:
	RBTree();

	void insert(T key);
	void print();   
	void inOrder();
	void BFS();
	double average();
	int find_distance(int key);

private:
	void leftRotate(RBTNode<T>*& root, RBTNode<T>* x);
	void rightRotate(RBTNode<T>*& root, RBTNode<T>* y);

	void insert(RBTNode<T>*& root, RBTNode<T>* node);
	void InsertFixUp(RBTNode<T>*& root, RBTNode<T>* node);

	double average_key(RBTNode<T>* node);

	void print(RBTNode<T>* node)const;
	void inOrder(RBTNode<T>* tree)const;
	void BFS(RBTNode<T>* tree)const;
	int find_distance(RBTNode<T>* Node, int key, int level);

private:
	RBTNode<T>* root;
	double avg = 0;
	int num = 0;
};

template<class T>
RBTree<T>::RBTree() :root(NULL) 
{
	root = nullptr;
}

template<class T>
void RBTree<T>::leftRotate(RBTNode<T>*& root, RBTNode<T>* x) 
{
	RBTNode<T>* y = x->right;
	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;

	y->parent = x->parent;
	if (x->parent == NULL)
		root = y;
	else {
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
};

template<class T>
void RBTree<T>::rightRotate(RBTNode<T>*& root, RBTNode<T>* y) 
{
	RBTNode<T>* x = y->left;
	y->left = x->right;
	if (x->right != NULL)
		x->right->parent = y;

	x->parent = y->parent;
	if (y->parent == NULL)
		root = x;
	else {
		if (y == y->parent->right)
			y->parent->right = x;
		else
			y->parent->left = x;
	}
	x->right = y;
	y->parent = x;
};

template<class T>
void RBTree<T>::insert(T key)
{
	RBTNode<T>* z = new RBTNode<T>(key, Red, NULL, NULL, NULL);
	insert(root, z);
};

template<class T>
void RBTree<T>::insert(RBTNode<T>*& root, RBTNode<T>* node)
{
	RBTNode<T>* x = root;
	RBTNode<T>* y = NULL;
	while (x != NULL)
	{
		y = x;
		if (node->key > x->key)
			x = x->right;
		else
			x = x->left;
	}
	node->parent = y;
	if (y != NULL)
	{
		if (node->key > y->key)
			y->right = node;
		else
			y->left = node;
	}
	else
		root = node;
	node->color = Red;
	InsertFixUp(root, node);
};

template<class T>
void RBTree<T>::InsertFixUp(RBTNode<T>*& root, RBTNode<T>* node)
{
	RBTNode<T>* parent;
	parent = node->parent;
	while (node != RBTree::root && parent->color == Red)
	{
		RBTNode<T>* gparent = parent->parent;
		if (gparent->left == parent)
		{
			RBTNode<T>* uncle = gparent->right;
			if (uncle != NULL && uncle->color == Red)
			{
				parent->color = Black;
				uncle->color = Black;
				gparent->color = Red;
				node = gparent;
				parent = node->parent;
			}
			else
			{
				if (parent->right == node)
				{
					leftRotate(root, parent);
					swap(node, parent);
				}
				rightRotate(root, gparent);
				gparent->color = Red;
				parent->color = Black;
				break;
			}
		}
		else
		{
			RBTNode<T>* uncle = gparent->left;
			if (uncle != NULL && uncle->color == Red)
			{
				gparent->color = Red;
				parent->color = Black;
				uncle->color = Black;

				node = gparent;
				parent = node->parent;
			}
			else
			{
				if (parent->left == node)
				{
					rightRotate(root, parent);
					swap(parent, node);
				}
				leftRotate(root, gparent);
				parent->color = Black;
				gparent->color = Red;
				break;
			}
		}
	}
	root->color = Black;
}

template<class T>
void RBTree<T>::print() {
	if (root == NULL)
		cout << "empty RBtree\n";
	else
		print(root);
}

template<class T>
void RBTree<T>::print(RBTNode<T>* node)const {
	if (node == NULL)
		return;
	if (node->parent == NULL)
		cout << node->key << "(" << node->color << ") is root" << endl;
	else if (node->parent->left == node)
	{
		cout << node->key << "(" << node->color << ") is " << node->parent->key << "'s " << "left child" << endl;
	}
	else
	{
		cout << node->key << "(" << node->color << ") is " << node->parent->key << "'s " << "right child" << endl;
	}
	print(node->left);
	print(node->right);
}

template<class T>
void RBTree<T>::inOrder() 
{
	if (root == NULL)
		cout << "empty RBtree\n";
	else
		inOrder(root);
};

template<class T>
void RBTree<T>::inOrder(RBTNode<T>* tree)const {
	if (tree != NULL) {
		inOrder(tree->left);
		cout << tree->key << " ";
		inOrder(tree->right);
	}
}

template<class T>
void RBTree<T>::BFS() 
{
	if (root == NULL)
		cout << "empty RBtree\n";
	else
		BFS(root);
};

template<class T>
void RBTree<T>::BFS(RBTNode<T>* tree)const
{
	queue<RBTNode<T>*> q;
	q.push(tree);
	while (!(q.empty()))
	{
		RBTNode<T>* node = q.front();
		q.pop();
		std::cout << node->key << " ";
		if (node->left != NULL)
		{
			q.push(node->left);
		}
		if (node->right != NULL)
		{
			q.push(node->right);
		}
	}
}

template<class T>
double RBTree<T>::average()
{
	return average_key(root) / num;
}

template<class T>
double RBTree<T>::average_key(RBTNode<T>* p)
{
	if (root == NULL)
	{
		cout << "\nEmpty Tree.";
		return avg;
	}
	if (p != NULL)
	{
		avg = avg + p->key;
		num++;
		if (p->left)
		{
			average_key(p->left);
		}
		if (p->right)
		{
			average_key(p->right);
		}
		return avg;
	}
}

template<class T>
int RBTree<T>::find_distance(int key)
{
	return find_distance(root, key, 0);
}

template<class T>
int RBTree<T>::find_distance(RBTNode<T>* Node, int x, int level)
{
	if (Node == NULL)
	{
		return -1;
	}

	if (Node->key == x)
	{
		return level;
	}

	else
	{
		int left = find_distance(Node->left, x, level + 1);
		int right = find_distance(Node->right, x, level + 1);
		return (left != -1) ? left : right;
	}
}