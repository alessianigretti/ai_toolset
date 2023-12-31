#include "graph.h"
#include <iostream>

using namespace std;

graph::graph(const vector<shared_ptr<vertex>>& vertices)
	: vertices(vertices)
{
}

void graph::run(const shared_ptr<vertex>& start)
{
	auto cmp = [](shared_ptr<vertex> left, shared_ptr<vertex> right) { return left->total_distance > right->total_distance; };
	priority_queue<shared_ptr<vertex>, vector<shared_ptr<vertex>>, decltype(cmp)> queue(cmp);

	for (shared_ptr<vertex> v : vertices)
	{
		v->total_distance = INT_MAX;

		queue.push(v);
	}

	start->total_distance = 0;

	cout << "Vertex: " << start->id << ", Total distance: " << start->total_distance << endl;

	while (!queue.empty())
	{
		shared_ptr<vertex> u = queue.top();

		queue.pop();

		u->visited = true;

		for (shared_ptr<edge> connected_edge : u->edges)
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
