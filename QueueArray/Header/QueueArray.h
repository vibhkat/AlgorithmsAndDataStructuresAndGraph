#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H
#include<iostream>
#include<cstdlib>
#include<stdlib.h>
template<class T> class QueueArray;
template<class T> std::ostream& operator<<(std::ostream& , const QueueArray<T> &);

template<class T>
class QueueArray{
	friend std::ostream& operator<< <>(std::ostream& os, const QueueArray<T> &);

private:
	size_t size;
	int front;
	int rear;
	T* elements;
	T* cap;
	void free();
	void reallocate();
	void check_n_alloc(){if(size >= Capacity())	reallocate();}

public:
	QueueArray():size(-1),front(-1), rear(-1), elements(NULL), cap(NULL){};
	~QueueArray(){ free();};
	std::size_t Capacity() const {return cap - elements;}
	std::size_t Size() const{ return size+1; }
	QueueArray& Enqueue(const T& );
	QueueArray& Dequeue();
	const T& top(){return elements[front];}
	int Front(){return front;}
	int Rear(){return rear;}
	T* Elements(){return elements;}
};


template<class T>
void QueueArray<T>::free()
{
	if(elements)
		delete []elements;
}

template<class T>
void QueueArray<T>::reallocate()
{
int newcapacity = size ? 2*size:1;
T* newdata = new T[newcapacity]();
T* dest = newdata;
T* elem = elements;
int count=size;
int tail = -1;
while(count !=0)
{
--count;
*dest++ = elem[front];
++tail;
front = (front + 1) % Capacity();
}
free();
elements = newdata;
rear = tail;
front = 0;
cap = elements + newcapacity;
}

template<class T>
QueueArray<T>& QueueArray<T>::Enqueue(const T& data)
{
	++size;
check_n_alloc();
if( front == -1 && rear == -1)
	front = rear = 0;
else
	rear = (rear+1)% Capacity();
elements[rear] = data;
return *this;
}

template<class T>
QueueArray<T>& QueueArray<T>:: Dequeue()
{--size;
	if( front == -1 && rear == -1)
		std::cout<<"Queue Is Empty";
	else if(front == rear)
		front = rear = -1;
	else
		front = (front+1) % Capacity();
return *this;
}


template<class T>
inline std::ostream& operator<<(std::ostream& os, const QueueArray<T> &d)
{
	int Front = d.front;
	while(Front != ((int)d.rear + 1))
	{
		os<<d.elements[Front]<<" ";
		Front = (Front + 1) % d.Capacity();
	}
return os;
}



#endif
