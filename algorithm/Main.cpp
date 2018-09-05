


#include <iostream>
#include <iomanip>
#include "1_100.h"
#include <vector>

class A
{
public:
	virtual ~A()
	{
		std::cout << "A()" << std::endl;
	}
};

class B : public A
{
public:
	~B()
	{
		std::cout << "B()" << std::endl;
	}
};

int main(int argc, char**argv)
{
	A * pb = new B();
	delete pb;
	//print_circle_array();
	return 0;
}