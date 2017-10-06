#include "binaryTree.hpp"

BinaryTree::BinaryTree()
{

	head = new t_binaryTree;
	head->data = 2000;
	head->parent = NULL;
	head->left = NULL;
	//head->right = NULL;
	head->right = new t_binaryTree;

	head->right->data = 2500;
	head->right->left = NULL;
	head->right->right = NULL;
	head->right->parent = head;
}

BinaryTree::BinaryTree(double head_data)
{
	head = new t_binaryTree;
	head->data = head_data;
	head->parent = NULL;
	head->left = NULL;
	head->right = NULL;
}

BinaryTree::~BinaryTree()
{

}

void	BinaryTree::addNode(double data)
{
	t_binaryTree *node;

	node = new t_binaryTree;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	if (data < head->data)
	{
		head->left = node;	
	}
	else
	{
		head->right = node;
	}
	node->parent = head;
}

void	BinaryTree::deleteNode(double data)
{
	;
}

void	BinaryTree::printHead()
{
	cout << head->data << endl;
}

void	BinaryTree::kostil()
{
	cout << head->left->data << endl;
}

void	BinaryTree::tryPrint(t_binaryTree *node)
{
	if (node != NULL)
	{
		cout << node->data << endl;
		tryPrint(node->left);
		tryPrint(node->right);
	}
}

t_binaryTree	*BinaryTree::getHead(BinaryTree &bt)
{
	return (bt.head);
}
