/*
 * Cycle.h
 *
 *  Created on: Apr 9, 2016
 *      Author: vibhanshu
 */

#ifndef CYCLE_H_
#define CYCLE_H_
#include<vector>
#include"Graph.h"


class Cycle {
private:
	bool *marked;
	std::size_t *edgeTo;
	std::vector<std::size_t> cycle;
	void dfs (const Graph &, int  , const std::size_t & );
	bool hasSelfLoop(const Graph &);
	bool hasParallelEdges(const Graph &);
public:
	Cycle(const Graph &);
	virtual ~Cycle();
	bool hasCycle(){ return !cycle.empty();}
	std::vector<std::size_t> CycleSet(){return cycle;}
};

#endif /* CYCLE_H_ */
