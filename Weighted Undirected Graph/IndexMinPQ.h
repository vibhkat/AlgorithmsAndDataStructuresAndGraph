/*
 * IndexMinPQ.h
 *
 *  Created on: Apr 27, 2016
 *      Author: vibhanshu
 */

#ifndef INDEXMINPQ_H_
#define INDEXMINPQ_H_
#include<cassert>
#include<iostream>
template < class Key>
class IndexMinPQ {
	int maxN;
	int N;
	int *pq;
	int *qp;
	Key *keys;


	bool greater(int i, int j){
        return keys[pq[i]] > keys[pq[j]];
    }


	void exch(int i, int j){
        int swap = pq[i];
        pq[i] = pq[j];
        pq[j] = swap;
        qp[pq[i]] = i;
        qp[pq[j]] = j;
    }

	void swim(int k){
		while (k > 1 && greater(k/2, k)) {
			exch(k, k/2);
			k = k/2;
	    }
	}


	void sink(int k){
        while (2*k <= N) {
            int j = 2*k;
            if (j < N && greater(j, j+1)) j++;
            if (!greater(k, j)) break;
            exch(k, j);
            k = j;
        }
    }



public:

	IndexMinPQ( const int MaxN =0):maxN(MaxN),N(0), pq( new int[MaxN+1]()),qp(new int[MaxN+1]()),keys(new Key[MaxN+1]())
	{
				for (std::size_t i = 0; i <= maxN; ++i)
					qp[i] = -1;
	}


	IndexMinPQ( const IndexMinPQ &rhs):	maxN(rhs.maxN),N (rhs.N),pq(rhs.pq),qp(rhs.qp),keys(rhs.keys){}


	IndexMinPQ& operator=(const IndexMinPQ &rhs){
		maxN = rhs.maxN;
		N = rhs.N;
		pq = rhs.pq;
		qp = rhs.qp;
		keys = rhs.keys;
		return *this;
	}

	bool isEmpty()const {
		return N == 0;
	}


	bool contains(int i) {
		if( i<0 || i >=maxN) throw "Index out of bound";
		return  qp[i]!= -1;
	}

	int size()const {
		return N;
	}


	void insert(int i, Key key){
		if (i < 0 || i >= maxN) throw "Index out of bound";
		if (contains(i)) throw "**index is already in the priority queue";
		N++;
		qp[i] = N;
		pq[N] = i;
		keys[i] = key;
		swim(N);
	}


	int minIndex() const
	{
		if (N==0) throw " Priority queue underflow";
		return pq[1];
	}


	Key minKey()const
	{
		if (N==0) throw " Priority queue underflow";
		return keys[pq[1]];
	}

	int delMin()
	{
		if (N==0) throw " Priority queue underflow";
		int min = pq[1];
		exch(1, N--);
		sink(1);
		assert (min == pq[N+1]);
		qp[min] = -1;        // delete
		keys[min] = NULL;    // to help with garbage collection
		pq[N+1] = -1;        // not needed
		return min;
	}


	Key keyOf(int i)
	{
		if (i < 0 || i >= maxN) throw "Index out of bound";
		if (!contains(i)) throw "INdex is not in the priority queue";
	    else return keys[i];

	}


	void changeKey(int i, Key key)
	{
		if (i < 0 || i >= maxN) throw "Index out of bound";
			if (!contains(i)) throw "INdex is not in the priority queue";
		    keys[i] = key;
		    swim(qp[i]);
		    sink(qp[i]);

	}

	void change(int i , Key key){ changeKey(i , key);}


	void decreaseKey(int i, Key key)
	{
		if (i < 0 || i >= maxN) throw "Index out of bound";
		if (!contains(i)) throw "INdex is not in the priority queue";
		if( keys[i] <= key) throw "Calling decreaseKey() with given argument would not strictly decrease the key";
		keys[i] = key;
		swim(qp[i]);
	}


	void increaseKey(int i, Key key)
		{
			if (i < 0 || i >= maxN) throw "Index out of bound";
			if (!contains(i)) throw "INdex is not in the priority queue";
			if( keys[i] >= key) throw "Calling decreaseKey() with given argument would not strictly increase the key";
			keys[i] = key;
			sink(qp[i]);
		}


	void Delete(int i)
	{
		if (i < 0 || i >= maxN) throw "Index out of bound";
		if (!contains(i)) throw " * INdex is not in the priority queue";
		int index = qp[i];
		exch(index, N--);
		swim(index);
		sink(index);
		keys[i] = NULL;
		qp[i] = -1;

	}



};

#endif /* INDEXMINPQ_H_ */
