#include "graph.h"
#include <iostream>

using namespace std;

graph::graph(int vertices_amount)
{
	edges = new list<int>[vertices_amount];
	visited = new bool[vertices_amount];
	for (int i = 0; i < vertices_amount; i++)
	{
		visited[i] = false;
	}
}

void graph::run_bfs(int start)
{
	list<int> queue;

	visited[start] = true;

	queue.push_back(start);

	list<int>::iterator i;

	while (!queue.empty())
	{
		int visiting = queue.front();

		cout << "Visited " << visiting << endl;

		queue.pop_front();

		for (i = edges[visiting].begin(); i != edges[visiting].end(); i++)
		{
			int neighbour = *i;

			if (!visited[neighbour])
			{
				visited[neighbour] = true;

				queue.push_back(neighbour);
			}
		}
	}
}

void graph::add_edge(int source, int destination)
{
	edges[source].push_back(destination);
	edges[destination].push_back(source);
}
