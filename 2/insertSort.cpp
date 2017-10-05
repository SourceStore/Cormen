#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int		main()
{
	int	curr;
	int i;

	vector<int> v = {-2, 4, -100, 3, -1, 2, 1, 0};
	for (auto i = v.begin(); i != v.end(); ++i)
		cout << *i << ' ';
	cout << endl;

	// for (int j = 2; j < v.size(); j++)
	// {
	// 	curr = v[j];
	// 	i = -1;
	// 	while (++i < j && v[i] > curr)
	// 	{
	// 		v[j] = v[i];
	// 		v[i] = curr;
	// 		curr = v[j];
	// 	}
	// }
	for (int j = 1; j < v.size(); j++)
	{
		curr = v[j];
		i = j - 1;
		while (i >= 0 && v[i] < curr)
		{
			v[i + 1] = v[i];
			i--;
		}
		v[i + 1] = curr;
	}
	for (auto i = v.begin(); i != v.end(); ++i)
		cout << *i << ' ';
	return (0);
}
