#ifndef NODE_H
#define NODE_H

template<class type>
class stack;


template<class type>
class NODE
{
	friend class stack<type>;
private:
	type data;
	NODE<type>* next;
public:
	NODE(type X, NODE<type>* next = nullptr)
	{
		this->data = X;
		this->next = next;
	}

	~NODE()
	{

	}
};


#endif
