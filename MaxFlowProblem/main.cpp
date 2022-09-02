#include "Validation.h"
#include "Graph.h"
#include "FF.h"

int main(int argc, char** argv) {
	int n, m, i, j, c, s, t, maxFlow = 0;
	bool isValid = true;
	Validation validation;
	FF ff;

	cin >> n;
	cin >> m;
	cin >> s;
	cin >> t;

	if (validation.isStartInputValid(n, m, s, t)) { // n, m > 0 && 0 < s,t =< n  dummy head
		Graph graph(n, s, t);

		for (int k = 0; (k < m) && isValid; k++) {
			cin >> i;
			cin >> j;
			cin >> c;
			if (validation.isValidEdge(i, j, c, n)) {  // c >= 0 && 0 < i, j =< n
				graph.AddEdge(i, j, 0, c, 0); // Edge
				graph.AddEdge(j, i, 0, 0, 0); // AntiEdge
				}
			else {
				isValid = false;
			}
		}

		if (isValid) {
			graph.printGraph();
			// BFS
			Graph GfBFS = ff.FFWithBFS(graph, &maxFlow);
			cout << "BFS Method:" << endl;
			GfBFS.printGf(maxFlow);
			maxFlow = 0;
			// DYK
			//ff.FFWithDijkstra(graph);
		}

	}
	else {
		isValid = false;
	}
	
	if(!isValid){
		cout << "invalid input" << endl;
		exit(1);
	}

}
