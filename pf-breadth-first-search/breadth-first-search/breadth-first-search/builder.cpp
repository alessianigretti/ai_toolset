#include "builder.h"

void builder::build_and_run()
{
	graph* bfs_graph = new graph(5);

	bfs_graph->add_edge(0, 1);
	bfs_graph->add_edge(0, 2);
	bfs_graph->add_edge(0, 3);
	bfs_graph->add_edge(1, 2);
	bfs_graph->add_edge(2, 4);

	bfs_graph->run_bfs(0);
}