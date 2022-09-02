#ifndef _GRAPH_H_
#define _GRAPH_H_
#include "Vertex.h"
#include "Edge.h"
#include <iostream>
#include <list>
#include <vector>

using std::list;
using std::vector;

class Graph {
private:
	int s;
	int t;
	int n;
	vector <Vertex> vertexes;
//	Vertex* vertexes;

public:
	Graph(int n, int s, int t);
	void MakeEmptyGraph(int n);
	~Graph();
	int getS();
	int getT();
	int getN();
	vector<Vertex> getVertexes();
	list<Edge> GetAdjList(Vertex u);
	void AddEdge(int u, int v, int f, int c, int cf);
	void RemoveEdge(int u, int v);
	void updateEdges();
	void printGraph();
	void addResidualEdges(Graph G);
	void printGf(int maxFlow);

};

#endif