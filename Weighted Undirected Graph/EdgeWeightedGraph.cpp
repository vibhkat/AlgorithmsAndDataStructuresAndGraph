/*
 * EdgeWeightedGraph.cpp
 *
 *  Created on: Apr 19, 2016
 *      Author: vibhanshu
 */

#include "EdgeWeightedGraph.h"

EdgeWeightedGraph::EdgeWeightedGraph(const std::size_t &v) :V(v),E(0),adj(new std::list<Edge>[V])
{
	for(std::size_t i=0; i!= V; ++i)
	{
		adj[i] = std::list<Edge>();
	}
};

EdgeWeightedGraph::~EdgeWeightedGraph() {
 delete []adj;}

void EdgeWeightedGraph::validateVertex(const std::size_t &v) const
{
        if (v < 0 || v >= V)
            throw "Out of Range";
}

std::istream& operator>>(std::istream &in, EdgeWeightedGraph &G)
{
	std::size_t v ,w , vertices, edges;
	double wt;
	in >> vertices >> edges;
	G.V = vertices;
	G.adj = new std::list<Edge>[vertices];
	for (std::size_t i = 0; i != edges; ++i)
	{
		in >> v >> w >>wt;
		G.addEdge({v, w, wt});
	}
	return in;
}



EdgeWeightedGraph& EdgeWeightedGraph::addEdge(const Edge &e)
{
	std::size_t v = e.either();
	std::size_t w = e.other(v);
	validateVertex(v);
	validateVertex(w);
	adj[v].push_front(e);
	adj[w].push_front(e);
	E++;
return *this;
}


std::list<Edge>& EdgeWeightedGraph::Adj(const std::size_t & v) const
{
	validateVertex(v);
	return adj[v];
}

std::size_t EdgeWeightedGraph::degree(const std::size_t  &v) const
{
        validateVertex(v);
        return adj[v].size();
}


std::ostream& operator<<(std::ostream &os, const EdgeWeightedGraph &G)
{
	os << G.Vertices()<< " vertices, "<< G.Edges()<<" edges"<<std::endl;
	for(std::size_t i =0 ; i!= G.Vertices(); ++i)
	{
		os << i <<": ";
		for( const Edge &w : G.Adj(i))
		{
			os<< w << " ";
		}
		os << std::endl;
	}
	return os;
}

std::list<Edge> EdgeWeightedGraph::edges() const
{
	std::list<Edge> l;
	std::size_t selfLoops = 0;
	for(std::size_t v =0 ; v != V; ++v)
	{
		for(const Edge &e : adj[v])
		{
			if(e.other(v) > v)	l.push_back(e);
			else if ( e.other(v) == v)
			{
				if(selfLoops % 2 == 0)
				{
					l.push_back(e);
				}
				++selfLoops;
			}
		}
	}
	return l;

}
