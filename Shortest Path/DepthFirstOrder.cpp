/*
 * DepthFirstOrder.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: vibhanshu
 */

#include "DepthFirstOrder.h"

DepthFirstOrder::DepthFirstOrder(const EdgeWeightedDigraph &D): marked(new bool[D.Vertices()]) , pre(new std::size_t [D.Vertices()]), post(new std::size_t [D.Vertices()]),
preCounter(0),postCounter(0)
{
	for(std::size_t v = 0; v != D.Vertices(); ++v)
	{
		if(!marked[v])
			dfs(D,v);
	}
}


void DepthFirstOrder::dfs(const EdgeWeightedDigraph &D, std::size_t v)
{
	marked[v] = true;
	pre[v] = preCounter++;
	preorder.push_back(v);
	for(DirectedEdge e: D.Adj(v))
	{
		std::size_t w = e.to();
		if(!marked[w])
			dfs(D,w);
	}
	postorder.push_back(v);
	post[v] = postCounter++;
}



 bool DepthFirstOrder::check()
 {
     // check that post(v) is consistent with post()
       std::size_t r = 0;
        for (std::size_t v : PostOrder()) {
            if (Post(v) != r) {
                std::cout<<"post(v) and post() inconsistent"<<std::endl;
                return false;
            }
            r++;
        }

        // check that pre(v) is consistent with pre()
        r = 0;
        for (std::size_t v : PreOrder()) {
            if (Pre(v) != r) {
                std::cout<<"post(v) and post() inconsistent"<<std::endl;
                 return false;
            }
            r++;
        }


        return true;
    }









DepthFirstOrder::~DepthFirstOrder() {
delete []marked;
delete []pre;
delete []post;
}

