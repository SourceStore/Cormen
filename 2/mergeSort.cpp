#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void		mergeSort(vector<int> &arrayInt)
{
	int 	sizeL;
	int 	sizeR;
	std::vector<int> lPart;
	std::vector<int> rPart;

	sizeL = arrayInt.size() / 2;
	sizeR = arrayInt.size();
	for (int i = 0; i < sizeL; i++)
	{
		lPart.push_back((arrayInt)[i]);
	}
	for (int i = sizeL; i < sizeR; i++)
	{
		rPart.push_back((arrayInt)[i]);
	}
	if (lPart.size() > 1)
		mergeSort(lPart);
	if (rPart.size() > 1)
		mergeSort(rPart);


	int l;
	int r;

	l = 0;
	r = 0;
	for (int i = 0; i < sizeR; i++)
	{
		if (lPart[l] <= rPart[r] || r == rPart.size())
		{
			arrayInt[i] = lPart[l];
			l++;
		}
		else if (rPart[r] < lPart[l] || l == sizeL)
		{
			arrayInt[i] = rPart[r];
			r++;
		}
	}
}

int	main(){
	//int	size = 10;
	//vector<int>	arrayInt = {10, 9, 8 , 7, 6, 5, 4, 3, 2, 1};
	vector<int> arrayInt = {10, 9, 8 , 7, -6, 5, 4, 3, 2, 1};
	mergeSort(arrayInt);
	// vector<int> arraySorted;
	// vector<int> lPart;
	// vector<int> rPart;

	// for (int i = 0; i < size / 2; ++i)
	// {
	// 	lPart.push_back(arrayInt[i]);
	// }
	// for (int i = size / 2; i < size; ++i)
	// {
	// 	rPart.push_back(arrayInt[i]);
	// }

	// int l;
	// int r;

	// l = 0;
	// r = 0;
	// for (int i = 0; i < size; ++i)
	// {
	// 	if (lPart[l] <= rPart[r] || r == rPart.size())
	// 	{
	// 		arraySorted.push_back(lPart[l]);
	// 		l++;
	// 	}
	// 	else if (l != lPart.size())
	// 	{
	// 		arraySorted.push_back(rPart[r]);
	// 		r++;
	// 	}
	// }

	for (int i = 0; i < arrayInt.size(); ++i)
	{
		cout << arrayInt[i] << " ";
	}

	// cout << endl;
	return (0);
}