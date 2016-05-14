/*
 * EdgeWeightedGraph.h
 *
 *  Created on: Apr 19, 2016
 *      Author: vibhanshu
 */

#ifndef EDGEWEIGHTEDGRAPH_H_
#define EDGEWEIGHTEDGRAPH_H_
#include "Edge.h"
#include<list>
class EdgeWeightedGraph {
friend std::istream& operator>>(std::istream &, EdgeWeightedGraph&);
friend std::ostream& operator<<(std::ostream &, const EdgeWeightedGraph&);

private:
	std::size_t V;
	std::size_t E;
	std::list<Edge> *adj;
	void validateVertex(const std::size_t &) const;
public:
	EdgeWeightedGraph(const std::size_t &v = 0);
	virtual ~EdgeWeightedGraph();
	EdgeWeightedGraph& addEdge(const Edge &);
	std::list<Edge>& Adj (const std::size_t &) const;
	std::size_t degree(const std::size_t  &) const;
	std::size_t Vertices()const  {return V;}
	std::size_t Edges()const {return E;}
	std::list<Edge> edges() const;
};

#endif /* EDGEWEIGHTEDGRAPH_H_ */
