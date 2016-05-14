#include"QueueArray.h"
void print(int []);
int main()
{
	QueueArray<int> q;
	q.Enqueue(1);
	q.Enqueue(2);
	std::cout<<std::unitbuf;   //set the streams internal state to empty buffer at each output operations
	q.Enqueue(3);
	std::cout<<"Here"<<std::endl;
	std::cout<<q<<std::endl;
	q.Dequeue();
	std::cout<<q<<std::endl;
	std::cout<<q.Size()<<" "<< q.Capacity()<<std::endl;
	std::cout<<sizeof(int)<<std::endl;

	std::cout<<std::nounitbuf <<  "Test " << "file" << '\n';
	std::cerr<<"asdasd";
	int a[4] ={1,2,3,4};
	std::cout<<"sassss"<<a[0]<<std::endl;
	print(a);
	std::cout<<"Hello"<<std::endl;
	std::cout<<"sassss"<<a[0]<<std::endl;

return 0;

}



void print(int a[])
{
	a[0]=10;
std::cout<<";;;;;;;;;;;;;;;;;;; "<<a[0]<<std::endl;
}
