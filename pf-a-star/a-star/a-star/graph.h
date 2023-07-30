#pragma once
#include <string>
#include <queue>

using namespace std;

class edge;

class vertex
{
public:

	vertex(string id)
		: id(id) {};

	void add_edge(edge* connecting_edge)
	{
		edges.push_back(connecting_edge);
	}

	string id;

	int total_cost;

	int distance_from_start;
	
	int estimated_distance_to_end;

	vertex* parent;

	vector<edge*> edges;
};

struct cmp {
	constexpr bool operator()(
		vertex* a,
		vertex* b)
		const noexcept
	{
		return a->total_cost > b->total_cost;
	}
};

class edge
{
public:

	edge(vertex* to, int distance)
		: to(to), distance(distance) {};

	vertex* to;

	int distance;
};

class graph
{
public:

	void run(vertex* start, vertex* end);

	bool contains(priority_queue<vertex*, vector<vertex*>, cmp> queue, vertex* element_to_find);
};

