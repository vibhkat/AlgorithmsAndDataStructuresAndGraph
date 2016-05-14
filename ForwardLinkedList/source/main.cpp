#include"ForwardList.h"
int main()
{
	ForwardList<int> l;
	std::cout<<l.Size()<<std::endl;
	l.addNode_front(1).addNode_front(2);
	l.displayList(std::cout)<<std::endl;
	std::cout<<l.Size()<<std::endl;
	l.addNode(10,1);
	l.addNode(20,2);
	l.displayList(std::cout)<<std::endl;
	std::cout<<l.Size()<<std::endl;
	l.deleteNode(2);
	l.displayList(std::cout)<<std::endl;
	std::cout<<l.Size()<<std::endl;
	l.reverseRecursive().displayList(std::cout)<<std::endl;;
	std::cout<<"++++++++++++++++++++\n";
	ForwardList<int> a;
	a.addNode_back(1).addNode_back(2).addNode_back(3).addNode_back(4).addNode_back(5).addNode_back(6).addNode_back(7).addNode_back(8	);
	a.displayList(std::cout)<<std::endl;
	a.RunnerTechnique();
	a.displayList(std::cout)<<std::endl;


return 0;
}
