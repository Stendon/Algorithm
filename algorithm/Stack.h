


/*******************************************
*File:		Stack.h
*Author:	Michael.Wang
*Function:	Simple stack data structure
*Date:		2015-05-23
*Version:	1.0
*******************************************/


#ifndef _STACK_H_
#define _STACK_H_

template < typename T >
class stack
{
public:
	stack(int size);
	~stack();

	void push(T const & value);
	T pop();
	int size()const;
	bool empty()const;
	T top()const;

private:
	T * elem;
	int length;
	int max_size;
};

template < typename T >
stack<T>::stack(int size)
{
	elem = new T[size];
	length = -1;
	max_size = size;
}

template < typename T >
stack<T>::~stack()
{
	delete []elem;
}

template < typename T >
void stack<T>::push(T const & value)
{
	_ASSERT(max_size > length);
	elem[++length] = value;
}

template < typename T >
T stack<T>::pop()
{
	_ASSERT(length >= 0);

	return elem[length--];
}

template < typename T >
int stack<T>::size()const
{
	return length;
}

template < typename T >
bool stack<T>::empty()const
{
	return length >= 0;
}

template < typename T >
T stack<T>::top()const
{
	_ASSERT(length >= 0);
	return elem[length];
}

#endif