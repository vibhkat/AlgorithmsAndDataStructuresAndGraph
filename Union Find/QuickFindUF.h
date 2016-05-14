/*
 * QuickFindUF.h
 *
 *  Created on: Apr 20, 2016
 *      Author: vibhanshu
 */

#ifndef QUICKFINDUF_H_
#define QUICKFINDUF_H_
#include<iostream>
class QuickFindUF {
	friend std::istream& operator>>(std::istream &in, QuickFindUF &uf);

private:
	std::size_t *id;
	std::size_t count;
	std::size_t size;
	void validateVertex(const std::size_t &N =0 ) const ;

public:
	QuickFindUF(const std::size_t &N = 0);
	virtual ~QuickFindUF();
	std::size_t Count(){ return count;}
	bool connected(const std::size_t &, const std::size_t & );
	std::size_t find(const std::size_t &);
	void Union(const std::size_t &, const std::size_t & );

};

#endif /* QUICKFINDUF_H_ */
