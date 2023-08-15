#include "graph.h"
#include <iostream>
#include <memory>

using namespace std;

void graph::run(const shared_ptr<vertex>& start, const shared_ptr<vertex>& end)
{
	priority_queue<vertex*, vector<vertex*>, cmp> open;
	priority_queue<vertex*, vector<vertex*>, cmp> closed;

	open.push(start.get());

	while (!open.empty())
	{
		vertex* current_vertex = open.top();

		open.pop();

		closed.push(current_vertex);

		if (current_vertex == end.get())
		{
			while (current_vertex != nullptr)
			{
				cout << current_vertex->id << " Cost: " << current_vertex->total_cost << endl;

				current_vertex = current_vertex->parent;
			}

			return;
		}

		for (const shared_ptr<edge>& connected_edge : current_vertex->edges)
		{
			if (contains(closed, connected_edge->to))
			{
				continue;
			}

			if (!contains(open, connected_edge->to))
			{
				open.push(connected_edge->to.get());

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

			open.push(connected_edge->to.get());
		}
	}
}

bool graph::contains(const priority_queue<vertex*, vector<vertex*>, cmp>& queue, const shared_ptr<vertex>& element_to_find)
{
	priority_queue<vertex*, vector<vertex*>, cmp> temp_queue = priority_queue<vertex*, vector<vertex*>, cmp>(queue);

	while (!temp_queue.empty())
	{
		if (temp_queue.top() == element_to_find.get())
		{
			return true;
		}

		temp_queue.pop();
	}

	return false;
}
