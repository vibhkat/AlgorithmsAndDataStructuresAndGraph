/*
 * EdgeWeightedDigraph.cpp
 *
 *  Created on: Apr 26, 2016
 *      Author: vibhanshu
 */

#include "EdgeWeightedDigraph.h"

EdgeWeightedDigraph::EdgeWeightedDigraph(const std::size_t &v):V(v),E(0),adj(new std::list<DirectedEdge> [V]),indegree(new std::size_t [V])
{
	for(std::size_t i=0; i!= V; ++i)
		{
			adj[i] = std::list<DirectedEdge>();
		}
}

EdgeWeightedDigraph::~EdgeWeightedDigraph()
{
	delete []adj;
	delete []indegree;
}


std::list<DirectedEdge>& EdgeWeightedDigraph::Adj(const std::size_t &v) const
{
	validateVertex(v);
	return adj[v];
}

std::ostream& operator<<(std::ostream &os, const EdgeWeightedDigraph &G)
{
	os << G.Vertices()<< " vertices, "<< G.Edges()<<" edges"<<std::endl;
	for(std::size_t i =0 ; i!= G.Vertices(); ++i)
	{
		os << i <<": ";
		for( const DirectedEdge &w : G.Adj(i))
		{
			os<< w << " ";
		}
		os << std::endl;
	}
	return os;
}




void EdgeWeightedDigraph::validateVertex(const std::size_t &v) const
{
        if (v < 0 || v >= V)
            throw "Out of Range";
}


EdgeWeightedDigraph& EdgeWeightedDigraph::addEdge(const DirectedEdge &e)
{
	std::size_t v = e.from();
	std::size_t w = e.to();
	validateVertex(v);
	validateVertex(w);
	adj[v].push_front(e);
	++indegree[w];
	E++;
return *this;
}


std::list<DirectedEdge> EdgeWeightedDigraph::edges() const
{
	std::list<DirectedEdge> list;
	for(std::size_t v =0 ; v!= V; ++v)
	{
		for( auto e : adj[v])
			list.push_front(e);
	}
	return list;

}

std::istream& operator>>(std::istream &in, EdgeWeightedDigraph &G)
{
	std::size_t v ,w , vertices, edges;
	double wt;
	in >> vertices >> edges;
	G.V = vertices;
	G.adj = new std::list<DirectedEdge>[vertices];
	G.indegree = new std::size_t[vertices];
	for (std::size_t i = 0; i != edges; ++i)
	{
		in >> v >> w >>wt;
		G.addEdge({v, w, wt});
	}
	return in;
}
