#include "PriorityQueue.h"

PriorityQueue<DijkstraVertex*>::PriorityQueue(Graph graph) {
	//pointers = new DijkstraVertex[graph.getN() + 1];
	//
	//for (int i = 1; i <= graph.getN(); i++) {
	//	DijkstraVertex* currVertex = new DijkstraVertex(graph.getVertexes()[i], -1, -1);
	//	pointers[i] = *currVertex;
	//	if (graph.getS() == i) {
	//		currVertex->setMin(0);
	//	}
	//	this->c.push_back(currVertex);
	//}

}

DijkstraVertex* PriorityQueue<DijkstraVertex*>::getPQPointers() {
	return pointers;
}

void PriorityQueue<DijkstraVertex>::updateQueue(int i) {
	//swap(i);
	//DijkstraVertex temp = this->top();
	//this->pop();
	//this->push(temp);
}


//void PriorityQueue<DijkstraVertex>::swap(int i){
//	DijkstraVertex temp = this->c[i];
//	c[i] = c[0];
//	c[0] = temp;
//}


