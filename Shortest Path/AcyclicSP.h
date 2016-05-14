/*
 * AcyclicSP.h
 *
 *  Created on: May 1, 2016
 *      Author: vibhanshu
 */

#ifndef ACYCLICSP_H_
#define ACYCLICSP_H_
#include "Topological.h"
#include <limits>
#include<stack>


class AcyclicSP {
private:
	double *distTo;
	DirectedEdge *edgeTo;
	void relax(DirectedEdge );

public:
	AcyclicSP(const EdgeWeightedDigraph & , std::size_t);
	virtual ~AcyclicSP();
	double DistTo(std::size_t v){ return distTo[v];}
	bool hasPathTo(std::size_t v){ return distTo[v] < std::numeric_limits<double>::max();}
	std::vector<DirectedEdge> pathTo(std::size_t v);
	std::vector<DirectedEdge> pathTo(std::size_t , std::size_t );

};

#endif /* ACYCLICSP_H_ */
