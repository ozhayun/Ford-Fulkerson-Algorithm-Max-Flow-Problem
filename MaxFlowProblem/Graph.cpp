#include "Graph.h"

Graph::Graph(int n, int S, int T) {
	vertexes.reserve(n + 1); // dummy head
	this->MakeEmptyGraph(n);
	s = S;
	t = T;
}

void Graph::MakeEmptyGraph(int n) {
	for (int i = 0; i <= n; i++) {
		vertexes.push_back(Vertex(i));
	}
	this->n = n;
	s = 0;
	t = 0;
}
                           
Graph::~Graph() {
	//delete vertexes;
}

int Graph::getS() {
	return s;
}

int Graph::getT() {
	return t;
}

int Graph::getN() {
	return n;
}

vector<Vertex> Graph::getVertexes() {
	return vertexes;
}

list<Edge> Graph::GetAdjList(Vertex u) {
	return u.getEdges();
}

void Graph::AddEdge(int u, int v, int f, int c, int cf) {
	vertexes[u].addEgde(v, f, c, cf);
}

void Graph::RemoveEdge(int u, int v) {
	vertexes[u].removeEdge(v);
}

void Graph::printGraph() {
	for (int i = 1; i <= n; i++) {
		vertexes[i].printVertex();
	}
}

void Graph::addResidualEdges(Graph G) {
	list<Edge> edges;
	for (int i = 1; i <= n; i++) {
		edges = G.getVertexes()[i].getEdges();
		for (auto edge = edges.begin(); edge != edges.end(); edge++) {
			if (edge->getCapacity() != edge->getFlow()){
				AddEdge(edge->getFromVertex(), edge->getToVertex(), edge->getFlow(), edge->getCapacity(), (edge->getCapacity() - edge->getFlow()));
			}
		}
	}
}

void Graph::updateEdges() {
	list<Edge> edges;
	for (int i = 1; i <= n; i++) {
		edges = vertexes[i].getEdges();
		for (auto edge = edges.begin(); edge != edges.end(); edge++) {
			if (edge->getCF() == 0) {
				RemoveEdge(edge->getFromVertex(), edge->getToVertex());
			}
		}
	}
}

// zmani
void Graph::printGf(int maxFlow) {
	cout << "Max flow = " << maxFlow << endl;
	cout << "Min cut: S = ";
	//vector<int> p = getMinCut(); //?

	/*for (int i = 1; i <= n; i++) {
		if (p[i] != -1) {
			cout << i << ", ";
		}
	}

	cout << "T = ";
	for (int i = 1; i <= n; i++) {
		if (p[i] == -1) {
			cout << i << ", ";
		}
	}*/

}


