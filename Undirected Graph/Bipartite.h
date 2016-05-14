/*
 * Bipartite.h
 *
 *  Created on: Apr 9, 2016
 *      Author: vibhanshu
 */

#ifndef BIPARTITE_H_
#define BIPARTITE_H_
#include"Graph.h"
#include<vector>
#include<cassert>
#include<iostream>

class Bipartite {
private:
	bool *marked;
	bool *color;
	std::size_t *edgeTo;
	bool isBipartite;
	std::vector<std::size_t> cycle;
	void dfs(const Graph &, const std::size_t & );
	bool check (const Graph &);

public:
	Bipartite(const Graph&);
	virtual ~Bipartite();
	bool isBiPartite(){ return isBipartite;}
	bool Color (const std::size_t &);
	std::vector<std::size_t> oddcycle(){ return cycle;}
};

#endif /* BIPARTITE_H_ */
