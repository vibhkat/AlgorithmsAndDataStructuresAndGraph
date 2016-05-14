/*
 * DirectedEdge.h
 *
 *  Created on: Apr 26, 2016
 *      Author: vibhanshu
 */

#ifndef DIRECTEDEDGE_H_
#define DIRECTEDEDGE_H_
#include<iostream>
class DirectedEdge {
	friend std::ostream& operator<<(std::ostream& os, const DirectedEdge &e){ os<< e.v << "->"<<e.w<<" "<< e.weight;	return os;};
private:
	std::size_t v;
	std::size_t w;
	double weight;
public:
	DirectedEdge(const std::size_t &V=0, const std::size_t &W=0, const double &wt=0):v(V),w(W),weight(wt){};
	std::size_t from()const {return v;}
	std::size_t to()const {return w;}
	double Weight()const {return weight;}
	int compareTo(const DirectedEdge &that){
			if(weight < that.weight) return -1;
			else if(weight > that.weight) return +1;
			else return 0;
		}
};

#endif /* DIRECTEDEDGE_H_ */
