#pragma once
#include <utility>
#include <list>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class node
{
public:

	node(string id)
		: id(id) {};

	string id;

	int total_distance;
};

class edge
{
public:

	edge(const shared_ptr<node>& from, const shared_ptr<node>& to, int distance)
		: from(from), to(to), distance(distance) {};

	shared_ptr<node> from;

	shared_ptr<node> to;

	int distance;
};

class graph
{
public:

	graph(const vector<shared_ptr<node>>& vertices, const vector<shared_ptr<edge>>& edges);

	void run();

private:

	vector<shared_ptr<node>> vertices;

	vector<shared_ptr<edge>> edges;
};

