#include "DijkstraVertex.h"

DijkstraVertex::DijkstraVertex() {
	p = -1;
	min = -1;
}

DijkstraVertex::DijkstraVertex(Vertex vertex, int p, int min) {
	this->setVertex(vertex.getVertex());
	this->setEdges(vertex.getEdges());
	this->p = p;
	this->min = min;
}


int DijkstraVertex::getP() {
	return p;
}

void DijkstraVertex::setP(int p) {
	this->p = p;
}

int DijkstraVertex::getMin() {
	return min;
}

void DijkstraVertex::setMin(int m) {
	this->min = m;
}


bool DijkstraVertex:: operator()(const DijkstraVertex& v1, const DijkstraVertex& v2){
	return v1.min < v2.min;
}


