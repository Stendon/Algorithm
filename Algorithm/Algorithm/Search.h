



/*******************************************
*File:		Search.h
*Author:	Michael.Wang
*Function:	All kinds of search algorithm
*Date:		2015-05-23
*Version:	1.0
*******************************************/


#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <iostream>
#include "Sort.h"

///linear search, return 
template < typename T >
bool linear_search(T arr[], size_t length, T find_value)
{
	for (size_t i = 0; i < length; ++i)
	{
		if (arr[i] == find_value)
			return true;
	}
	return false;
}

/* binary search, recursive and non-recursive
*precondition: this array is sorted
*recursive algorithm
*/
template < typename T >
bool binary_search_recursive(T arr[], size_t low, size_t high, T find_value)
{
	size_t middle = (low + high) / 2;
	if (arr[middle] == find_value)
		return true;
	else if (arr[middle] > find_value)
		binary_search(arr, low, middle - 1, find_value);
	else
		binary_search(arr, middle + 1, high, find_value);
	return false;
}

///non recursive
template < typename T >
bool binary_search(T arr[], size_t low, size_t high, T find_value)
{
	while (low < high)
	{
		size_t middle = (low + high) / 2;

		if (arr[middle] == find_value)
			return true;
		else if (arr[middle] > find_value)
			high = middle - 1;
		else
			low = middle + 1;
	}
	return false;
}

void search_test()
{
	int arr[] = {0,4,2,6,9,1,5,7,8,3};
	bool find = false;
	//
	find = linear_search(arr, 10, 5);

	select_sort(arr, 10);
	for (size_t i = 0; i < 10; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	//find = binary_search_recursive(arr, 0, 10, 5);
	find = binary_search(arr, 0, 10, 6);

	std::cout << find << std::endl;

}

#endif