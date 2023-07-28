#pragma once
#include <queue>
#include <string>

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

	int total_distance;

	bool visited;

	vector<edge*> edges;
};

class edge
{
public:

	edge(vertex* to, int weight)
		: to(to), weight(weight) {};

	vertex* to;

	int weight;
};

class graph
{
public:

	graph(vector<vertex*> vertices);

	void run(vertex* start);

private:

	vector<vertex*> vertices;
};

