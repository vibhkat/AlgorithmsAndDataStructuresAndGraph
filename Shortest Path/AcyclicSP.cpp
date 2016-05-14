/*
 * AcyclicSP.cpp
 *
 *  Created on: May 1, 2016
 *      Author: vibhanshu
 */

#include "AcyclicSP.h"

AcyclicSP::AcyclicSP(const EdgeWeightedDigraph &G, std::size_t s):distTo(new double [G.Vertices()]), edgeTo(new DirectedEdge[G.Vertices()])
{
	for(std::size_t v =0 ; v != G.Vertices() ; ++v)
	{
		distTo[v] = std::numeric_limits<double>::max(); // for longest path we will have min value over here and make changes in inequality of rela function
	}
	distTo[s] = 0.0;
	Topological topological(G);
	if(!topological.hasOrder())  throw "Digraph is not acyclic";
	for(auto v : topological.Order())
	{
		for(DirectedEdge e: G.Adj(v))
			relax(e);
	}

}

AcyclicSP::~AcyclicSP() {
delete []distTo;
delete []edgeTo;
}

void AcyclicSP::relax(DirectedEdge e)
{
	std::size_t v = e.from() , w = e.to();
	if (distTo[w] > distTo[v] + e.Weight())   // for longest path the inequality is less than
	{
		distTo[w] = distTo[v] + e.Weight();
		edgeTo[w] = e;
	}

}


std::vector<DirectedEdge> AcyclicSP::pathTo(std::size_t v)
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


std::vector<DirectedEdge> AcyclicSP::pathTo(std::size_t s, std::size_t t)
{
	std::size_t v_end = distTo[s] < distTo[t] ? t:s;
	std::size_t v_start = distTo[s] < distTo[t] ? s:t;

	std::stack<DirectedEdge> path;
	std::vector<DirectedEdge> p;
	DirectedEdge e;
	for( e = edgeTo[v_end] ; e.from() != v_start; e = edgeTo[e.from()])
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


