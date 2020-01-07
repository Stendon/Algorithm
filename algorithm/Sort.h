

/*******************************************
*File:		Sort.h
*Author:	Michael.Wang
*Function:	All kinds of sort 
*Date:		2015-05-23
*Version:	1.0
*******************************************/

#ifndef _SORT_H_
#define _SORT_H_

using std::swap;

/*select the index of minimum every round, and exchange the value 
* to the first element of this round
*/
template < typename T >
bool select_sort(T arr[], size_t length)
{
	///
	if (length <= 0)
		return false;
	for (size_t i = 0; i < length -1 ; ++i)
	{
		///cursor of traversal
		size_t index = i;
		for (size_t j = i + 1; j < length; ++j)
		{
			///chooset the minimum value 
			if (arr[j] < arr[index])
				index = j;
		}
		std::swap(arr[index], arr[i]);
	}
	return true;
}

/*insert sort: loop every element and compare with all previous element, 
if small, backward element and go on
*/
template < typename T >
bool insert_sort(T arr[], size_t length)
{
	if (length <= 0)
		return false;
	for (size_t i = 1; i < length; ++i)
	{
		T temp = arr[i];
		size_t j = i - 1;
		///backward the element and at last
		while (j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		///exchange the temporary elem with first not match elem
		std::swap(arr[++j], temp);
	}
	return true;
}

/*bubble sort
*loop elements and compare the ajacent element as asc, until the end
*/
template < typename T >
bool bubble_sort(T arr[], size_t length)
{
	if (length <= 0)
		return false;
	for (size_t i = 0; i < length; ++i)
	{
		for (size_t j = length - 1; j > i; --j)
		{
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
		}
	}
	return true;
}

///recursively invoke the algorithm
template < typename T >
bool merge_sort(T arr[], size_t low, size_t high, T temp_arr[])
{
	while (low < high)
	{
		size_t middle = (low + high) / 2;
		merge_sort(arr, low, middle, temp_arr);
		merge_sort(arr, middle + 1, high, temp_arr);
		merge_array(arr, low, middle, high, temp_arr);
	}

	return true;
}
/*merge the arr[low...mid] and arr[mid+1...high] into an array 
*/
template < typename T >
void merge_array(T arr[], size_t low, size_t mid, size_t high, T temp_arr[])
{
	size_t i = low, j = high, p = low;
	
	while (i <= mid && j <= high)
		temp_arr[p++] = arr[i] > arr[j] ? arr[i++] : arr[j++];
	while (i <= mid)
		temp_arr[p++] = arr[i++];
	while (j <= high)
		temp_arr[p++] = arr[j++];
}


//quick sort
int partition(int *arr, int p, int r)
{
	int x = arr[r];
	int i = p - 1;
	for (int j = p; j < r; ++j)
	{
		if (arr[j] <= x)
			std::swap(arr[++i], arr[j]);
	}
	std::swap(arr[i + 1], arr[r]);
	return i + 1;
}

template < typename T >
void quick_sort(T *arr, int low, int high)
{
	if (low < high)
	{
		int p = partition(arr, low, high);
		quick_sort(arr, low, p - 1);
		quick_sort(arr, p + 1, high);
	}
}

/*count sort
*/
template < typename T >
bool count_sort(T arr[], size_t length)
{
	//check for array 
	if (length <= 0)
		return false;
	
	//get maximum value
	T max = arr[0];
	for (size_t i = 1; i < length; ++i)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	//
	T *temp = new T[length];
	for (size_t i = 0; i < length; ++i)
	{
		temp[arr[i]]++;
	}

	//copy to original array
	for (size_t i = 0; i < length; ++i)
	{

	}
}
#endif