
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

//�������

//����[k,m]������
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
		//�ݹ���Ҫ������ô���� F(n)����Ϊ F(n-1)
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

//��ϣ������Ӽ�
//����n��Ԫ�ص������Ӽ��������ռ�

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