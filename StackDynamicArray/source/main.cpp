#include"StackDynamicArray.h"
#include<iostream>

int main()
{
	Stack<int> s;
	s.push(1).push(2).push(3).push(4);
	s.print(std::cout)<<std::endl;
	s.pop();
	s.print(std::cout)<<std::endl;
	std::cout<<s.peek()<<std::endl;
	if(s.isempty()) std::cout<<"Empty"<<std::endl;
	else std::cout<<"Not Empty"<<std::endl;

return 0;
}
