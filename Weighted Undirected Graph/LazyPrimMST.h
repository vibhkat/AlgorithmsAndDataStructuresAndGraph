/*
  * LazyPrimMST.h
 *
 *  Created on: Apr 24, 2016
 *      Author: vibhanshu
 */

#ifndef LAZYPRIMMST_H_
#define LAZYPRIMMST_H_
#include "EdgeWeightedGraph.h"
#include "Edge.h"
#include <queue>
#include <cassert>
class LazyPrimMST {
private:
	bool *marked;// name it onMST
	std::priority_queue<Edge> pq;
	std::vector<Edge> mst;
	double weight;
	void visit(const EdgeWeightedGraph & , std::size_t );
	void prim(const EdgeWeightedGraph & , std::size_t );

public:
	LazyPrimMST(const EdgeWeightedGraph &);
	virtual ~LazyPrimMST();
	std::vector<Edge> MST(){return mst;}
	double Weight(){return weight;}
};

#endif /* LAZYPRIMMST_H_ */
