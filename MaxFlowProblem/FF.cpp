#include "FF.h"


Graph FF::buildGF(Graph graph) {
	Graph GF(graph.getN(), graph.getS(), graph.getT());
	GF.addResidualEdges(graph);
	return GF;
}

Graph FF::FFWithBFS(Graph graph, int* maxFlow) {
	Graph GF = buildGF(graph);
	GF.printGraph();
	vector<int> parent;
	//parent.reserve(graph.getN() + 1); 
	int v, cfp;
	Edge currEdgeGraph, antiCurrEdgeGraph, currEdgeGF, antiCurrEdgeGF;

	//if (parent[graph.getT()] == -1) //no parent --> no maslol

	while (BFS(GF, parent)) {
		v = graph.getT();
		cfp = getCapacityFromPath(GF, parent, v);
		while (v != graph.getS()) {
			currEdgeGraph = graph.getVertexes()[parent[v]].getEdge(v); // (p,v) --> G
			currEdgeGraph.setFlow(currEdgeGraph.getFlow() + cfp);

			antiCurrEdgeGraph = graph.getVertexes()[v].getEdge(parent[v]); //(v,p) --> G
			antiCurrEdgeGraph.setFlow(-currEdgeGraph.getFlow());

			currEdgeGF = GF.getVertexes()[parent[v]].getEdge(v); //(p,v) --> GF
			currEdgeGF.setCF(currEdgeGraph.getCapacity() - currEdgeGraph.getFlow());

			antiCurrEdgeGF = GF.getVertexes()[v].getEdge(parent[v]);  //(v,p) --> GF
			antiCurrEdgeGF.setCF(antiCurrEdgeGraph.getCapacity() - antiCurrEdgeGraph.getFlow());

			*(maxFlow) += cfp;
			v = parent[v];
		}
		GF.updateEdges();
		
	}
	return graph;
}

bool FF::BFS(Graph graph, vector<int>&p) {
	//int* d[graph.getN()+ 1];
	queue<Vertex> bfsQueue;
	Vertex u, v;
	list<Edge> currVertexAdj;
	Edge edge;
	p.clear();

	// init	
	for (int i = 0; i <= graph.getN(); i++) {
		p.push_back(-1);
	}

	bfsQueue.push(graph.getVertexes()[graph.getS()]);
	p[graph.getS()] = 0;

	while(!bfsQueue.empty()){
		u = bfsQueue.front();
		bfsQueue.pop();
		currVertexAdj = u.getEdges();


		for (auto currEdge = currVertexAdj.begin(); currEdge != currVertexAdj.end(); currEdge++) {
			v = graph.getVertexes()[currEdge->getToVertex()];

			if (p[v.getVertex()] == -1) {
				p[v.getVertex()] = u.getVertex();
				bfsQueue.push(v);
			}
		}
	}
	return p[graph.getT()] != -1;
}

int FF::getCapacityFromPath(Graph GF, vector<int> parent, int t) {
	int v = t;
	Edge edge = GF.getVertexes()[parent[v]].getEdge(v);
	int min = 0;
	if (edge.getFromVertex() != -1) {
		min = edge.getCF();

		while (parent[v] != 0) {
			if (GF.getVertexes()[parent[v]].getEdge(v).getCF() < min) {
				min = GF.getVertexes()[parent[v]].getEdge(v).getCF();
			}
			v = parent[v];
		}
	}
	return min;
}

Graph FF::FFWithDijkstra(Graph graph) {
	//buildGF(graph);
	return graph;// Zmani
}




int* FF::Dijkstra(Graph graph) {
	//PriorityQueue<DijkstraVertex*> priorityQueue(graph);
	//DijkstraVertex u, v;
	//list<Edge> currVertexAdj;
	//Edge currEdge;
	//int min = 0;


	//// Handle the first iteration of adj of S, the init of s.min is zero so every adj will get 0

	//while (!priorityQueue.empty()) {
	//	u = *priorityQueue.top();
	//	priorityQueue.pop();
	//	currVertexAdj = u.getEdges();

	//	while (!currVertexAdj.empty()) {
	//		currEdge = currVertexAdj.front();
	//		v = priorityQueue.getPQPointers()[currEdge.getToVertex()];
	//		currVertexAdj.pop_front();
	//		
	//		if (u.getMin() <= currEdge.getCapacity()) {
	//			min = u.getMin();
	//			v.setP(u.getVertex());
	//		}
	//		else {
	//			min = currEdge.getCapacity();
	//			v.setP(u.getVertex());
	//		}

	//		if (v.getP() != -1 && v.getMin() <= min) { // yes parent
	//			min = v.getMin();
	//		}
	//		v.setMin(min);


	//		//update
	//		priorityQueue.updateQueue(v.getVertex());
	//	}
	//}


	return NULL; // Zmani
}