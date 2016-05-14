/*
 * QuickUnionUF.h
 *
 *  Created on: Apr 20, 2016
 *      Author: vibhanshu
 */

#ifndef QUICKUNIONUF_H_
#define QUICKUNIONUF_H_
#include<iostream>
class QuickUnionUF {
private:
	std::size_t *parent;
	std::size_t count;
	std::size_t size;
	void validateVertex(const std::size_t &) const ;
public:
	QuickUnionUF(const std::size_t &);
	virtual ~QuickUnionUF();
	std::size_t Count(){ return count;}
	std::size_t find( std::size_t );
	bool connected(const std::size_t &p, const std::size_t &q){ return find(p) == find(q);}
	void Union(const std::size_t & , const std::size_t &);

};

#endif /* QUICKUNIONUF_H_ */
