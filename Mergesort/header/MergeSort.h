#ifndef MERGESORT_H
#define MERGESORT_H
#include<vector>
#include<iostream>
template<class T>
class MergeSort{
public:
	MergeSort(std::vector<T> arr):a(arr){a=mergesort(a);}
	std::vector<T> mergesort( std::vector<T> v);
	std::vector<T> merge(std::vector<T> left, std::vector<T> right);
	int print();
private:
	std::vector<T> a;

};

template<class T>
std::vector<T> MergeSort<T>::mergesort( std::vector<T> v)
{
	if((int)v.size()<=1)
	    {
	        return v;
	    }
	    std::vector<T> left, right, result;
	    int middle=((int)v.size()+1)/2;
	    for(int i=0; i!=middle; ++i)
	    {
	        left.push_back(v[i]);
	    }
	    for(int i=middle; i!=(int)v.size(); ++i)
	    {
	        right.push_back(v[i]);
	    }

	    left=mergesort(left);
	    right=mergesort(right);
	    result=merge(left, right);
	    return result;
}

template<class T>
std::vector<T> MergeSort<T>::merge(std::vector<T> left, std::vector<T> right)
{
	std::vector<T> result;
	    while((int)left.size() != 0 || (int)right.size() != 0)
	    {
	        if(left.size()>0 && right.size()>0)
	        {
	            if(left.front()<= right.front())  //stable becuase we only pushing left element in case of equal elements
	            {
	                result.push_back(left.front());
	                left.erase(left.begin());
	            }
	            else
	            {
	                result.push_back(right.front());
	                right.erase(right.begin());
	            }
	        }
	        else if((int)left.size()!=0)
	        {
	            for(int i=0; i!=(int)left.size(); ++i)
	            {
	                result.push_back(left[i]);
	            }
	            break; // break statement because the size of left vector is not changing wrt to what was happening in first if case, so we have to put a break statemet to get out of while loop
	        }
	        else if((int)right.size()!=0)
	        {
	            for(int i=0; i!=(int)right.size(); ++i)
	            {
	                result.push_back(right[i]);
	            }
	        break;
	        }
	    }
	   return result;
}

template<class T>
int MergeSort<T>::print()
{
    for(int i=0; i!=(int)a.size(); ++i)
    {
        std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;
    return 4;
}







#endif
