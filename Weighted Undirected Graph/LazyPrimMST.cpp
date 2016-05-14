/*
 * LazyPrimMST.cpp
 *
 *  Created on: Apr 24, 2016
 *      Author: vibhanshu
 */

#include "LazyPrimMST.h"

LazyPrimMST::LazyPrimMST(const EdgeWeightedGraph &G):marked (new bool [G.Vertices()]()),weight(0)
{
	for(std::size_t v = 0 ; v!= G.Vertices(); ++v)
	{
		if(!marked[v])
			prim(G,v);
	}

}


void LazyPrimMST::prim(const EdgeWeightedGraph &G , std::size_t s)
{
	visit(G,s);
	while(!pq.empty())
	{
		Edge e = pq.top();
		pq.pop();
		std::size_t v = e.either() , w = e.other(v);
		assert ( marked[v] || marked[w]);
		if( marked[v] && marked[w]) continue; // means we already found a optimum way, then no need to look into it.
		mst.push_back(e);
		weight += e.Weight();
		if(!marked[v]) visit(G,v);
		if(!marked[w]) visit(G,w);
	}
}


LazyPrimMST::~LazyPrimMST() {
delete []marked;}

void LazyPrimMST::visit(const EdgeWeightedGraph &G , std::size_t v )
{
	assert (!marked[v]);
	marked[v] = true;
	for( Edge e : G.Adj(v))
	{
		if(!marked[e.other(v)] )
			pq.push(e);
	}

}
