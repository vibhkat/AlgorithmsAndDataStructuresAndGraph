/*
 * QuickFindUF.cpp
 *
 *  Created on: Apr 20, 2016
 *      Author: vibhanshu
 */

#include "QuickFindUF.h"

QuickFindUF::QuickFindUF(const std::size_t &N):id(new std::size_t[N]), count(N), size(N) {
	for(std::size_t i = 0 ; i != N ; ++i)
		id[i]=i;

}

QuickFindUF::~QuickFindUF() {
delete []id;}

void QuickFindUF::validateVertex(const std::size_t &v) const
{
        if (v < 0 || v >= size)
            throw "Out of Range";
}


bool QuickFindUF::connected(const std::size_t &p, const std::size_t &q)
{
	validateVertex(p);
	validateVertex(q);
	return id[p] == id[q];
}

std::size_t QuickFindUF::find(const std::size_t &p)
{
	validateVertex(p);
	return id[p];
}


void QuickFindUF::Union(const std::size_t &p, const std::size_t &q )
{
	validateVertex(p);
	validateVertex(q);
	std::size_t pID = id[p];
	std::size_t qID = id[q];
	if( pID == qID) return; // also check if same id then return
	for(std::size_t i =0 ; i != size; ++i)
	{
		if(id[i] == pID)
			id[i] = qID;
	}
	--count;
}


std::istream& operator>>(std::istream &in, QuickFindUF &uf)
{
	std::size_t vertices, p ,q;
	in >> vertices;
	uf.size = vertices;
	uf.id = new std::size_t[vertices];
	for (std::size_t i = 0; i != vertices; ++i)
	{
		in >> p >>q;
		uf.Union(p,q);
	}
	return in;
}
