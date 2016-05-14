/*
 * DepthFirstOrder.h
 *
 *  Created on: Apr 16, 2016
 *      Author: vibhanshu
 */

#ifndef DEPTHFIRSTORDER_H_
#define DEPTHFIRSTORDER_H_
#include<vector>
#include<queue>
#include "EdgeWeightedDigraph.h"
#include<algorithm>
class DepthFirstOrder {
private:
	bool *marked;
	std::size_t *pre;
	std::size_t *post;
	std::size_t preCounter;
	std::size_t postCounter;
	std::vector<std::size_t> preorder;
	std::vector<std::size_t> postorder;
	void dfs(const EdgeWeightedDigraph &, std::size_t );
	bool check();
public:
	DepthFirstOrder(const EdgeWeightedDigraph &);
	virtual ~DepthFirstOrder();
	std::size_t Pre(const std::size_t &v){ return pre[v];}
	std::size_t Post(const std::size_t &v){ return post[v];}
	std::vector<std::size_t> PostOrder(){return postorder;}
	std::vector<std::size_t> PreOrder(){return preorder;}
	std::vector<std::size_t> reversePostOrder(){
		auto Reverse = postorder;
		std::reverse(Reverse.begin(), Reverse.end());
		return Reverse;
	}

};

#endif /* DEPTHFIRSTORDER_H_ */
