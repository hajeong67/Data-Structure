#include "SrchAMGraph.h"
#include "AdjListGraph.h"
#include "CirclearQueue.h"

void main() {
	SrchAMGraph g;
	g.load("graph.txt");
	printf("±×·¡ÇÁ(graph.txt)\n");
	g.display();

	printf("BFS ==> ");
	g.resetVisited();
	g.BFS(0);
	printf("\n");
}

class SrchALGraph :public AdjListGraph
{
	bool visited[MAX_VTXS];
public:
	void resetVisited() {
		for (int i = 0; i < size; i++)
			visited[i] = false;
	}
	bool isLinked(int u, int v) {
		for (Node* p = adj[u]; p != NULL; p = p->getLink())
			if (p->getId() == v) return true;
		return false;
	}

	void BFS(int v) {
		visited[v] = true;
		printf("%c", getVertex(v));

		CircularQueue que;
		que.enqueue(v);

		while (!que.isEmpty()) {
			int v = que.dequeue();
			for (int w = 0; w < size; w++)
				if (isLinked(v, w) && visited[w] == false) {
					visited[w] = true;
					printf("%c", getVertex(w));
					que.enqueue(w);
				}
			for (Node* w = adj[v]; w != NULL; w = w->getLink()) {
				int id = w->getId();
				if (!visited[id]) {
					visited[id] = true;
					printf("%c", getVertex(id));
					que.enqueue(id);
				}
			}
		}
	}
};