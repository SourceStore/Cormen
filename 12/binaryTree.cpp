#include "binaryTree.hpp"

BinaryTree::BinaryTree() {

	head = new t_binaryTree;
	head->data = 2000;
	head->parent = NULL;
	head->left = NULL;
	head->right = NULL;
}

BinaryTree::BinaryTree(double head_data) {

	head = new t_binaryTree;
	head->data = head_data;
	head->parent = NULL;
	head->left = NULL;
	head->right = NULL;
}

BinaryTree::~BinaryTree() {

}

t_binaryTree	*BinaryTree::initNode(double data) {

	t_binaryTree *node;

	node = new t_binaryTree;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

void	BinaryTree::deleteNode(double data, t_binaryTree *node) {

	while (node) {
		if (node->data > data)
			node = node->left;
		else if (node->data < data)
			node = node->right;
		else if (node->data == data)
			break;
	}
	if (node->left == NULL || node->right == NULL)
	{
		if (node->left)
		{
			node->left->parent = node->parent;
			if (node->parent->data > data)
				node->parent->left = node->left;
			else
				node->parent->right = node->left;
			delete node;
		}
		else if (node->right)
		{
			node->right->parent = node->parent;
			if (node->parent->data < data)
				node->parent->right = node->right;
			else
				node->parent->left = node->right;
			delete node;
		}
	}
}

void	BinaryTree::printHead() {

	cout << head->data << endl;
}

void	BinaryTree::tryPrint(t_binaryTree *node) {

	if (node != NULL) {
		cout << node->data << endl;
		tryPrint(node->left);
		tryPrint(node->right);
	}
}

t_binaryTree	*BinaryTree::getHead(BinaryTree &bt) {

	return (bt.head);
}

void			BinaryTree::inorderTreeWalk(t_binaryTree *node) {

	if (node) {
		inorderTreeWalk(node->left);
		cout << node->data << " ";
		inorderTreeWalk(node->right);
	}
}

void		BinaryTree::addNewNode(double data, t_binaryTree *node) {

	if (node->left != NULL && node->data >= data)
		addNewNode(data, node->left);
	if (node->right != NULL && node->data < data)
		addNewNode(data, node->right);
	if (node->data >= data && node->left == NULL) {
		node->left = initNode(data);
		node->left->parent = node;
	}
	else if (node->data < data && node->right == NULL) {
		node->right = initNode(data);
		node->right->parent = node;
	}
}

t_binaryTree		*BinaryTree::findNode(double data, t_binaryTree *node) {

	if (node) {
		if (node->data == data) {
 			return (node);
		}
		else if (node->data > data) {
			findNode(data, node->left);
		}
		else {
			findNode(data, node->right);
		}
	}
}

double		BinaryTree::getData(t_binaryTree *node) {

	return(node->data);
}

t_binaryTree	*BinaryTree::findMax(t_binaryTree *node) {

	if (node->right->right == NULL)
		return (node->right);
	findMax(node->right);
}

t_binaryTree	*BinaryTree::findMin(t_binaryTree *node) {

	if (node->left->left == NULL)
		return (node->left);
	findMax(node->left);
}

t_binaryTree	*BinaryTree::treeSuccessor(t_binaryTree *node) {

	if (node->right != NULL)
		return (findMin(node));
	else if (node->left != NULL) {
		return (findMax(node));
	}
}

void			BinaryTree::swapNodes(double data, t_binaryTree *node) {
	
	t_binaryTree	*swapNode;

	swapNode = initNode(data);
	swapNode->right = node;
	swapNode->left = node->left;
	swapNode->parent = node->parent;
	node->parent = swapNode;
}

void			BinaryTree::transplant(double data, t_binaryTree *node, t_binaryTree *u, t_binaryTree * v)
{
	if (u->parent == NULL)
		node = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	if (v != NULL)
		v->parent = u->parent;
}

void		BinaryTree::freeAll(t_binaryTree *node) {

	if (node) {
		freeAll(node->left);
		if (node)
			delete node;
		freeAll(node->right);
	}
}