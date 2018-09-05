

#ifndef _TIME_H_
#define _TIME_H_

#include <time.h>
#include <memory>
#include <iostream>

class Time
{

};

void time_test()
{
	time_t  t = time(NULL);
	std::cout << t << std::endl;
}

#endif


