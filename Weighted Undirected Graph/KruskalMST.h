/*
 * KruskalMST.h
 *
 *  Created on: Apr 23, 2016
 *      Author: vibhanshu
 */

#ifndef KRUSKALMST_H_
#define KRUSKALMST_H_
#include "QuickUnionPathCompressionUF.h"
#include "EdgeWeightedGraph.h"
#include "Edge.h"
#include <queue>
#include <vector>

class KruskalMST {
private:
	double weight;
	std::vector<Edge> mst;
	public:
	KruskalMST(const EdgeWeightedGraph &);
	virtual ~KruskalMST();
	std::vector<Edge> edges(){ return mst;}
	double Weight(){ return weight;}
};

#endif /* KRUSKALMST_H_ */
