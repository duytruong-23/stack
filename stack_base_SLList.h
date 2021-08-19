#ifndef STACK_BASE_SLLIST_H
#define STACK_BASE_SLLIST_H

#include "Node.h"
#include <new>

template<class type>
class stack
{
private:
	Node<type>* m_pHead;
public:
	stack();
	~stack();
	bool isEmpty();
	bool push(const type& X);
	type pop();
private:
	void deleteNode(Node<type>*& X);
};

template<class type>
stack<type>::stack()
	: m_pHead(nullptr)
{
}

template<class type>
bool stack<type>::isEmpty()
{
	return (m_pHead == nullptr);
}

template<class type>
bool stack<type>::push(const type& X)
{
	Node<type>* newNode = new (std::nothrow) Node<type>(X);
	if (newNode == nullptr) { return false; }
	if (m_pHead == nullptr)
	{
		m_pHead = newNode;
		return true;
	}
	newNode->m_pNext = m_pHead;
	m_pHead = newNode;
	return true;
}

template<class type>
type stack<type>::pop()
{
	if (isEmpty())
	{
		throw "Error : Stack Is Empty!";
	}
	Node<type>* p = m_pHead;
	m_pHead = m_pHead->m_pNext;
	type X = p->m_Data;
	deleteNode(p);
	return X;
}

template<class type>
void stack<type>::deleteNode(Node<type>*& X)
{
	if (X == nullptr) { return; }
	X->m_pNext = nullptr;
	delete X;
	X = nullptr;
}

template<class type>
stack<type>::~stack()
{
	while (m_pHead != nullptr)
	{
		pop();
	}
}
#endif
