#ifndef STACK_BASE_ARRAY_H
#define STACK_BASE_ARRAY_H

#include <iostream>
using namespace std;

template<class type>
class stack
{
private:
	type* item;
	int size;
	int top;
public:
	stack(int size);
	bool fail();
	~stack();
	bool isEmpty();
	bool push(type X);
	type pop();
};

#include "stack_base_array.h"

template<class type>
stack<type>::stack(int size)
{
	item = new (nothrow) type[size];
	if (!fail())
	{
		this->size = size;
		this->top = 0;
	}
}

template<class type>
stack<type>::~stack()
{
	if (fail()) { return; }
	delete[] item;
	item = nullptr;
	size = 0;
	top = 0;
}


template<class type>
bool stack<type>::fail()
{
	return item == nullptr ? 1 : 0;
}

template<class type>
bool stack<type>::isEmpty()
{
	return top == 0 ? 1 : 0;
}

template<class type>
bool stack<type>::push(type X)
{
	if (top == size) { return false; }
	item[top] = X;
	top++;
	return true;
}

template<class type>
type stack<type>::pop()
{
	return item[--top];
}
#endif