
 #ifndef WEIGHTEDQUICKUNIONUF_H_
#define WEIGHTEDQUICKUNIONUF_H_
#include <iostream>

class WeightedQuickUnionUF {
private:
	std::size_t *parent;
	std::size_t *wt;
	std::size_t count;
	std::size_t size;
	void validateVertex(const std::size_t &) const;
public:
	WeightedQuickUnionUF(const std::size_t &);
	virtual ~WeightedQuickUnionUF();
	std::size_t Count(){return count;}
	bool connected(const std::size_t &p, const std::size_t &q){ return find(p) == find(q);}
	std::size_t find( std::size_t );
	void Union(const std::size_t & , const std::size_t &);

};

#endif
