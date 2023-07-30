#include "graph.h"
#include <iostream>

using namespace std;

void graph::run(vertex* start, vertex* end)
{
	priority_queue<vertex*, vector<vertex*>, cmp> open;
	priority_queue<vertex*, vector<vertex*>, cmp> closed;

	open.push(start);

	while (!open.empty())
	{
		vertex* current_vertex = open.top();

		open.pop();

		closed.push(current_vertex);

		if (current_vertex == end)
		{
			while (current_vertex != nullptr)
			{
				cout << current_vertex->id << " Cost: " << current_vertex->total_cost << endl;

				current_vertex = current_vertex->parent;
			}

			return;
		}

		for (edge* connected_edge : current_vertex->edges)
		{
			if (contains(closed, connected_edge->to))
			{
				continue;
			}

			if (!contains(open, connected_edge->to))
			{
				open.push(connected_edge->to);

				connected_edge->to->parent = current_vertex;

				connected_edge->to->distance_from_start = current_vertex->total_cost + connected_edge->distance;

				connected_edge->to->estimated_distance_to_end = ((connected_edge->to->distance_from_start - end->distance_from_start) ^ 2);

				connected_edge->to->total_cost = connected_edge->to->distance_from_start + connected_edge->to->estimated_distance_to_end;
			}
			else
			{
				if (connected_edge->to->distance_from_start > current_vertex->distance_from_start)
				{
					current_vertex->distance_from_start = connected_edge->to->distance_from_start;

					current_vertex->total_cost = current_vertex->distance_from_start + current_vertex->estimated_distance_to_end;

					connected_edge->to->parent = current_vertex;

					continue;
				}
			}

			open.push(connected_edge->to);
		}
	}
}

bool graph::contains(priority_queue<vertex*, vector<vertex*>, cmp> queue, vertex* element_to_find)
{
	priority_queue<vertex*, vector<vertex*>, cmp> temp_queue = priority_queue<vertex*, vector<vertex*>, cmp>(queue);

	while (!temp_queue.empty())
	{
		if (temp_queue.top() == element_to_find)
		{
			return true;
		}

		temp_queue.pop();
	}

	return false;
}
