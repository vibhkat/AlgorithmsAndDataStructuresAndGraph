/*
 * DijkstraSP.h
 *
 *  Created on: Apr 30, 2016
 *      Author: vibhanshu
 */

#ifndef DIJKSTRASP_H_
#define DIJKSTRASP_H_
#include "IndexMinPQ.h"
#include "DirectedEdge.h"
#include "EdgeWeightedDigraph.h"
#include <vector>
#include <limits>
#include <stack>

class DijkstraSP {
private:
	double *distTo;
	DirectedEdge *edgeTo;
	IndexMinPQ<double> pq;
	void relax (DirectedEdge );
public:
	DijkstraSP(const EdgeWeightedDigraph &, std::size_t );
	virtual ~DijkstraSP();
	double DistTo(std::size_t v){ return distTo[v];}
	bool hasPathTo(std::size_t v){ return distTo[v] < std::numeric_limits<double>::max();}
	std::vector<DirectedEdge> pathTo(std::size_t );
};

#endif /* DIJKSTRASP_H_ */
