#include "builder.h"

void builder::build_and_run()
{
    node* a = new node("a");
    node* b = new node("b");
    node* c = new node("c");
    node* d = new node("d");
    node* e = new node("e");

    edge* a_b = new edge(a, b, 4);
    edge* a_c = new edge(a, c, 2);
    edge* b_c = new edge(b, c, 3);
    edge* b_d = new edge(b, d, 2);
    edge* b_e = new edge(b, e, 3);
    edge* c_b = new edge(c, b, 1);
    edge* c_d = new edge(c, d, 4);
    edge* c_e = new edge(c, e, 5);
    edge* e_d = new edge(e, d, -5);

    graph* bf_graph = new graph({ a, b, c, d, e }, { a_b, a_c, b_c, b_d, b_e, c_b, c_d, c_e, e_d });

    bf_graph->run();
}
