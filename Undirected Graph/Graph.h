/*
 * Graph.h
 *
 *  Created on: Apr 5, 2016
 *      Author: vibhanshu
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include<vector>
#include<list>
#include<string>
#include<iostream>
#include<fstream>
class Graph {
	friend std::size_t numberOfSelfLoops(const Graph&);
	friend std::istream& operator>>(std::istream &, Graph&);
	friend std::ostream& operator<<(std::ostream &, const Graph&);
public:
	//Graph();
	Graph(const std::size_t &v = 0);
	Graph( std::fstream &);
	virtual ~Graph();
	Graph& addEdge(const std::size_t &, const std::size_t &);
	std::list<int>& Adj (const std::size_t &) const;
	std::size_t Vertices()const  {return V;}
	std::size_t Edges()const {return E;}
	std::size_t degree(const std::size_t  &) const;

private:
	std::size_t V;
	std::size_t E;
	std::list<int> *adj;
	void validateVertex(const std::size_t &) const;
};

#endif /* GRAPH_H_ */
