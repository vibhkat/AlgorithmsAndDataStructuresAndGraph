/*
 * DepthFirstSearch.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: vibhanshu
 */

#include "DepthFirstSearch.h"

DepthFirstSearch::DepthFirstSearch(const Graph &G, std::size_t s):marked(new bool[G.Vertices()]), count(0){
	dfs(G,s);
};

void DepthFirstSearch::dfs(const Graph &G, std::size_t v)
{
	++count;
	marked[v] = true;
	for(const int &w : G.Adj(v))
	{
		if(!marked[w])
			dfs(G,w);
	}
}



DepthFirstSearch::~DepthFirstSearch() {
 delete [] marked;
}

