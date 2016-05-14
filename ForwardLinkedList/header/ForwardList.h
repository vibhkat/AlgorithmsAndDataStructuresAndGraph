#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include<iostream>
template<class T>
class ForwardList{
private:
	int size;
	struct Node{
		T data;
		Node* next;
	};
	Node* Start = NULL;
	Node* createNode(const T& data){
		Node* temp = new Node;
		temp -> data = data;
		temp -> next = NULL;
		return temp;
		};

public:
	ForwardList():size(0){};
	~ForwardList();
	//ForwardList& operator=(const ForwardList&);
	Node* Head(){return Start;};
	const T& topValue(){return Start->data;};
	size_t Size(){return size;};
	std::ostream& displayList(std::ostream& );
	ForwardList& addNode_front(const T& );
	ForwardList& addNode_back(const T& );
	ForwardList& addNode(const T&, const int&);
	ForwardList& deleteNode_front();
	ForwardList& deleteNode_back();
	ForwardList& deleteNode(const int&);
	ForwardList& reverseIterative();
	ForwardList& reverseRecursiveFunction(Node *p );
	ForwardList& reverseRecursive(){return reverseRecursiveFunction(Start);};
	void RunnerTechnique();
};

template<class T>
ForwardList<T>::~ForwardList()
{
while(size>0)
{
	deleteNode_front();
	--size;
	}
}



template<class T>
std::ostream& ForwardList<T>::displayList(std::ostream& os)
{
	Node* ptr = Start;
    while (ptr!=NULL)
    {
        os<<ptr->data<<" ";

        ptr=ptr->next;
    }
    return os;
}
/*
template<class T>
ForwardList<T>& ForwardList<T>::operator=(const ForwadList& rhs)
{
	ForwardList lhs;
	Node* head = rhs.Head();
	while()
return *this;
}
*/
template<class T>
ForwardList<T>& ForwardList<T>::addNode_front(const T& value)
{
    ++size;
	Node* temp = createNode(value);
    if(Start == NULL)
    {
        Start = temp;
    }
    else
    {
        temp -> next=Start;
        Start = temp;
    }
return *this;
}


template<class T>
ForwardList<T>& ForwardList<T>::addNode_back(const T& value)
{
    ++size;
	Node* temp = createNode(value);
    if(Start == NULL)
    {
        Start = temp;
    }
    else
    {
    	Node* temp1 = Start;
    	while(temp1 -> next != NULL)
   	        {
  	           temp1 = temp1 -> next;
   	        }
        temp1 -> next = temp;
    }
    return *this;
}

template<class T>
ForwardList<T>& ForwardList<T>::addNode(const T& value, const int& place)
{
Node* temp = createNode(value);
if(Start == NULL)
    {
	++size;
	std::cerr<<"LIST IS EMPTY. Inserting at first"<<std::endl;
    Start = temp;
    }
else
{
	if(place > size)
	{
	std::cout<<"OUT OF RANGE :putting new node at the end "<<std::endl;
	addNode_back(value);
	}
	else if(place==1)
    {
	std::cout<<"OUT OF RANGE :putting new node at the front "<<std::endl;
	addNode_front(value);
    }
	else
	    {
		++size;
        int count = 1;
	        Node* temp1 = Start;
	        while(temp1 -> next != NULL && count != (place-1))
	        {
	            ++count;
	            temp1=temp1->next;
	        }
	        temp->next = temp1->next;
	        temp1->next = temp;
	    }
}
return *this;
}

template<class T>
ForwardList<T>& ForwardList<T>::deleteNode_front()
{
    if (Start == NULL)
    {
        std::cout<<"LIST is empty"<<std::endl;
    }
    else
    {
    	--size;
        Node* temp = Start;
        if(temp->next==NULL)
        {
            delete temp;
            Start = NULL;
        }
        else
        {
            Start = Start->next;
            delete temp;
        }
    }
	return *this;
}

template<class T>
ForwardList<T>& ForwardList<T>::deleteNode_back()
{
	if (Start == NULL)
	    {
	        std::cout<<"LIST is empty"<<std::endl;
	    }
	    else
	    {
	    	--size;
	        Node* temp1= Start, *temp2;
	        if(temp1->next == NULL)
	        {
	            delete temp1;
	            Start = NULL;
	        }
	        else
	        {
	            while(temp1->next != NULL)
	            {
	                temp2 = temp1;
	                temp1 = temp1->next;
	            }
	            temp2->next = NULL;
	            delete temp1;
	        }
	    }
	return *this;
}

template<class T>
ForwardList<T>& ForwardList<T>::deleteNode(const int& place)
{
	if (Start == NULL)
		    {
		        std::cout<<"LIST is empty"<<std::endl;
		    }
	else
	{
		if(place ==1)
		{
		    deleteNode_front();
		}
		else if(place>=size)
		{
		    deleteNode_back();
		}
		else
		{
			--size;
			int count = 0;
			Node* temp1=Start, *temp2;
			while(temp1->next != NULL && count == (place-1))
			{
				temp1=temp1->next;
				++count;
			}
			temp2=temp1->next;
			temp1->next=temp2->next;
			delete temp2;
		}
	}
return *this;
}

template<class T>
ForwardList<T>& ForwardList<T>::reverseIterative()
{
	Node *prev, *curr, *next;
	curr = Start;
	prev = NULL;
	while(curr != NULL)
	{
		next= curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	Start = prev;
return *this;
}

template<class T>
ForwardList<T>& ForwardList<T>::reverseRecursiveFunction(Node * p )
{
if(p-> next == NULL)
{
Start = p;
return *this;
}
	reverseRecursiveFunction(p->next);
	Node *q = p->next;
	q->next = p;
	p->next = NULL;
	return *this;
}

template<class T>
void ForwardList<T>::RunnerTechnique()
{
	Node *p1 = Start;
	Node *p2 = Start;
	while(p2 -> next -> next != NULL)
	{ if(p2 -> next -> next == NULL) std::cout<<"I am INvincible"<<std::endl;
		p1 = p1 -> next;
		p2 = p2 -> next;
		if(p2 -> next != NULL)
				p2 = p2 -> next;
	}
	//std::cout<<p1-> data<< " "<< p2 -> data<<std::endl;
	p2 =Start;
	//std::cout<<p1-> data<< " "<< p2 -> data<<std::endl;

	while(p1 != NULL)
	{
		//std::cout<<p1-> data<< " "<< p2 -> data<<std::endl;

		Node *temp = p2 -> next;
		p2 -> next = p1;
		p1 = p1 -> next;
		if(p1 != NULL)
		{
			(p2 -> next) -> next = temp;
			p2 =temp;
		}

	}
}

#endif
