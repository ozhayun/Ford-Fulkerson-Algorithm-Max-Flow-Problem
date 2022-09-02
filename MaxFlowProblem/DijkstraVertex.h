#ifndef _DIJKSTRAVERTEX_H_
#define _DIJKSTRAVERTEX_H_
#include <iostream>
#include <list>
#include "Edge.h"
#include "Vertex.h"

using std::list;

class DijkstraVertex: public Vertex{
private:
	int p;
	int min;

public:
	DijkstraVertex();
	DijkstraVertex(Vertex vertex, int p, int min);
	int getP();
	void setP(int p);
	int getMin();
	void setMin(int m);

	bool operator < (const DijkstraVertex& other){
		return this->min < other.min;
	}
	bool operator()(const DijkstraVertex& v1, const DijkstraVertex& v2);

	void updateQueue();
};

#endif





