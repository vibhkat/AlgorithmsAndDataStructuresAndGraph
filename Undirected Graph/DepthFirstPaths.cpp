/*
 * DepthFirstPaths.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: vibhanshu
 */

#include "DepthFirstPaths.h"

DepthFirstPaths::DepthFirstPaths( const Graph &G, std::size_t S):marked(new bool[G.Vertices()]),edgeTo(new std::size_t[G.Vertices()]), s(S)
{
	dfs(G,s);

}
void DepthFirstPaths::dfs(const Graph &G, std::size_t v)
{
	marked[v] = true;
	for(const int &w : G.Adj(v))
	{
		if(!marked[w])
		{	edgeTo[w] = v;
			dfs(G,w);
		}
	}
}

bool DepthFirstPaths::hasPathTo(const std::size_t &v)
{
	return marked[v];
}

std::vector<int> DepthFirstPaths::pathTo(const std::size_t &v)
{
	if(!hasPathTo(v)) throw "No Path";
	std::stack<int> path;
	std::vector<int> p;
	for(std::size_t x = v; x != s; x = edgeTo[x])
	{
		path.push(x);
	}
	path.push(s);
	while(!path.empty())
	{
		p.push_back(path.top());
		path.pop();
	}

	return p;
}




DepthFirstPaths::~DepthFirstPaths()
{
	delete [] marked;
	delete [] edgeTo;
}

