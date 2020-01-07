#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::string;


bool isLetterExist(string J, char c)
{
	for (size_t i = 0; i < J.size(); ++i)
	{
		if (J[i] == c)
			return true;
	}
	return false;
}

//problem 771
int numJewelsInStones(string J, string S) 
{
	int sum = 0;
	for (size_t i = 0; i < S.size(); ++i)
	{
		if (isLetterExist(J, S[i]))
			++sum;
	}
	return sum;
}

using std::vector;

//977
vector<int> sortedSquares(vector<int>& A) 
{
	std::vector<int> s;
	for (size_t i = 0; i < A.size(); ++i)
		s.emplace_back(A[i] * A[i]);
	std::sort(s.begin(), s.end());
	return s;
}

//709
string toLowerCase(string str) 
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
	return str;
}
