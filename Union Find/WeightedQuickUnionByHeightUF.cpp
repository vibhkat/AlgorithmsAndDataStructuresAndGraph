/*
 * WeightedQuickUnionByHeightUF.cpp
 *
 *  Created on: Apr 21, 2016
 *      Author: vibhanshu
 */

#include "WeightedQuickUnionByHeightUF.h"

WeightedQuickUnionByHeightUF::WeightedQuickUnionByHeightUF(const std::size_t &N):parent(new std::size_t[N]),ht(new std::size_t[N]),count(N),size(N)
{
	for(std::size_t i = 0; i != N ; ++i)
	{
		parent[i] = i;
		ht[i] = 0;
	}
}

WeightedQuickUnionByHeightUF::~WeightedQuickUnionByHeightUF() {
delete []parent;
delete []ht;
}

void WeightedQuickUnionByHeightUF::validateVertex(const std::size_t &v) const
{
        if (v < 0 || v >= size)
            throw "Out of Range";
}


std::size_t WeightedQuickUnionByHeightUF::find( std::size_t p)
{
	validateVertex(p);
	while(p != parent[p])
		p = parent[p];
	return p;
}

void WeightedQuickUnionByHeightUF::Union(const std::size_t &p, const std::size_t &q)
{
	std::size_t rootP = find(p);
	std::size_t rootQ = find(q);
	if( rootP == rootQ) return;
	if(ht[rootP] < ht[rootQ])   // ht of taller tree remains the same when we add a shorter tree to it
	{
		parent[rootP] = rootQ;
	}
	else if(ht[rootP] > ht[rootQ])
	{
		parent[rootQ] = rootP;
	}
	else   // change of ht when equal trees are merging.
	{
		parent[rootQ] = rootP;
		++ht[rootP];
	}
	--count;
}
