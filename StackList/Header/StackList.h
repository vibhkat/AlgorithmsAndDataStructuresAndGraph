#ifndef STACKLIST_H
#define STACKLIST_H
#include"ForwardList.h"
#include<iostream>

template<class T>
class StackList: private ForwardList<T>{
public:
	StackList():ForwardList<T>::ForwardList(){};
	StackList& push(const T& data){ForwardList<T>::addNode_front(data); return *this;};
	StackList& pop(){ ForwardList<T>::deleteNode_front(); return *this;}
	const T& peek(){return ForwardList<T>::topValue();}
	bool isEmpty(){	if(ForwardList<T>::Head() == NULL) return true; return false;}
	std::ostream& print(std::ostream& os){ return ForwardList<T>::displayList(os);};
	//std::ostream& operator<<(std::ostream& os, StackList& s){return ForwardList<T>::displayList(os);}
};
#endif
