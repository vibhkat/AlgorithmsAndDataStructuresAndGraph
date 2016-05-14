/*
 * EdgeWeightedDigraph.h
 *
 *  Created on: Apr 26, 2016
 *      Author: vibhanshu
 */

#ifndef EDGEWEIGHTEDDIGRAPH_H_
#define EDGEWEIGHTEDDIGRAPH_H_
#include "DirectedEdge.h"
#include <iostream>
#include <list>
#include<fstream>


class EdgeWeightedDigraph {
	friend std::istream& operator>>(std::istream &, EdgeWeightedDigraph&);
	friend std::ostream& operator<<(std::ostream &, const EdgeWeightedDigraph&);
private:
	std::size_t V;
	std::size_t E;
	std::list<DirectedEdge> *adj;
	std::size_t *indegree;
	void validateVertex(const std::size_t &) const;
public:
	EdgeWeightedDigraph(const std::size_t &v = 0);
	virtual ~EdgeWeightedDigraph();
	EdgeWeightedDigraph& addEdge(const DirectedEdge &) ;
	std::list<DirectedEdge>& Adj(const std::size_t &) const;
	std::size_t Vertices()const  {return V;}
	std::size_t Edges()const {return E;}
	std::size_t Outdegree(const std::size_t &v){return adj[v].size();}
	std::size_t Indegree(const std::size_t & v){return indegree[v];}
	std::list<DirectedEdge> edges() const;


};



#endif /* EDGEWEIGHTEDDIGRAPH_H_ */
