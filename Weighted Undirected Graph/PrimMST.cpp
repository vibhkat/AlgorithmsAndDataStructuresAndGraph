/*
 * PrimMST.cpp
 *
 *  Created on: Apr 28, 2016
 *      Author: vibhanshu
 */

#include "PrimMST.h"

PrimMST::PrimMST(const EdgeWeightedGraph &G):
length(G.Vertices()),
edgeTo(new Edge[G.Vertices()]()),
distTo(new double[G.Vertices()]()),
marked(new bool[G.Vertices()]()),
pq(IndexMinPQ<double>(G.Vertices()))
{
	for( std::size_t v =0 ; v != G.Vertices() ; ++v)
		distTo[v] = std::numeric_limits<double>::max();
	for (std::size_t v =0; v != G.Vertices() ; ++v)
		if(!marked[v]) prim(G,v);
}

PrimMST::~PrimMST() {
	delete []edgeTo;
	delete []distTo;
	delete []marked;
	//delete pq;
}


void PrimMST::prim(const EdgeWeightedGraph &G, std::size_t s)
{
	distTo[s] = 0.0;
	pq.insert( s , distTo[s]);
	while (!pq.isEmpty())
	{
		int v = pq.delMin();
		scan(G,v);
	}
}

void PrimMST::scan(const EdgeWeightedGraph &G, std::size_t v)
{
	marked[v] = true;
	for (Edge e : G.Adj(v))
	{
		int w = e.other(v);
		if( marked[w]) continue;
		if( e.Weight() < distTo[w])   // when we find a better way to connect to the vertices
		{
			distTo[w] = e.Weight();             // distance to 'w' from the tree
			edgeTo[w] = e;                                // edge that will take that vertices to the tree
			if (pq.contains(w)) pq.decreaseKey( w , distTo[w]);
			else                pq.insert(w,distTo[w]);
		}
	}
}

std::vector<Edge> PrimMST::edges()
{
	std::vector<Edge> mst;
	for (std::size_t v =0 ; v != length ; ++v)
	{
		Edge e = edgeTo[v];
		mst.push_back(e);
	}
	return mst;
}


double PrimMST::Weight()
{
	double weight = 0;
	for (Edge e : edges())
		weight += e.Weight();
	return weight;
}
