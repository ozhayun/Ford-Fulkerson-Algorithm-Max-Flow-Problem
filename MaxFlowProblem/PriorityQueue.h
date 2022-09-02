#ifndef _PRIORITYQUEUE_H_
#define _PRIORITYQUEUE_H_
#include <stdlib.h>
#include <iostream>
#include <string>
#include <queue>
#include "Graph.h"
#include "DijkstraVertex.h"

using std::queue;
using std::priority_queue;

using std::list;

template<class T = DijkstraVertex>
class PriorityQueue: public std::priority_queue<T>{
private:
	DijkstraVertex* pointers;


public:
	PriorityQueue(Graph graph);
	DijkstraVertex* getPQPointers();
	void updateQueue(int i);
	void swap(int i);

};

#endif






