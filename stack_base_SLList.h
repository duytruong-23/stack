#ifndef STACK_BASE_SLLIST_H
#define STACK_BASE_SLLIST_H

#include <iostream>
#include"NODE.h"

using namespace std;

template<class type>
class stack
{
private:
	NODE<type>* head;
public:
	stack();
	~stack();
	bool isEmpty();
	bool push(type X);
	type pop();
	void deleteNODE(NODE<type>*& X);
};

template<class type>
stack<type>::stack()
{
	head = nullptr;
}

template<class type>
bool stack<type>::isEmpty()
{
	return head == nullptr ? 1 : 0;
}

template<class type>
bool stack<type>::push(type X)
{
	NODE<type>* newNODE = new (nothrow) NODE<type>(X);
	if (newNODE == nullptr) { return false; }
	if (head == nullptr)
	{
		head = newNODE;
		return true;
	}
	newNODE->next = head;
	head = newNODE;
	return true;
}

template<class type>
type stack<type>::pop()
{
	NODE<type>* p = head;
	head = head->next;
	type X = p->data;
	deleteNODE(p);
	return X;
}

template<class type>
void stack<type>::deleteNODE(NODE<type>*& X)
{
	if (X == nullptr) { return; }
	X->next = nullptr;
	delete X;
	X = nullptr;
}

template<class type>
stack<type>::~stack()
{
	while (head != nullptr)
	{
		pop();
    }
}
#endif
