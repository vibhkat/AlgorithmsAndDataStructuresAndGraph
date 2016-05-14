/*
 * BreadthFirstPaths.cpp
 *
 *  Created on: Apr 7, 2016
 *      Author: vibhanshu
 */

#include "BreadthFirstPaths.h"

BreadthFirstPaths::BreadthFirstPaths(const Graph &G, const std::size_t &s):marked(new bool[G.Vertices()]),edgeTo(new std::size_t[G.Vertices()]),
distTo(new std::size_t[G.Vertices()])
{
	bfs(G, s);
}

void BreadthFirstPaths::bfs(const Graph &G, const std::size_t &s)
{
	std::queue<std::size_t> q;
	distTo[s] = 0;
	marked[s] = true;
	q.push(s);
	while(!q.empty())
	{
		std::size_t v = q.front();
		q.pop();
		for ( int w: G.Adj(v) )
		{
			if(!marked[w])
			{
				edgeTo[w] = v;
				distTo[w] = distTo[v]+1;
				marked[w] = true;
				q.push(w);
			}
		}
	}
}

void BreadthFirstPaths::bfs(const Graph &G, const std::vector<std::size_t> &sources)
{
	std::queue<std::size_t> q;
	for(const std::size_t &s : sources)
	{
		distTo[s] = 0;
		marked[s] = true;
		q.push(s);
	}
	while(!q.empty())
	{
		std::size_t v = q.front();
		q.pop();
		for ( int w: G.Adj(v) )
		{
			if(!marked[w])
			{
				edgeTo[w] = v;
				distTo[w] = distTo[v]+1;
				marked[w] = true;
				q.push(w);
			}
		}
	}
}

std::vector<int> BreadthFirstPaths::pathTo(const std::size_t &v)
{
	if(!hasPathTo(v)) return {};
	std::stack<int> path;
	std::vector<int> p;
	std::size_t x;
	for(x = v; distTo[x] != 0; x = edgeTo[x])// using distTo[x] because we did not store the source in the class.
	{
		path.push(x);
	}
	path.push(x);
	while(!path.empty())
	{
		p.push_back(path.top());
		path.pop();
	}

	return p;
}




BreadthFirstPaths::~BreadthFirstPaths() {
	// TODO Auto-generated destructor stub
}

