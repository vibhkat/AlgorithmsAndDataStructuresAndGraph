#include"MergeSort.h"

int main()
{
	std::vector<int> v{38,27,43,3,9,82,10};
	MergeSort<int> a(v);
	a.print();
	return 0;
}
