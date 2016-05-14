/*
 * DirectedCycle.cpp
 *
 *  Created on: Apr 15, 2016
 *      Author: vibhanshu
 */

#include "EdgeWeightedDirectedCycle.h"

EdgeWeightedDirectedCycle::EdgeWeightedDirectedCycle(const EdgeWeightedDigraph &D):marked(new bool [D.Vertices()]), onstack(new bool [D.Vertices()]),edgeTo(new DirectedEdge [D.Vertices()])
{
	for(std::size_t v =0; v != D.Vertices() ; ++v)
	{
		if(!marked[v] )
			dfs(D,v);
	}

}

EdgeWeightedDirectedCycle::~EdgeWeightedDirectedCycle() {
delete []marked;
delete []onstack;
delete []edgeTo;
}

void EdgeWeightedDirectedCycle::dfs(const EdgeWeightedDigraph &D, std::size_t v)
{
	marked[v] = true;
	onstack[v] = true;
	for(DirectedEdge e : D.Adj(v))
	{
		std::size_t w = e.to();
		if(!cycle.empty())
			return;

		else if(!marked[w])
		{
			edgeTo[w]=e;
			dfs(D,w);
		}

		else if( onstack[w])
		{
			 while (e.from() != w)
			 {
				 cycle.push_back(e);
				 e = edgeTo[e.from()];
			 }
			 cycle.push_back(e);
			return;
		}
	}
	onstack[v] = false;
}

