#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int		main() {

	int	cols = 8;
	int	rows = 8;

	int	start = 1;
	int	size = 0;
	
	int i = 0;
	int j = 0;
	int	**matrix;
	matrix = new int*[rows];

	int k;
		for (int l = 0; l < rows; l++)
		{
			k = -1;
			matrix[l] = new int[cols];
			while (++k < cols)
			{
				matrix[l][k] = 0;
			}
		}

	while(start <= cols * rows)
	{
		j = size;
		//cout << "I = " << i << endl;
		if (i == size)
		{
			while (j < cols - size)
			{
				matrix[i][j] = start;
				start++;
				j++;
			}
		}
		if (j == cols - size)
		{
			j--;
			i++;
			while (i < rows - size)
			{
				matrix[i][j] = start;
				start++;
				i++;
			}
			size++;
			i--;
		}
		if (i == rows - size)
		{
			j--;
			if (cols % 2 == 0)
			{
				while (j >= cols - (cols - size))
				{
					matrix[i][j] = start;
					start++;
					j--;	
				}
			}
			else if (cols % 2 == 1)
			{
				while (j >= cols - (cols - size) - 1)
				{
					matrix[i][j] = start;
					start++;
					j--;	
				}
				j++;
			}
			if (cols % 2 == 0)
			{
				while (i > cols - (rows - size))
				{
					matrix[i][j] = start;
					start++;
					i--;				
				}	
				matrix[i][j] = start;
				start++;
			}
			else if (cols % 2 == 1)
			{
				i--;
				while (i >= cols - (rows - size))
				{
					matrix[i][j] = start;
					start++;
					i--;				
				}
				i++;
			}
		}
	}


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; ++j)
		{
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}
	return (0);
}

// 	while(i < rows)
// 	{
// 		j = size;
// 		//cout << "I = " << i << endl;
// 		if (i == size)
// 		{
// 			while (j < cols - size)
// 			{
// 				matrix[i][j] = start;
// 				start++;
// 				j++;
// 			}
// 		}
// 		if (j  == cols - size)
// 		{
// 			j--;
// 			i++;
// 			while (i < rows - size)
// 			{
// 				matrix[i][j] = start;
// 				start++;
// 				i++;
// 			}
// 			if (i == rows - size)
// 			{
// 				size++;
// 				i--;
// 				//cout << i << " " << j << " " << size << " " << start <<endl; 
// 				while (j >= cols - (cols - size))
// 				{
//     				matrix[i][j] = start;
//     				start++;
//     				j--;
// 				}
// 			}
// 			j++;
// 		}
// 		//cout << i << endl;
// 		if (j == size)
// 		{
// 			i--;
// 			while (i >= size)
// 			{
// 				matrix[i][0] = start;
// 				start++;
// 				i--;
// 			}
// 			i++;
// 		}
// 	}


// 	for (int i = 0; i < rows; i++)
// 	{
// 		for (int j = 0; j < cols; ++j)
// 		{
// 			cout << matrix[i][j] << '\t';
// 		}
// 		cout << endl;
// 	}
// 	return (0);
// }