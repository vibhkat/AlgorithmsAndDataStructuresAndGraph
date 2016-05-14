/*
 * DepthFirstPaths.h
 *
 *  Created on: Apr 6, 2016
 *      Author: vibhanshu
 */

#ifndef DEPTHFIRSTPATHS_H_
#define DEPTHFIRSTPATHS_H_
#include"Graph.h"
#include<stack>
#include<vector>

class DepthFirstPaths {
private:
	bool *marked;
	std::size_t *edgeTo;
	std::size_t s;
	void dfs(const Graph &, std::size_t ) ;  // Depth first Search from given source vertex



public:
	DepthFirstPaths(const Graph&, std::size_t);
	virtual ~DepthFirstPaths();
	bool hasPathTo(const std::size_t &) ;
	std::vector<int> pathTo(const std::size_t &) ;


};

#endif /* DEPTHFIRSTPATHS_H_ */
