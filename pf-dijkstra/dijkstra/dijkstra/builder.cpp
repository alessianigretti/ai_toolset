#include "builder.h"
#include "graph.h"
#include <memory>

using namespace std;

void builder::build_and_run()
{
	shared_ptr<vertex> a = shared_ptr<vertex>(new vertex("a"));
	shared_ptr<vertex> b = shared_ptr<vertex>(new vertex("b"));
	shared_ptr<vertex> c = shared_ptr<vertex>(new vertex("c"));
	shared_ptr<vertex> d = shared_ptr<vertex>(new vertex("d"));
	shared_ptr<vertex> e = shared_ptr<vertex>(new vertex("e"));
	shared_ptr<vertex> f = shared_ptr<vertex>(new vertex("f"));

	shared_ptr<edge> a_b = shared_ptr<edge>(new edge(b, 4));
	shared_ptr<edge> a_c = shared_ptr<edge>(new edge(c, 4));
	a->add_edge(a_b);
	a->add_edge(a_c);

	shared_ptr<edge> b_c = shared_ptr<edge>(new edge(c, 2));
	b->add_edge(b_c);

	shared_ptr<edge> c_d = shared_ptr<edge>(new edge(d, 3));
	shared_ptr<edge> c_e = shared_ptr<edge>(new edge(e, 1));
	shared_ptr<edge> c_f = shared_ptr<edge>(new edge(f, 6));
	c->add_edge(c_d);
	c->add_edge(c_e);
	c->add_edge(c_f);

	shared_ptr<edge> d_f = shared_ptr<edge>(new edge(f, 2));
	d->add_edge(d_f);

	shared_ptr<edge> e_f = shared_ptr<edge>(new edge(f, 3));
	e->add_edge(e_f);

	graph* d_graph = new graph({a, b, c, d, e, f});

	d_graph->run(a);
}