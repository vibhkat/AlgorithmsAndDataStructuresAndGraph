/*
 * DijkstraSP.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: vibhanshu
 */

#include "DijkstraSP.h"

DijkstraSP::DijkstraSP(const EdgeWeightedDigraph &G, std::size_t s):distTo(new double[G.Vertices()]), edgeTo(new DirectedEdge [G.Vertices()]),
pq( IndexMinPQ<double> (G.Vertices()))
{
	for (DirectedEdge e : G.edges())
	{
		if (e.Weight() < 0)
			throw "edge has negative weight";
	}
	for (std::size_t v =0 ; v != G.Vertices(); ++v)
		distTo[v] = std::numeric_limits<double>::max();
	distTo[s] = 0.0;
	pq.insert(s, distTo[s]);
	while(!pq.isEmpty())
	{
		std::size_t v = pq.delMin();  // for shortest path between 's' and 't' we will put if(v == t) break;
		for(DirectedEdge e : G.Adj(v))
			relax(e);    // for undirected graph  relax(e, v);
	}


}

DijkstraSP::~DijkstraSP() {
delete []distTo;
delete []edgeTo;
}


void DijkstraSP::relax(DirectedEdge e)   // for undirected graph void DijkstraSP::relax(DirectedEdge e, int v)
{
	std::size_t v = e.from(), w = e.to(); // Here for undirected graph int w = e.other(v);
	if (distTo[w] > distTo[v] + e.Weight())
	{
		distTo[w] = distTo[v] + e.Weight();
		edgeTo[w] = e;
		if (pq.contains(w)) pq.decreaseKey(w, distTo[w]);
		else                pq.insert(w, distTo[w]);
	}
}


std::vector<DirectedEdge> DijkstraSP::pathTo(std::size_t v)
{
	std::stack<DirectedEdge> path;
		std::vector<DirectedEdge> p;
		DirectedEdge e;
		for( e = edgeTo[v] ; distTo[e.from()] != 0; e = edgeTo[e.from()])
		{
			path.push(e);
		}
		path.push(e);
		while(!path.empty())
		{
			p.push_back(path.top());
			path.pop();
		}

		return p;

}


