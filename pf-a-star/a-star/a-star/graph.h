#pragma once
#include <string>
#include <queue>
#include <memory>

using namespace std;

class edge;

class vertex
{
public:

	vertex(string id)
		: id(id) {};

	void add_edge(const shared_ptr<edge>& connecting_edge)
	{
		edges.push_back(connecting_edge);
	}

	string id;

	int total_cost;

	int distance_from_start;
	
	int estimated_distance_to_end;

	vertex* parent;

	vector<shared_ptr<edge>> edges;
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

	edge(shared_ptr<vertex> to, int distance)
		: to(to), distance(distance) {};

	shared_ptr<vertex> to;

	int distance;
};

class graph
{
public:

	void run(const shared_ptr<vertex>& start, const shared_ptr<vertex>& end);

	bool contains(const priority_queue<vertex*, vector<vertex*>, cmp>& queue, const shared_ptr<vertex>& element_to_find);
};

