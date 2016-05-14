/*
 * main.cpp
 *
 *  Created on: Apr 26, 2016
 *      Author: vibhanshu
 */

#include "DirectedEdge.h"
#include "EdgeWeightedDigraph.h"
#include<fstream>
#include<iostream>
#include "DijkstraSP.h"
#include "AcyclicSP.h"



int main()
{

	std::ifstream in("mediumEWD.txt");
	EdgeWeightedDigraph G;
	in >> G;
	std::cout<<G<<std::endl<<"-------------------------------"<<std::endl;;
	std::size_t s = 0;
	DijkstraSP sp(G, s);
	for ( std::size_t t =0 ; t <G.Vertices() ; ++t)
	{
		std::cout<< s << "to" << t << "( "<<sp.DistTo(t)<< " )";
		for(DirectedEdge e : sp.pathTo(t))
		{
			std::cout<<e << " ";
		}
		std::cout<< std::endl;
	}


}
