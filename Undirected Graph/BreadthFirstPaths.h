/*
 * BreadthFirstPaths.h
 *
 *  Created on: Apr 7, 2016
 *      Author: vibhanshu
 */

#ifndef BREADTHFIRSTPATHS_H_
#define BREADTHFIRSTPATHS_H_
#include"Graph.h"
#include <queue>
#include<vector>
#include<stack>

class BreadthFirstPaths {
private:
	bool *marked;
	std::size_t *edgeTo;
	std::size_t *distTo;

public:
	BreadthFirstPaths(const Graph &, const std::size_t &);
	virtual ~BreadthFirstPaths();
	void bfs(const Graph &, const std::size_t &);
	void bfs(const Graph &, const std::vector<std::size_t> &);
	bool hasPathTo(const std::size_t &v){ return marked[v];}
	std::size_t DistTo(const std::size_t &v){ return distTo[v];}
	std::vector<int> pathTo(const std::size_t &);
};

#endif /* BREADTHFIRSTPATHS_H_ */
