/*
 * main.cpp
 *
 *  Created on: Apr 19, 2016
 *      Author: vibhanshu
 */
#include "Edge.h"
#include<iostream>
#include<vector>
#include<list>
#include "EdgeWeightedGraph.h"
#include<fstream>
#include "KruskalMST.h"
#include "LazyPrimMST.h"
#include "IndexMinPQ.h"
#include "PrimMST.h"



int main()
{
 Edge e(12,34,5.67);
 std::cout<< e<<std::endl;
 std::ifstream in("tinyEWG.txt");
 EdgeWeightedGraph G;
 in >> G;
 //std::cout<< G <<std::endl;
 /*KruskalMST mst(G);
 for (Edge e : mst.edges())
 {
	 std::cout<<e<<std::endl;
 }
 std::cout<< mst.Weight()<<std::endl;
 std::cout<<"================================="<<std::endl;
 LazyPrimMST MSt(G);
 for (auto e: MSt.MST())
	 std::cout<< e <<std::endl;
 std::cout<< MSt.Weight()<<std::endl;
*/
 std::cout<<"=================================1"<<std::endl;
 try{
	 PrimMST pMST(G);
	 for (Edge e : pMST.edges())
		 std::cout<<e<<std::endl;

	 std::cout<<pMST.Weight()<<std::endl;
 }
 catch (const char *msg)
 { std::cout<<msg<<std::endl;
 }

}

