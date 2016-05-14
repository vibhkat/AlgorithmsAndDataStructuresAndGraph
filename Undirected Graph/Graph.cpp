/*
 * Graph.cpp
 *
 *  Created on: Apr 5, 2016
 *      Author: vibhanshu
 */

#include "Graph.h"

std::size_t numberOfSelfLoops(const Graph & G)
{
	std::size_t count =0;
	for(std::size_t i = 0; i != G.Vertices(); ++i )
	{
		for (const int &w : G.Adj(i))
		{
			if(i == w) ++count;
		}
	}
	return count/2;  // count/2 because when we are adding in the list we are adding 2 times at v and w, in this case both are same
}



std::ostream& operator<<(std::ostream &os, const Graph &G)
{
	os << G.Vertices()<< " vertices, "<< G.Edges()<<" edges"<<std::endl;
	for(std::size_t i =0 ; i!= G.Vertices(); ++i)
	{
		os << i <<": ";
		for( const int &w : G.Adj(i))
		{
			os<< w << " ";
		}
		os << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream &in, Graph &G)
{
	std::size_t v ,w , vertices, edges;
	in >> vertices >> edges;
	G.V = vertices;
	G.adj = new std::list<int>[vertices];
	for (std::size_t i = 0; i != edges; ++i)
	{
		in >> v >> w;
	    G.addEdge(v, w);
	}
	return in;
}

Graph::Graph(const std::size_t &v):V(v),E(0),adj(new std::list<int>[V])
{
	for(std::size_t i=0; i!= V; ++i)
	{
		adj[i] = std::list<int>();
	}
};

Graph::~Graph()
{
	delete [] adj;
}


Graph& Graph::addEdge(const std::size_t &v, const std::size_t &w)
{	validateVertex(v);
	validateVertex(w);
	++E;
	adj[v].push_front(w);
	adj[w].push_front(v);
	return *this;
}

std::list<int>& Graph::Adj(const std::size_t & v) const
{
	validateVertex(v);
	return adj[v];
}



void Graph::validateVertex(const std::size_t &v) const
{
        if (v < 0 || v >= V)
            throw "Out of Range";
}

std::size_t Graph::degree(const std::size_t  &v) const
{
        validateVertex(v);
        return adj[v].size();
}
