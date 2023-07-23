#pragma once
#include <list>
#include <string>

using namespace std;

class graph
{
public:

	graph(int vertices_amount);

	void run_dfs(int start);

	void add_edge(int source, int destination);

private:

	list<int>* edges;

	bool* visited;
};

