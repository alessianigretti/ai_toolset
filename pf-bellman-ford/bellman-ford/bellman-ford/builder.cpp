#include "builder.h"
#include <memory>

using namespace std;

void builder::build_and_run()
{
    shared_ptr<node> a = shared_ptr<node>(new node("a"));
    shared_ptr<node> b = shared_ptr<node>(new node("b"));
    shared_ptr<node> c = shared_ptr<node>(new node("c"));
    shared_ptr<node> d = shared_ptr<node>(new node("d"));
    shared_ptr<node> e = shared_ptr<node>(new node("e"));

    shared_ptr<edge> a_b = shared_ptr<edge>(new edge(a, b, 4));
    shared_ptr<edge> a_c = shared_ptr<edge>(new edge(a, c, 2));
    shared_ptr<edge> b_c = shared_ptr<edge>(new edge(b, c, 3));
    shared_ptr<edge> b_d = shared_ptr<edge>(new edge(b, d, 2));
    shared_ptr<edge> b_e = shared_ptr<edge>(new edge(b, e, 3));
    shared_ptr<edge> c_b = shared_ptr<edge>(new edge(c, b, 1));
    shared_ptr<edge> c_d = shared_ptr<edge>(new edge(c, d, 4));
    shared_ptr<edge> c_e = shared_ptr<edge>(new edge(c, e, 5));
    shared_ptr<edge> e_d = shared_ptr<edge>(new edge(e, d, -5));

    shared_ptr<graph> bf_graph = shared_ptr<graph>(new graph({ a, b, c, d, e }, { a_b, a_c, b_c, b_d, b_e, c_b, c_d, c_e, e_d }));

    bf_graph->run();
}
