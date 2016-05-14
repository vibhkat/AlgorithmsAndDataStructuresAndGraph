/*
 * Topological.h
 *
 *  Created on: Apr 17, 2016
 *      Author: vibhanshu
 */

#ifndef TOPOLOGICAL_H_
#define TOPOLOGICAL_H_
#include "DepthFirstOrder.h"
#include "EdgeWeightedDirectedCycle.h"
#include "EdgeWeightedDigraph.h"
class Topological {
	std::vector<std::size_t> order;
	std::size_t *rank;
public:
	Topological(const EdgeWeightedDigraph & );
	virtual ~Topological();
	std::vector<std::size_t> Order(){ return order;}
	bool hasOrder(){return !order.empty();}
	int Rank(std::size_t v){
		if(hasOrder()) return rank[v];
		else return -1;
	}
};

#endif /* TOPOLOGICAL_H_ */
