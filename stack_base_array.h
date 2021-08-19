#ifndef STACK_BASE_ARRAY_H
#define STACK_BASE_ARRAY_H

#include <new>

template<class type>
class stack
{
private:
	type* m_pItems;
	int m_nSize;
	int m_nTop;
public:
	stack(const int& size);
	bool isFail();
	bool isFull();
	~stack();
	bool isEmpty();
	bool push(const type& X);
	type pop();
};


template<class type>
stack<type>::stack(const int& size)
{
	if (size <= 0) { m_pItems == nullptr; }
	m_pItems = new (std::nothrow) type[size];
	if (!isFail())
	{
		this->m_nSize = size;
		this->m_nTop = 0;
	}
}

template<class type>
stack<type>::~stack()
{
	if (isFail()) { return; }
	delete[] m_pItems;
	m_pItems = nullptr;
	m_nSize = 0;
	m_nTop = 0;
}


template<class type>
bool stack<type>::isFail()
{
	return (m_pItems == nullptr);
}

template<class type>
bool stack<type>::isEmpty()
{
	return (m_nTop == 0);
}

template<class type>
bool stack<type>::isFull()
{
	return (m_nTop == m_nSize);
}

template<class type>
bool stack<type>::push(const type& X)
{
	if (isFull()) { return false; }
	m_pItems[m_nTop] = X;
	m_nTop++;
	return X;
}

template<class type>
type stack<type>::pop()
{
	if (isEmpty())
	{
		throw "Error : Stack Is Empty!";
	}
	return m_pItems[--m_nTop];
}
#endif