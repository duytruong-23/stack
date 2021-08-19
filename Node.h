#ifndef NODE_H
#define NODE_H

template<class type>
class stack;

template<class type>
class Node
{
	friend class stack<type>;
private:
	type m_Data;
	Node<type>* m_pNext;
public:
	Node(const type& X, Node<type>* next = nullptr)
		: m_Data(X), m_pNext(next)
	{
	}
	~Node()
	{
	}
};


#endif
