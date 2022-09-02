#ifndef _EDGE_H_
#define _EDGE_H_
#include <stdlib.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;

class Edge {
private:
	int fromVertex;
	int toVertex;
	int flow; // zrima
	int capacity; // kibul
	int cf; // kibul shiori


public:
	Edge();
	Edge(int fromVertex, int toVertex, int flow, int capacity, int cf);
	Edge(const Edge& e);
	int getFromVertex();
	void setFromVertex(int num);
	int getToVertex();
	void setToVertex(int num);
	int getFlow();
	void setFlow(int num);
	int getCapacity();
	void setCapacity(int num);	
	int getCF();
	void setCF(int num);
	void printEdge();
};

#endif