#include"QueueList.h"
int main()
{
QueueList<int> q;
q.enqueue(1).enqueue(2).enqueue(3);
q.print(std::cout)<<std::endl;
q.dequeue();
q.print(std::cout)<<std::endl;

return 1;
}
