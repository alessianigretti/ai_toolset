#include "graph.h"
#include <iostream>
#include "builder.h"

using namespace std;

graph::graph(const vector<shared_ptr<node>>& vertices, const vector<shared_ptr<edge>>& edges)
	: vertices(vertices), edges(edges)
{
}

void graph::run()
{
	for (shared_ptr<node>& vertex : vertices)
	{
		vertex->total_distance = INT_MAX;
	}

	vertices[0]->total_distance = 0;

	cout << "Node: " << vertices[0]->id << ", Total Distance: " << vertices[0]->total_distance << endl;
	
	for (int v = 0; v < vertices.size(); v++)
	{
		cout << "Iteration: " << v << endl;

		for (int e = 0; e < edges.size(); e++)
		{
			shared_ptr<edge> edge = edges[e];

			if (edge->from->total_distance != INT_MAX &&
				edge->from->total_distance + edge->distance < edge->to->total_distance)
			{
				edge->to->total_distance = edge->from->total_distance + edge->distance;

				cout << "Node: " << edge->to->id << ", Total Distance: " << edge->to->total_distance << endl;
			}
		}
	}

	for (int v = 0; v < vertices.size(); v++)
	{
		for (int e = 0; e < edges.size(); e++)
		{
			shared_ptr<edge> edge = edges[e];

			if (edge->from->total_distance != INT_MAX &&
				edge->from->total_distance + edge->distance < edge->to->total_distance)
			{
				return;
			}
		}
	}

	for (const shared_ptr<node>& vertex : vertices)
	{
		cout << "Node: " << vertex->id << ", Final distance: " << vertex->total_distance << endl;
	}
}