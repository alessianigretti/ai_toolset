#pragma once
#include <utility>
#include <list>
#include <vector>
#include <string>

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

	edge(node* from, node* to, int distance)
		: from(from), to(to), distance(distance) {};

	node* from;

	node* to;

	int distance;
};

class graph
{
public:

	graph(vector<node*> vertices, vector<edge*> edges);

	void run();

private:

	vector<node*> vertices;

	vector<edge*> edges;
};

