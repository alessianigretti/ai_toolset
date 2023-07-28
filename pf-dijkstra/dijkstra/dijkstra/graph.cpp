#include "graph.h"
#include <iostream>

using namespace std;

graph::graph(vector<vertex*> vertices)
	: vertices(vertices)
{
}

void graph::run(vertex* start)
{
	auto cmp = [](vertex* left, vertex* right) { return left->total_distance > right->total_distance; };
	priority_queue<vertex*, vector<vertex*>, decltype(cmp)> queue(cmp);

	for (vertex* v : vertices)
	{
		v->total_distance = INT_MAX;

		queue.push(v);
	}

	start->total_distance = 0;

	cout << "Vertex: " << start->id << ", Total distance: " << start->total_distance << endl;

	while (!queue.empty())
	{
		vertex* u = queue.top();

		queue.pop();

		u->visited = true;

		for (edge* connected_edge : u->edges)
		{
			if (connected_edge->to->visited)
			{
				continue;
			}

			if (u->total_distance == INT_MAX)
			{
				continue;
			}

			int distance = u->total_distance + connected_edge->weight;

			if (distance < connected_edge->to->total_distance)
			{
				connected_edge->to->total_distance = distance;

				cout << "Vertex: " << connected_edge->to->id << ", Total distance: " << connected_edge->to->total_distance << endl;
			}
		}
	}
}
