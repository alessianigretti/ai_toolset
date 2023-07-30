#include "builder.h"
#include "graph.h"

void builder::build_and_run()
{
	vertex* a = new vertex("a");
	vertex* b = new vertex("b");
	vertex* c = new vertex("c");
	vertex* d = new vertex("d");
	vertex* e = new vertex("e");
	vertex* f = new vertex("f");

	edge* a_b = new edge(b, 1);
	edge* a_c = new edge(c, 2);
	a->add_edge(a_b);
	a->add_edge(a_c);

	edge* b_c = new edge(c, 1);
	edge* b_d = new edge(d, 2);
	b->add_edge(b_c);
	b->add_edge(b_d);

	edge* c_d = new edge(d, 1);
	c->add_edge(c_d);

	edge* d_e = new edge(e, 2);
	d->add_edge(d_e);

	edge* e_f = new edge(f, 1);
	e->add_edge(e_f);

	graph* a_graph = new graph();
	
	a_graph->run(a, f);
}
