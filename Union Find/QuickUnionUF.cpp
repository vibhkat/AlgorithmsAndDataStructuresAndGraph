/*
 * QuickUnionUF.cpp
 *
 *  Created on: Apr 20, 2016
 *      Author: vibhanshu
 */

#include "QuickUnionUF.h"

QuickUnionUF::QuickUnionUF(const std::size_t &N): parent(new std::size_t[N]), count(N), size(N){
	for(std::size_t i = 0 ; i != N ; ++i)
			parent[i]=i;

}

QuickUnionUF::~QuickUnionUF() {
delete []parent;}

void QuickUnionUF::validateVertex(const std::size_t &v) const
{
        if (v < 0 || v >= size)
            throw "Out of Range";
}

std::size_t QuickUnionUF::find( std::size_t p)
{
	validateVertex(p);
	while(p != parent[p])
		p = parent[p];
	return p;
}

void QuickUnionUF::Union(const std::size_t &p, const std::size_t &q)
{
	validateVertex(p);
	validateVertex(q);
	std::size_t rootP = find(p);
	std::size_t rootQ = find(q);
	if(rootP == rootQ) return;
	parent[rootP] = rootQ;  //can alos change the other way
	--count;
}
