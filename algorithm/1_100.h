

#ifndef _JUDGE_ONLINE_H_
#define _JUDGE_ONLINE_H_

#include <iostream>
#include <iomanip>

// 0001 
void print_circle_array()
{
	int n = 0, k = 1, loop = 0, sum = 0;
	bool w = false, d = false;
	std::cin >> n;

	int **p = new int *[n];
	for (int i = 0; i < n; ++i)
		p[i] = new int[n];

	for (int i = n / 2, j = n / 2;;)
	{
		p[i][j] = k++;
		if (i == j && i == n - 1)
			break;
		if (i == j)
		{
			w = d = false;
			if (i >= n / 2)
			{
				++j;
				loop += 2;
			}
			else
			{
				++i;
			}
		}
		else if (i < j)
		{
			if ((j - i) % loop == 0)
				w = true;

			if (w)
				--j;
			else
				--i;
		}
		else
		{
			if ((i - j) % loop == 0)
				d = true;

			if (d)
				++j;
			else
				++i;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << std::setw(3) << p[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0, j = n - 1; i < n; --j, ++i)
	{
		sum += (p[i][i] + p[i][j]);
	}

	//std::cout << sum - p[n / 2][n / 2] << std::endl;
}


#endif