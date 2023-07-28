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

	edge* a_b = new edge(b, 4);
	edge* a_c = new edge(c, 4);
	a->add_edge(a_b);
	a->add_edge(a_c);

	edge* b_c = new edge(c, 2);
	b->add_edge(b_c);

	edge* c_d = new edge(d, 3);
	edge* c_e = new edge(e, 1);
	edge* c_f = new edge(f, 6);
	c->add_edge(c_d);
	c->add_edge(c_e);
	c->add_edge(c_f);

	edge* d_f = new edge(f, 2);
	d->add_edge(d_f);

	edge* e_f = new edge(f, 3);
	e->add_edge(e_f);

	graph* d_graph = new graph({a, b, c, d, e, f});

	d_graph->run(a);
}