/*
 * Bipartite.cpp
 *
 *  Created on: Apr 9, 2016
 *      Author: vibhanshu
 */

#include "Bipartite.h"


Bipartite::Bipartite(const Graph &G): marked(new bool[G.Vertices()]), color(new bool[G.Vertices()]),edgeTo(new std::size_t[G.Vertices()]),
isBipartite(true),cycle()
{
	for (std::size_t v = 0; v != G.Vertices(); ++v )
	{
		if(!marked[v])
			dfs(G , v);
		assert(check(G));
	}
}

void Bipartite::dfs(const Graph &G, const std::size_t &v)
{
	marked[v] = true;
	for (const std::size_t &w : G.Adj(v))
	{
		if(!cycle.empty())
			return;

		if(!marked[v])
		{
			edgeTo[w] = v;
			color[w] = !color[v];
			dfs( G , w);
		}

		else if(color[w] == color[v])
		{
			isBipartite = false;
			cycle.push_back(w);
			for (std::size_t x = v; x != w ; x = edgeTo[x])
			{
				cycle.push_back(x);
			}
			cycle.push_back(w);
		}
	}
}

bool Bipartite::Color(const std::size_t &v)
{
	if(!isBipartite)
		throw "Graph is not Bipartite";
	return color[v];
}

bool Bipartite::check(const Graph &G)
{
	if(isBipartite)
	{
		for(std::size_t v = 0; v != G.Vertices() ; ++v)
		{
			for (std::size_t w : G.Adj(v))
			{
				if (color[v] == color[w])
				{
					std::cout<<"Edge "<< v <<"and "<< w <<"on the same side of bipartition"<<std::endl;
					return false;
				}
			}
		}
	}
	else
	{
		if(cycle[0] != cycle[cycle.size() - 1])
		{
			std::cout<< "cycle begins with "<<cycle[0]<<" and ends with "<<cycle[cycle.size() - 1];
			return false;
		}
	}

	return true;
}




Bipartite::~Bipartite() {
	 delete [] marked;
	 delete [] color;
	 delete [] edgeTo;
}

