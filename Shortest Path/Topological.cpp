/*
 * Topological.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: vibhanshu
 */

#include "Topological.h"

Topological::Topological(const EdgeWeightedDigraph &D):rank(new std::size_t[D.Vertices()]) {
	EdgeWeightedDirectedCycle finder(D);
	if(!finder.hasCycle())
	{
		DepthFirstOrder dfs(D);
		order = dfs.reversePostOrder();
		std::size_t i=0;
		for(std::size_t v : order)
		{
			rank[v]=i++;
		}
	}
}







Topological::~Topological() {
	// TODO Auto-generated destructor stub
}

