/*
 * main.cpp
 *
 *  Created on: Apr 20, 2016
 *      Author: vibhanshu
 */

#include "QuickFindUF.h"
#include<iostream>
#include<fstream>
#include "WeightedQuickUnionUF.h"

int main()
{
 std::ifstream in("tinyUF.txt");
 std::size_t vertices, p ,q;
 	in >> vertices;
 	QuickFindUF uf(vertices);
 	while( in >> p >> q)
 	{
 		if( uf.connected(p ,q)) continue;
 		uf.Union(p,q);
 		std::cout<< p << " "<< q <<std::endl;
 	}
 	std::cout<<uf.Count()<< " components"<<std::endl;
}
