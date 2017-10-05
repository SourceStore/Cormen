#ifndef BINARYTREE_HPP
# define BINARYTREE_HPP

# include <stdio.h>
# include <string.h>
# include <iostream>
# include <limits>

using namespace std;

typedef struct 			s_binaryTree
{
	double	data;
	int		h;
	struct s_binaryTree *left;
	struct s_binaryTree *right;
	struct s_binaryTree *parent;
}						t_binaryTree;


class BinaryTree
{
	private:
		int				h;
		t_binaryTree	*head;
	public:
		BinaryTree();
		~BinaryTree();

		void	addNode(double data);
		void	deleteNode(double data);
		t_binaryTree	*getHead(BinaryTree &bt);
		//void 	printAll();
		void	printHead();
		void	tryPrint(t_binaryTree *node);
		void	kostil();
};

#endif