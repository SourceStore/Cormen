/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 18:38:05 by rishchen          #+#    #+#             */
/*   Updated: 2017/10/06 18:38:20 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void		mergerSort(vector<double> &vec)
{
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

	std::vector<double> numbers = {5, 4, 3, 2, -1, 0};
	mergerSort(numbers);
	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;
	return (0);
}