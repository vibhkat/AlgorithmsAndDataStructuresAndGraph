#ifndef STACKDYNAMICARRAY_H
#define STACKDYNAMICARRAY_H
#include<iostream>
#include<cstdlib>
//template<class T>
//class Stack;

template<class T>
class Stack{
	private:
	T *elements;
	T* cap;
	T* first_free;
	void free();
	void reallocate();
	void check_n_alloc(){if(Size() == Capacity() || Size() == Capacity()/4) reallocate(); }
public:
	Stack():elements(NULL), cap(NULL), first_free(NULL){};
	~Stack(){free();}
	std::size_t Capacity() const {return cap - elements;}
	std::size_t Size() const {return first_free - elements;}
	T* begin() const {return elements;}
	T* end() const { return first_free;}
	Stack& push(const T&);
	T pop();
	std::ostream& print(std::ostream& );
	T peek();
	bool isempty();
	const T& operator[](std::size_t n)const {return elements[n];}
	T min();
	Stack& minimumPush(const T&);
	T& operator[](std::size_t n){return elements[n];};
};


template<class T>
void Stack<T>::free()
{
	if(elements)
		delete [](elements);
	}




template<class T>
void Stack<T>::reallocate()
{
std::size_t newcapacity = Size() ? 2*Size():1;
T* newdata = new T[newcapacity]();
T* dest = newdata;
T* elem = elements;
for(int i=0 ; i!= Size() ; ++i)
{
	*dest++ = *elem++;
}
free();
elements = newdata;
first_free = dest;
cap = elements + newcapacity;
}

template<class T>
Stack<T>& Stack<T>::push(const T& data)
{
	check_n_alloc();
	*first_free++=data;
	return *this;
}

template<class T>
std::ostream& Stack<T>::print(std::ostream& os)
{
for( T* i= begin(); i!= end(); ++i)
	os<<*i<<" ";
return os;
}

template<class T>
T Stack<T>::pop()
{
	T temp= *(--first_free);
	check_n_alloc();
	return temp;
	}

template<class T>
T Stack<T>::peek()
{
 return *(first_free-1);
}

template<class T>
bool Stack<T>::isempty()
{
if (elements == first_free)
	return true;
return false;
}
#endif
