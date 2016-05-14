/*
 * KruskalMST.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: vibhanshu
 */

#include "KruskalMST.h"

KruskalMST::KruskalMST(const EdgeWeightedGraph &G) : weight(0) {
	std::priority_queue<Edge> pq; // can store the edges in an array and then do the sorting
	for(Edge e : G.edges())
	{
		pq.push(e);
	}

	QuickUnionPathCompressionUF uf(G.Vertices());	// can also run the dfs but too costly
	while( !pq.empty() && mst.size() < (G.Vertices()-1))
	{
		Edge e = pq.top();
		pq.pop();
		std::size_t v = e.either(), w = e.other(v);
		if( !uf.connected(v,w))
		{
			uf.Union(v,w);
			mst.push_back(e);
			weight += e.Weight();
		}
	}

}

KruskalMST::~KruskalMST() {
	// TODO Auto-generated destructor stub
}

