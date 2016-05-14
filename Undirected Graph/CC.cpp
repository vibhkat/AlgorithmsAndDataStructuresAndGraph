/*
 * CC.cpp
 *
 *  Created on: Apr 7, 2016
 *      Author: vibhanshu
 */

#include "CC.h"

CC::CC(const Graph &G):marked(new bool [G.Vertices()]), id(new std::size_t [G.Vertices()]), size(new std::size_t [G.Vertices()]),count(0)
{
	for(std::size_t v =0 ; v != G.Vertices() ; ++v)
	{
		if(!marked[v])
		{
			dfs(G,v);
			++count;
		}
	}
}


void CC::dfs(const Graph &G, std::size_t v)
{
		marked[v] = true;
		id[v] = count;
		++size[count];
		for(const int &w : G.Adj(v))
		{
			if(!marked[w])
			{
				dfs(G,w);
			}
		}
}





CC::~CC() {
delete []marked;
delete []id;
delete []size;
}

