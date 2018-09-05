
/*******************************************
*File:		BasicAlgoithm.h
*Author:	Michael.Wang
*Function:	Basic computer algorithm
*Date:		2015-05-23
*Version:	1.0
*******************************************/

#ifndef _BASIC_ALGORITHM_H_
#define _BASIC_ALGORITHM_H_

#include <iostream>

template < typename T >
void Swap(T &a, T& b)
{
	T temp = a;
	a = b;e
	b = temp;
}

size_t sum = 0;

//排列组合

//生成[k,m]的排列
template < typename T >
void Perm(T arr[], size_t k, size_t m)
{
	size_t i = 0;
	if (k == m)
	{
		for (i = 0; i <= m; ++i)
		{
			std::cout << arr[i];
		}
		sum++;
		std::cout << std::endl;
	}
	else
	{
		//递归主要考虑怎么样把 F(n)消减为 F(n-1)
		for (size_t t = k; t <=m; ++t)
		{
			Swap(arr[k], arr[t]);
			Perm(arr, k + 1, m);
			Swap(arr[t], arr[k]);
		}
	}
}

void basic_alg_test_case()
{
	int a[] = {1,2,3,4,5,6};
	Perm(a, 0, 5);

	std::cout << sum << std::endl;
}

//组合，生成子集
//生成n个元素的所有子集，包括空集

template < typename T >
void Combination(T arr[], size_t n)
{
	for (size_t i = 0; i <= n; ++i)
	{
		Composite(arr, n, i);
	}
}

//C[n:k]
template < typename T >
void Composite(T arr[], size_t n, size_t k)
{

}

void hanota(int n, char a, char b, char c)
{

}

#endif