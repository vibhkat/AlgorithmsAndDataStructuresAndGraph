/*
 * DirectedCycle.h
 *
 *  Created on: Apr 15, 2016
 *      Author: vibhanshu
 */

#ifndef EDGEWEIGHTEDDIRECTEDCYCLE_H_
#define EDGEWEIGHTEDDIRECTEDCYCLE_H_
#include<stack>
#include<vector>
#include"EdgeWeightedDigraph.h"
#include<cassert>
#include<algorithm>
class EdgeWeightedDirectedCycle {
private:
	bool *marked;
	bool *onstack;
	DirectedEdge *edgeTo;
	std::vector<DirectedEdge> cycle;
	void dfs(const EdgeWeightedDigraph &, std::size_t s);
public:
	EdgeWeightedDirectedCycle(const EdgeWeightedDigraph &);
	virtual ~EdgeWeightedDirectedCycle();
	bool hasCycle(){return !cycle.empty();}
	std::vector<DirectedEdge> Cycle(){return cycle;}

};

#endif /* DIRECTEDCYCLE_H_ */
