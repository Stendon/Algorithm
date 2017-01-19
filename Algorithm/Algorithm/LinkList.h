
/*******************************************
*File:		LinkList.h
*Author:	Michael.Wang
*Function:	Single link list 
*Date:		2015-05-23
*Version:	1.0
*******************************************/


#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <iostream>

template < typename T >
struct list_node
{
public:
	list_node() :value(T()), next(nullptr){}
	list_node(T v, list_node* n = nullptr) : value(v), next(n){}
public:
	T			value;
	list_node*	next;
};

//this link list has head node 
template < typename T >
class link_list
{
public:

	link_list();
	~link_list();

	bool empty()const;
	int size()const;

	list_node<T>* insert_item(T const & value); // insert the value to the tail
	bool delete_item(T const & value);							 
	void iterate()const;						//iterate all elements
	list_node<T>* find(T const & value);

private:
	list_node<T>*	head;
	int				size_of_elem;
};

template < typename T >
link_list<T>::link_list()
{
	head = new list_node<T>();
	size_of_elem = 0;
}

template < typename T >
link_list<T>::~link_list()
{
	while (head != nullptr)
	{
		list_node<T> * node = head;
		head = head->next;
		delete node;
		node = nullptr;
	}
}

template < typename T >
bool link_list<T>::empty()const
{
	return size_of_elem == 0;
}

template < typename T >
int link_list<T>::size()const
{
	return size_of_elem;
}

template < typename T >
list_node<T>* link_list<T>::insert_item(T const & value)
{
	list_node<T> * node = new list_node<T>(value);
	list_node<T> * curr = head;

	while (curr->next != nullptr)
	{
		curr = curr->next;
	}
	curr->next = node;
	++size_of_elem;

	return node;
}

template < typename T >
bool link_list<T>::delete_item(T const & value)
{
	list_node<T>* node = head;
	while (node->next != nullptr)
	{
		if (node->next->value == value)
		{
			list_node<T>* temp = node->next;
			node->next = node->next->next;
			delete temp;
			temp = nullptr;
			--size_of_elem;

			return true;
		}
		else
			node = node->next;		
	}
	return false;
}

template < typename T >
void link_list<T>::iterate()const
{
	list_node<T>* node = head;
	while (node->next != nullptr)
	{
		node = node->next;
		std::cout << node->value << " ";	
	}
	std::cout << std::endl;
}

template < typename T >
list_node<T>* link_list<T>::find(T const &value)
{
	list_node<T>* node = head;
	while (node->next != nullptr)
	{
		node = node->next;
		if (node->value == value)
			return node;
	}

	return node->next;
}

void list_test()
{
	link_list<int> s;
	for (int i = 0; i < 10; ++i)
	{
		s.insert_item(i*i);
	}

	s.iterate();
	list_node<int>* node = s.find(25);
	if (node != nullptr)
		std::cout << node->value << std::endl;
	s.delete_item(0);
	s.delete_item(49);
	s.iterate();
}

//PARTITION(A, p, r)
//1  x ¡û A[r]
//2  i ¡û p - 1
//3  for j ¡û p to r - 1
//4       do if A[j] ¡Ü x
//5             then i ¡û i + 1
//6                  exchange A[i] <->A[j]
//7  exchange A[i + 1] <->A[r]
//8  return i + 1

#endif