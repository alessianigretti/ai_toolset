#pragma once
#include <queue>
#include <string>
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

	int total_distance;

	bool visited;

	vector<shared_ptr<edge>> edges;
};

class edge
{
public:

	edge(const shared_ptr<vertex>& to, int weight)
		: to(to), weight(weight) {};

	shared_ptr<vertex> to;

	int weight;
};

class graph
{
public:

	graph(const vector<shared_ptr<vertex>>& vertices);

	void run(const shared_ptr<vertex>& start);

private:

	vector<shared_ptr<vertex>> vertices;
};

