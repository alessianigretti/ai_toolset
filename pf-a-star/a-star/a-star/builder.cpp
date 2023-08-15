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

	shared_ptr<edge> a_b = shared_ptr<edge>(new edge(b, 1));
	shared_ptr<edge> a_c = shared_ptr<edge>(new edge(c, 2));
	a->add_edge(a_b);
	a->add_edge(a_c);

	shared_ptr<edge> b_c = shared_ptr<edge>(new edge(c, 1));
	shared_ptr<edge> b_d = shared_ptr<edge>(new edge(d, 2));
	b->add_edge(b_c);
	b->add_edge(b_d);

	shared_ptr<edge> c_d = shared_ptr<edge>(new edge(d, 1));
	c->add_edge(c_d);

	shared_ptr<edge> d_e = shared_ptr<edge>(new edge(e, 2));
	d->add_edge(d_e);

	shared_ptr<edge> e_f = shared_ptr<edge>(new edge(f, 1));
	e->add_edge(e_f);

	shared_ptr<graph> a_graph = shared_ptr<graph>(new graph());
	
	a_graph->run(a, f);
}
