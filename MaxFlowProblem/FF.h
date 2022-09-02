#ifndef _FF_H_
#define _FF_H_
#include <stdlib.h>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "Graph.h"
#include "DijkstraVertex.h"
#include "PriorityQueue.h"

using std::cout;
using std::endl;
using std::queue;
using std::vector;
using std::priority_queue;

class FF {
public:
	Graph buildGF(Graph graph);
	Graph FFWithBFS(Graph graph, int* maxFlow);
	Graph FFWithDijkstra(Graph graph);
	bool BFS(Graph graph, vector<int>&p);
	int* Dijkstra(Graph graph);
	int getCapacityFromPath(Graph GF, vector<int>, int t);

};

#endif