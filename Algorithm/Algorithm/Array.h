

#ifndef _ALGORITHM_ARRAY_H_
#define _ALGORITHM_ARRAY_H_

#include <iostream>
#include <iomanip>

template < typename T >
void Print(T a[], int length);

void array_test()
{
	int *p = new int[10];
	for (int i = 0; i < 10; ++i)
	{
		p[i] = i * i;
	}
	//һά����
	std::cout << "*****************һά����(10)*****************" << std::endl;
	Print(p, 10);
	delete []p;
	p = NULL;

	//��ά����
	int row = 5;
	int col = 4;
	int **q = new int *[row];
	for (int i = 0; i < col; ++i)
	{
		q[i] = new int[row];
	}

	//��ֵ
	for (int i = 0; i < col; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			q[i][j] = i + j;
		}
	}

	std::cout << "*****************��ά����([4,5])*****************" << std::endl;

	//��ӡ
	for (int w = 0; w < col; ++w)
	{
		Print(q[w], row);
	}

	//ɾ��
	for (int k = 0; k < col; ++k)
		delete []q[k];

	delete[]q;


	///��ά����
	int col1 = 4;
	int row1 = 5;
	int data = 6;

	int ***s = new int**[data];
	for (int i = 0; i < col1; ++i)
	{
		s[i] = new int*[row1];
		for (int k = 0; k < row1; ++k)
		{
			s[i][k] = new int[data];
		}
	}

	//��ά����
	std::cout.precision(2);
	std::cout << "*****************��ά����([4,5,6])*****************" << std::endl;
	for (int i = 0; i < col1; ++i)
	{
		for (int j = 0; j < row1; ++j)
		{
			for (int k = 0; k < data; ++k)
			{
				s[i][j][k] = i + j + k;
				std::cout <<std::setw(2) << s[i][j][k] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < col1; ++i)
	{
		for (int j = 0; j < row1; ++j)
		{
			delete[] s[i][j];
		}
	}

	for (int i = 0; i < col1; ++i)
	{
		delete []s[i];
	}

	delete[]s;


}

template < typename T >
void Print(T a[], int length)
{

	for (int i = 0; i < length; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

#endif