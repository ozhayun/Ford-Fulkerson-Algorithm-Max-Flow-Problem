#include "Vertex.h"


Vertex::Vertex() {
	vertex = 0;
}

Vertex::Vertex(int v) {
	vertex = v;
}

int Vertex::getVertex() {
	return vertex;
}

void Vertex::setVertex(int num) {
	vertex = num;
}

std::list<Edge> Vertex::getEdges() {
	return edges;
}

void Vertex::setEdges(list<Edge> edges) {
	this->edges = edges;
}

void Vertex::addEgde(int j, int f, int c, int cf) {
	if (!isEdgeExistAndUpdate(j, f, c, cf)) {
		edges.push_back(Edge(vertex, j, f, c, cf));
	}
}

bool Vertex::isEdgeExistAndUpdate(int v, int f, int c, int cf) {
	for (auto i = edges.begin(); i != edges.end(); i++) {
		if (i->getToVertex() == v && c != 0) {
			i->setFlow(f);
			i->setCapacity(c);
			i->setCF(cf);
			return true;
		}
		else if (i->getToVertex() == v && c == 0) {
			return true;
		} 

	}
	return false;
}

void Vertex::removeEdge(int v) {
	for (auto i = edges.begin(); i != edges.end(); i++) {
		if (i->getToVertex() == v) {
			edges.erase(i);
		}
	}
}

void Vertex::printVertex() {
	cout << "Vertex: " << vertex << " Adj: ";
	for (auto i = edges.begin(); i != edges.end(); i++) {
		i->printEdge();
	}
	cout << endl;
}


Edge Vertex::getEdge(int toVertex) {
	for (auto i = edges.begin(); i != edges.end(); i++) {
		if (i->getToVertex() == toVertex) {
			return *i;
		}
	}
	Edge edge(vertex, toVertex, 0, 0, 0);
	edges.push_back(edge);
	return edge;
}
