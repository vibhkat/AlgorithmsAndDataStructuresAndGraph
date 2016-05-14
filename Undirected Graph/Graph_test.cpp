/*
 * Graph_test.cpp
 *
 *  Created on: Apr 5, 2016
 *      Author: vibhanshu
 */

#include "Graph.h"
#include "DepthFirstSearch.h"
#include "DepthFirstPaths.h"
#include "BreadthFirstPaths.h"
#include "CC.h"
#include "Cycle.h"
#include<iostream>
void print(std::vector<std::size_t>&v);
void print(std::vector<std::vector<std::size_t> > &v);

int main()
{
	std::ifstream in("largeG.txt");
	Graph G;
	in >> G;
	//std::cout<<G;
	//std::cout<< "number of self loops = " << numberOfSelfLoops(G)<<std::endl;
	/*DepthFirstSearch search(G,9);
	for (std::size_t v = 0; v != G.Vertices(); ++v)
	{
		if (search.Marked(v))
	         std::cout<<v << " ";
	}
	std::cout<<std::endl;
	if( search.Count() != G.Vertices()) std::cout<< "Not connected"<<std::endl;
	else std::cout<< "Connected"<<std::endl;

	std::size_t s =1;
	DepthFirstPaths dfs(G,s);

	for (std::size_t v=0 ; v != G.Vertices(); ++v)
	{
		if(dfs.hasPathTo(v))
		{
			std::cout << s <<" to "<< v << ":";
			for( auto &x : dfs.pathTo(v))
			{
				if( x == s ) std::cout << x;
				else std::cout << "-" << x;
			}
			std::cout<<std::endl;
		}
		else std::cout << s << "not connected "<< v <<std::endl;
	}


	CC cc(G);
	std::cout<< cc.Count()<<std::endl;
	std::vector<std::vector<std::size_t> > components(cc.Count(),std::vector<std::size_t>());
	std::size_t M = cc.Count();
	for(std::size_t i =0 ; i != G.Vertices() ; ++i)
	{
		components[cc.ID(i)].push_back(i);
	}
	for (std::size_t i = 0; i != M; i++)
	{
		for (const std::size_t &v : components[i])
		{
	                std::cout<<v << " ";
	    }
	     std::cout<<std::endl;
	}
	in.close();
	std::cout<<";;;;;;;;;"<<G<<std::endl; */
	std::cout<<"CYCLE------------------------------------"<<std::endl;

	Cycle cy(G);
	std::cout<<"END1"<<std::endl;
	auto v1 = cy.CycleSet();
	std::cout<<"END2"<<std::endl;
	print(v1);
	std::cout<<"END"<<std::endl;
	double a =0.9, b = 0.8;
	std::cout<< b -a<< std::endl;
	return 0;
}




void print(std::vector<std::size_t >&v)
{
	std::cout<<" IN PRINTING FUNCTION"<<std::endl;
	 for(auto j : v)
		 std::cout<<j<<" ";
	 std::cout<<std::endl;

}


void print(std::vector<std::vector<std::size_t> > &v)
{
	std::cout<<" IN PRINTING FUNCTION"<<std::endl;
	 for(auto j : v)
	 {
		 for(auto i : j)
		 std::cout<<i<<" ";
	 std::cout<<std::endl;
	 }
}
