/*
 * CC.h
 *
 *  Created on: Apr 7, 2016
 *      Author: vibhanshu
 */

#ifndef CC_H_
#define CC_H_
#include "Graph.h"
class CC {
private:
	bool *marked;
	std::size_t *id;
	std::size_t *size;
	std::size_t count;
	void dfs(const Graph &, std::size_t );


public:

	CC(const Graph &);
	virtual ~CC();
	std::size_t ID(const std::size_t &v){return id[v];}
	std::size_t Size(const std::size_t &v){return size[id[v]];}
	std::size_t Count(){ return count;}
	bool connected(const std::size_t &v, const std::size_t &w){return id[v]==id[w];}
};

#endif /* CC_H_ */
