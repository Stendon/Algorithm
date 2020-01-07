

#include <iostream>
#include <string>
#include "1_100.h"

int evaluation(const std::string& pattern, int left, int right, int length)
{
	int equal_num = 0;
	for (int i = left, j = right; i >= 0 && j < length; --i, ++j)
	{
		if (pattern[i] == pattern[j])
			++equal_num;
	}
	return equal_num;
}

int max(int a, int b, int c)
{
	if (a < b)
		return b > c ? 1 : 2;
	return a > c ? 0 : 2;
}

int main(int argc, char**argv)
{
	print_circle_array();
	return 0;
}