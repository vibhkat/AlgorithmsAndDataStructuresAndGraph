#include"StackList.h"

int main()
{
StackList<int> s;
s.push(1).push(2).push(3).push(4);
s.print(std::cout)<<std::endl;
	s.pop();
	s.print(std::cout)<<std::endl;
	std::cout<<s.peek()<<std::endl;
		if(s.isEmpty()) std::cout<<"Empty"<<std::endl;
		else std::cout<<"Not Empty"<<std::endl;
int n=119;
		 unsigned char c = n;//= 133;
			std::cout<< c<<std::endl;
}
