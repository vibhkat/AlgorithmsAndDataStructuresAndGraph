/*
 * Cycle.cpp
 *
 *  Created on: Apr 9, 2016
 *      Author: vibhanshu
 */

#include "Cycle.h"

Cycle::Cycle(const Graph &G):marked(new bool [G.Vertices()]()),edgeTo(new std::size_t[G.Vertices()])
{
	if (hasSelfLoop(G)) return;
	if (hasParallelEdges(G)) return;
	for(std::size_t v = 0 ; v != G.Vertices(); ++v)
	{
		if(!marked[v])
		{
			dfs(G, -1 , v);
		}
	}

}


bool Cycle::hasSelfLoop(const Graph &G)
{
	for(std::size_t v = 0; v != G.Vertices(); ++v)
	{
		for(const size_t &w : G.Adj(v))
		{
			if( w == v)
			{
				cycle = {v,v};
				return true ;
			}
		}

	}
	return false;
}

bool Cycle::hasParallelEdges(const Graph &G)
{
	for(std::size_t v =0 ; v != G.Vertices(); ++v)
	{
		for(const size_t &w : G.Adj(v))
		{
			if(marked[w])
			{
				cycle = {v,w,v};
				return true;
			}

			marked[w] = true;
		}
		// we have to mark them false in case no parallel edges.
		for (const std::size_t &w : G.Adj(v))
		{
			marked[w] = false;
		}
	}
	return false;
}


//we need to send  the parent too just to make sure there is no parallel loop
void Cycle::dfs (const Graph &G,  int u , const std::size_t &v )
{
	marked[v] = true;
	for(const std::size_t &w: G.Adj(v))
	{
		if (!cycle.empty()) return;  // for getting all cycles we can remove this

		if(!marked[w])
		{
			edgeTo[w] = v;
			dfs(G, v , w);
		}
		else if( u != (int)w) // need to do it just in case going back to parent which is marked
		{
			for (std::size_t x = v; x != w ; x = edgeTo[x])
			{
				cycle.push_back(x);
			}
			cycle.push_back(w);
			cycle.push_back(v); // for getting all cycles here we will push in a double vector
		}
	}
	// here we will put marked[v] = false  but we will also get seen cycle in reverse order too.
}














Cycle::~Cycle() {
	// TODO Auto-generated destructor stub
}

