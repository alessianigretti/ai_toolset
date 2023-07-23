#include "builder.h"

void builder::build_and_run()
{
	graph* dfs_graph = new graph(5);

	dfs_graph->add_edge(0, 1);
	dfs_graph->add_edge(0, 2);
	dfs_graph->add_edge(0, 3);
	dfs_graph->add_edge(1, 2);
	dfs_graph->add_edge(2, 4);

	dfs_graph->run_dfs(0);
}