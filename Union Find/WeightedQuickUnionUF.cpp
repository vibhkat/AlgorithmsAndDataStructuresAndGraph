/*
 * WeightedQuickUnionUF.cpp
 *
 *  Created on: Apr 21, 2016
 *      Author: vibhanshu
 */

#include "WeightedQuickUnionUF.h"

WeightedQuickUnionUF::WeightedQuickUnionUF(const std::size_t &N):parent(new std::size_t[N]),wt(new std::size_t[N]),count(N),size(N)
{
	for(std::size_t i = 0; i != N ; ++i)
	{
		parent[i] = i;
		wt[i] = 1;
	}
}

WeightedQuickUnionUF::~WeightedQuickUnionUF() {
delete []parent;
delete []wt;
}

void WeightedQuickUnionUF::validateVertex(const std::size_t &v) const
{
        if (v < 0 || v >= size)
            throw "Out of Range";
}


std::size_t WeightedQuickUnionUF::find( std::size_t p)
{
	validateVertex(p);
	while(p != parent[p])
		p = parent[p];
	return p;
}

void WeightedQuickUnionUF::Union(const std::size_t &p, const std::size_t &q)
{
	std::size_t rootP = find(p);
	std::size_t rootQ = find(q);
	if( rootP == rootQ) return;
	if(wt[rootP] < wt[rootQ])
	{
		parent[rootP] = rootQ;
		wt[rootQ] += wt[rootP];
	}
	else
	{
		parent[rootQ] = rootP;
		wt[rootP] += wt[rootQ];

	}
	--count;
}
