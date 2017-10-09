#ifndef BINARYTREE_HPP
# define BINARYTREE_HPP

# include <stdio.h>
# include <string.h>
# include <iostream>
# include <limits>
# include <vector>

using namespace std;

typedef struct 			s_binaryTree {

	double	data;
	int		h;
	struct s_binaryTree *left;
	struct s_binaryTree *right;
	struct s_binaryTree *parent;
}						t_binaryTree;


class BinaryTree {

	private:
		int				h;
		t_binaryTree	*head;
	public:
		BinaryTree();
		BinaryTree(double head_data);
		~BinaryTree();

		void			insertNode(double data, t_binaryTree *node);
		void			swapNodes(double data, t_binaryTree *node);
		t_binaryTree	*initNode(double data);
		t_binaryTree	*findNode(double data, t_binaryTree *node);
		void			addNewNode(double data, t_binaryTree *node);
		void			deleteNode(double data, t_binaryTree *node);
		void			transplant(double data, t_binaryTree *node, t_binaryTree *u, t_binaryTree * v);
		t_binaryTree	*getHead(BinaryTree &bt);
		double			getData(t_binaryTree *node);
		void			inorderTreeWalk(t_binaryTree *node);
		void			printHead();
		void			tryPrint(t_binaryTree *node);
		t_binaryTree	*findMax(t_binaryTree *node);
		t_binaryTree	*findMin(t_binaryTree *node);
		t_binaryTree	*treeSuccessor(t_binaryTree *node);

		void			freeAll(t_binaryTree *node);
};

#endif