#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include<iostream>
template<class T> struct Node;
template<class T> class DoubleList;
template<class T> std::ostream& operator<<(std::ostream& , const DoubleList<T> &);

template<class T>
class DoubleList{
	friend std::ostream& operator<< <>(std::ostream& os, const DoubleList &);
	private:
	size_t size;
	struct Node{
		T data;
		Node* prev ;
		Node* next ;
	};
	Node* Head = NULL;
	Node* Tail = NULL;
	Node* createNode(const T& data){
		Node* temp = new Node;
		temp -> data = data;
		temp -> prev = NULL;
		temp -> next = NULL;
		return temp;
		};

public:
	typedef Node* Np;

	DoubleList():size(0){};
	Node* head(){return Head;}
	Node* tail(){return Tail;}
	size_t Size(){return size;};
	std::ostream& forwardDisplayList(std::ostream& );
	std::ostream& backwardDisplayList(std::ostream& );
	DoubleList& addNode_front(const T& );
	DoubleList& addNode_back(const T& );
	DoubleList& addNode(const T&, const int&);
	DoubleList& deleteNode_front();
	DoubleList& deleteNode_back();
	DoubleList& deleteNode(const int&);
	const T& topValue(){return Head->data;};


};


template<class T>
std::ostream& DoubleList<T>::forwardDisplayList(std::ostream& os)
{
	Node* ptr = Head;
    while (ptr!=NULL)
    {
        os<<ptr->data<<" ";

        ptr=ptr->next;
    }
    return os;
}

template<class T>
std::ostream& DoubleList<T>::backwardDisplayList(std::ostream& os)
{
	Node* ptr = tail;
    while (ptr!=NULL)
    {
        os<<ptr->data<<" ";

        ptr=ptr->prev;
    }
    return os;
}

template<class T>
DoubleList<T>& DoubleList<T>::addNode_front(const T& value)
{
	Node* temp = createNode(value);
	++size;
	if(Head == NULL)
	{
		Head = temp;
		Tail = temp;
	}
	else
	{
		temp -> next = Head;
		Head -> prev = temp;
		Head = temp;
	}
return *this;
}

template<class T>
DoubleList<T>& DoubleList<T>::addNode_back(const T& value)
{
	Node* temp = createNode(value);
	++size;
	if(Head == NULL)
	{
		Head = temp;
		Tail = temp;
	}
	else
	{
		temp -> prev = Tail;
		Tail -> next = temp;
		Tail = temp;
	}
return *this;
}


template<class T>
DoubleList<T>& DoubleList<T>::deleteNode_back()
{
	--size;
	if(Head == NULL)
	{
		std::cerr<<"List is empty\n";
	}
	else
	{
		if(Head -> next == NULL)
		{
			Node* temp= Head;
			Head = NULL;
			Tail = NULL;
			delete temp;
		}
		else
		{
			Node* temp  = Tail;
			Tail = temp -> prev;
			Tail -> next = NULL;
			delete temp;
		}
	}
return *this;
}


template<class T>
DoubleList<T>& DoubleList<T>::deleteNode_front()
{
	--size;
	if(Head == NULL)
	{
		std::cerr<<"List is empty\n";
	}
	else
	{
		if(Head -> next == NULL)
		{
			Node* temp= Head;
			Head = NULL;
			Tail = NULL;
			delete temp;
		}
		else
		{
			Node* temp  = Head;
			Head = temp -> next;
			Head -> prev = NULL;
			delete temp;
		}
	}
return *this;
}

template<class T>
inline std::ostream& operator<<(std::ostream& os, const DoubleList<T> &d)
{
 size_t s = d.size;
//DoubleList<t>::np temp = d.Head;  // check it out later

	d.forwardDisplayList(os);
return os;
}
#endif
