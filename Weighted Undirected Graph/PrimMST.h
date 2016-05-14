/*
 * PrimMST.h
 *
 *  Created on: Apr 28, 2016
 *      Author: vibhanshu
 */

#ifndef PRIMMST_H_
#define PRIMMST_H_
#include "IndexMinPQ.h"
#include "Edge.h"
#include "EdgeWeightedGraph.h"
#include<vector>
#include <limits>
class PrimMST {
private:
	std::size_t length;
	Edge *edgeTo;
	double *distTo;
	bool *marked;  //use onTree
	IndexMinPQ<double> pq;
	void prim(const EdgeWeightedGraph &G, std::size_t s);
	void scan(const EdgeWeightedGraph &G, std::size_t v);

public:
	PrimMST(const EdgeWeightedGraph &);
	virtual ~PrimMST();
	std::vector<Edge> edges();
	double Weight();



};

#endif /* PRIMMST_H_ */
