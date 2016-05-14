#ifndef QUEUELIST_H
#define QUEUELIST_H
#include"DoubleList.h"

template<class T>
class QueueList: private DoubleList<T>{

public:
	QueueList():DoubleList<T>::DoubleList(){};
	QueueList& enqueue(const T& data){DoubleList<T>::addNode_back(data); return *this;};
	QueueList& dequeue(){ DoubleList<T>::deleteNode_front(); return *this;}
	const T& peek(){return DoubleList<T>::topValue();}
	std::ostream& print(std::ostream& os){ return DoubleList<T>::forwardDisplayList(os);}
	size_t Size(){return DoubleList<T>::Size();}
	bool isEmpty(){	if(DoubleList<T>::Head() == DoubleList<T>::Tail == NULL) return true; return false;}
};



#endif
