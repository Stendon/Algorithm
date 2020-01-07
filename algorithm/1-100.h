

//first
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <chrono>

void question_1002()
{
	int num = 0;
	std::cin >> num;

	std::string *telephone = new std::string[num];

	for (int i = 0; i < num; ++i)
	{
		std::cin >> telephone[i];
	}

	char str[9];
	char *pattern = "22233344455566677778889999";
	int index = 0;

	for (int i = 0; i < num; ++i)
	{
		std::string current_string = telephone[i];
		for (int j = 0, k = 0; j < 8; ++k)
		{

			if (current_string[k] == '-')
				continue;

			if ((int)current_string[k] >= 0x30 && current_string[k] <= 0x39)
			{
				str[j] = current_string[k];
			}
			else if (current_string[k] >= 0x41 && current_string[k] <= 0x59)
			{
				str[j] = pattern[current_string[k] - 'A'];
			}

			++j;

			if (j == 3)
			{
				str[j] = '-';
				++j;
			}
		}
		str[8] = '\0';

		telephone[i] = str;
	}

	std::sort(telephone, telephone + num);

	bool duplicate_string_exist = false;
	int k = 1, count = 1;;

	while (k < num)
	{
		while (k < num && telephone[k] == telephone[k - 1])
		{
			++k;
			++count;
		}

		if (count > 1)
		{
			duplicate_string_exist = true;
			std::cout << telephone[k - 1] << " " << count << std::endl;
		}

		count = 1;
		++k;
	}

	if (!duplicate_string_exist)
	{
		std::cout << "No duplicates." << std::endl;
	}

	delete[]telephone;


}

void Question_1003()
{
	double d = 1.0;
	double sum = 0.00;
	while (std::cin >> d)
	{
		if (d == 0.00)
			break;
		if (d < 0.01 || d > 5.20)
			continue;

		for (int i = 2;; ++i)
		{
			sum = sum + (double)1 / i;
			if (sum >= d)
			{
				std::cout << i - 1 << " card(s)" << std::endl;
				break;
			}
		}

		sum = 0.00;
	}
}

void question_1005()
{

	double pi = 3.1415926;
	double x = 0.0, y = 0.0;
	int num = 0, count = 0;
	std::cin >> num;

	int *p = new int[num];

	while (count < num)
	{
		std::cin >> x >> y;
		p[count] = (int)((x * x + y * y) * pi / 100) + 1;
		++count;
	}

	for (int i = 0; i < num; ++i)
	{
		std::cout << "Property " << i + 1 << ": This property will begin eroding in year " << p[i] << "." << std::endl;
	}

	std::cout << "END OF OUTPUT." << std::endl;

	delete[]p;
}

void question_1007()
{
	int string_length = 0, array_size = 0;
	std::cin >> string_length >> array_size;
	std::string temp = "";

	std::string *elem = new std::string[array_size];

	int *sortedness = new int[array_size];
	for (int i = 0; i < array_size; ++i)
	{
		sortedness[i] = 0;
	}

	for (int i = 0; i < array_size; ++i)
	{
		std::cin >> temp;
		elem[i] = temp;
	}

	for (int i = 0; i < array_size; ++i)
	{
		temp = elem[i];
		size_t string_size = temp.size();

		for (int j = string_size - 2; j >= 0; --j)
		{
			char ch = temp[j];
			for (int t = j + 1; t < string_size; ++t)
			{
				if (temp[t] < ch)
					++sortedness[i];
			}
		}

		//sort
		int k = i - 1;
		int current_result = sortedness[i];

		while (k >= 0 && current_result < sortedness[k])
		{
			sortedness[k + 1] = sortedness[k];
			elem[k + 1] = elem[k];
			--k;
		}
		std::swap(current_result, sortedness[++k]);
		std::swap(temp, elem[k]);
	}

	for (int i = 0; i < array_size; ++i)
	{
		std::cout << elem[i] << std::endl;
	}

}
//1028

void question_1028()
{

	std::string web_base = "http://www.acm.org/";
	std::string backward[1000], forward[1000];
	backward[0] = "Ignored";
	forward[0] = "Ignored";
	int backward_index = 0, forward_index = 0;
	std::string current_page = web_base, line = "";

	while (std::getline(std::cin, line))
	{
		std::istringstream stream(line);
		std::string temp = "";
		std::vector<std::string> v;
		while (stream >> temp)
		{
			v.push_back(temp);
		}

		if (v.size() >= 3)
			continue;
		else if (v.size() == 1)
		{
			if (v[0] == "BACK")
			{
				if (backward_index < 1)
				{
					std::cout << backward[0] << std::endl;

				}
				else if (backward_index >= 1)
				{
					forward_index++;
					forward[forward_index] = current_page;

					current_page = backward[backward_index];
					backward_index--;

					std::cout << current_page << std::endl;
				}
			}
			else if (v[0] == "FORWARD")
			{
				if (forward_index >= 1)
				{
					++backward_index;
					backward[backward_index] = current_page;

					current_page = forward[forward_index];
					--forward_index;

					std::cout << current_page << std::endl;
				}
				else
				{
					std::cout << forward[0] << std::endl;
				}
			}
			else if (v[0] == "QUIT")
			{
				break;
			}
		}
		else if (v.size() == 2)
		{
			if (v[0] == "VISIT")
			{
				if (v[1].size() > 70)
					continue;

				++backward_index;
				backward[backward_index] = current_page;

				current_page = v[1];
				forward_index = 0;

				std::cout << current_page << std::endl;
			}
		}
	}
}

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

void question_1159()
{
	int num_of_string = 0;
	while (std::cin >> num_of_string)
	{

		if (num_of_string < 3 || num_of_string > 5000)
			return;

		std::string pattern = "";
		std::cin >> pattern;

		int count = 0, i = 0, j = 0;

		int left = (num_of_string / 2) - 1, right = (num_of_string / 2 + num_of_string % 2);

		if (num_of_string % 2 != 0)
		{
			i = left, j = right;
			int a = evaluation(pattern, i, j - 1, num_of_string);
			int b = evaluation(pattern, i + 1, j, num_of_string);
			int c = evaluation(pattern, i, j, num_of_string);

			if (max(a, b, c) == 0)
				--right;
			else if (max(a, b, c) == 1)
				++left;
		}

		for (i = left, j = right; i >= 0 && j < num_of_string;)
		{
			if (pattern[i] == pattern[j])
			{
				--i;
				++j;
			}
			else
			{
				if (evaluation(pattern, i - 1, j, num_of_string)
					>= evaluation(pattern, i, j + 1, num_of_string))
				{
					++count;
					--i;
				}
				else
				{
					++count;
					++j;
				}
			}
		}
		if (i < 0)
			i = 0;
		count += (i - 0) + (num_of_string - j);

		std::cout << count << std::endl;
		count = 0;
	}
}
