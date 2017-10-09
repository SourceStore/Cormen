/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 18:33:52 by rishchen          #+#    #+#             */
/*   Updated: 2017/10/09 17:28:57 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binaryTree.hpp"

void		mergerSort(vector<double> &vec) {
	vector<double> lPart;
	vector<double> rPart;

	int l;
	int r;
	int size;
	int sizeL;
	int sizeR;
	l = 0;
	r = 0;
	size = vec.size();
	if (size == 1)
		return ;
	sizeL = size / 2;
	sizeR = size - sizeL;

	for (int i = 0; i < sizeL; ++i) {
		lPart.push_back(vec[i]);
	}
	for (int i = sizeL; i < size; ++i) {
		rPart.push_back(vec[i]);
	}

	if (sizeL > 1)
		mergerSort(lPart);
	if (sizeR > 1)
		mergerSort(rPart);

	for (int i = 0; i < size; ++i) {
		if ((lPart[l] <= rPart[r] || r == sizeR) && l != sizeL) {
			vec[i] = lPart[l];
			l++;
		}
		else if ((rPart[r] < lPart[l] || l == sizeL) && r != sizeR) {
			vec[i] = rPart[r];
			r++;
		}
	}
}

int	main() {


	//auto i, j;
	//std::vector<double> numbers = {5, 4, 3, 2, -1, 0};
	std::vector<double> numbers = {2, 3, 4, 5, 6, 8};
	// std::vector<double> numbers = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	mergerSort(numbers);
	//mergerSort(numbers, 0, numbers.size());
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
	BinaryTree bt = BinaryTree(numbers[numbers.size() / 2]);
	for (int i = 0; i < numbers.size(); i++) {
		if (i != numbers.size() / 2) {
			bt.addNewNode(numbers[i], bt.getHead(bt));
		}
	}
	//bt.tryPrint(bt.getHead(bt));
	bt.inorderTreeWalk(bt.getHead(bt));
	cout << endl;
	bt.addNewNode(100, bt.getHead(bt));
	bt.inorderTreeWalk(bt.getHead(bt));
	cout << "\n==============" << endl;
	bt.deleteNode(8, bt.getHead(bt));
	bt.inorderTreeWalk(bt.getHead(bt));
	cout << endl;

	bt.freeAll(bt.getHead(bt));
	//bt.insertNode(7, bt.getHead(bt));
	//t_binaryTree *test_data = bt.findNode(6, bt.getHead(bt));
	return (0);
}