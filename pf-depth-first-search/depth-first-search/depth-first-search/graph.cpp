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

void graph::run_dfs(int start)
{
	visited[start] = true;

	cout << "Visited " << start << endl;

	list<int>::iterator i;

	for (i = edges[start].begin(); i != edges[start].end(); i++)
	{
		int neighbour = *i;

		if (!visited[neighbour])
		{
			run_dfs(neighbour);
		}
	}
}

void graph::add_edge(int source, int destination)
{
	edges[source].push_back(destination);
	edges[destination].push_back(source);
}