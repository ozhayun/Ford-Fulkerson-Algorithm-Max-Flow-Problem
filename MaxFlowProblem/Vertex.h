#ifndef _VERTEX_H_
#define _VERTEX_H_
#include <iostream>
#include <list>
#include "Edge.h"

using std::list;

class Vertex {
private:
	int vertex;
	list<Edge> edges;

public:
	Vertex();
	Vertex(int v);
	Vertex(const Vertex &v){
		this->vertex = v.vertex;
		this->edges= v.edges;
	}

	int getVertex();
	void setVertex(int num);
	list<Edge> getEdges();
	void setEdges(list<Edge> edges);
	void addEgde(int j, int f, int c, int cf);
	bool isEdgeExistAndUpdate(int v, int f, int c, int cf);
	void removeEdge(int v);
	void printVertex();
	Edge getEdge(int toVertex);

};

#endif






