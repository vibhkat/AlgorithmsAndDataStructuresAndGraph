/*
 * Edge.h
 *
 *  Created on: Apr 19, 2016
 *      Author: vibhanshu
 */

#ifndef EDGE_H_
#define EDGE_H_
#include<vector>
#include<iostream>

class Edge {
	friend std::ostream& operator<<(std::ostream &os,const Edge& e);
private:
	std::size_t v ;
	std::size_t w ;
	double weight;
public:
	Edge(const std::size_t &V=0, const std::size_t &W=0, const double &wt=0):v(V),w(W),weight(wt){};
	std::size_t either()const { return v;}
	std::size_t other(std::size_t vertex) const{
		if(vertex == v) return w;
		else if(vertex == w)return v;
		else throw "Illegal end point";
	}

	int compareTo(const Edge &that){
		if(weight < that.weight) return -1;
		else if(weight > that.weight) return +1;
		else return 0;
	}

	double Weight()const{return weight;	}
	//putting the opposite condition in this comparison just for priority_queue which is minimum
	bool operator<(const Edge &that) const{
			return weight > that.weight;
		}
};

#endif /* EDGE_H_ */
