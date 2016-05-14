/*
 * Edge.cpp
 *
 *  Created on: Apr 19, 2016
 *      Author: vibhanshu
 */

#include "Edge.h"



std::ostream& operator<<(std::ostream &os,const Edge& e)
{
	os<< e.v << "-"<<e.w<<" "<< e.weight;
return os;
}
