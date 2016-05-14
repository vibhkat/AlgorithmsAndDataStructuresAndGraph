/*
 * WeightedQuickUnionByHeightUF.h
 *
 *  Created on: Apr 21, 2016
 *      Author: vibhanshu
 */

#ifndef WEIGHTEDQUICKUNIONBYHEIGHTUF_H_
#define WEIGHTEDQUICKUNIONBYHEIGHTUF_H_
#include <iostream>
class WeightedQuickUnionByHeightUF {
private:
	std::size_t *parent;
	std::size_t *ht;
	std::size_t count;
	std::size_t size;
	void validateVertex(const std::size_t &) const;
public:
	WeightedQuickUnionByHeightUF(const std::size_t &);
	virtual ~WeightedQuickUnionByHeightUF();
	std::size_t Count(){return count;}
	bool connected(const std::size_t &p, const std::size_t &q){ return find(p) == find(q);}
	std::size_t find( std::size_t );
	void Union(const std::size_t & , const std::size_t &);

};
#endif /* WEIGHTEDQUICKUNIONBYHEIGHTUF_H_ */
