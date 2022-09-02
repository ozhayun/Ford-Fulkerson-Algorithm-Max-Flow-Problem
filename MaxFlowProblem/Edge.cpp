#include "Edge.h"

// Constructor
Edge::Edge() {
	fromVertex = toVertex = flow = capacity = cf = 0;
}

// New Edge
Edge::Edge(int fromVertex, int toVertex, int flow, int capacity, int cf) {
	this->fromVertex = fromVertex;
	this->toVertex = toVertex;
	this->flow = flow;
	this->capacity = capacity;
	this->cf = cf;
}


// Copy constructor
//Edge::Edge(const Edge& e){
	//this->fromVertex = e.fromVertex;
	//this->toVertex;
	//this->flow;
	//this->capacity;
//}

Edge::Edge(const Edge &e) {
	fromVertex = e.fromVertex;
	toVertex = e.toVertex;
	flow = e.flow;
	capacity = e.capacity;
	cf = e.cf;
}

int Edge::getFromVertex() {
	return fromVertex;
}

void Edge::setFromVertex(int num) {
	fromVertex = num;
}

int Edge::getToVertex() {
	return toVertex;
}

void Edge::setToVertex(int num) {
	toVertex = num;
}

int Edge::getFlow() {
	return flow;
}

void Edge::setFlow(int num) {
	flow = num;
}

int Edge::getCapacity() {
	return capacity;
}

void Edge::setCapacity(int num) {
	capacity = num;
}

int Edge::getCF() {
	return cf;
}

void Edge::setCF(int num) {
	cf = num;
}

void Edge::printEdge() {
	cout << "(" << fromVertex << ", " << toVertex << ") " << "c:" << capacity << " f:" << flow << "     ";
}
