#include "node.h"
#include <iostream>
#include <vector>

using namespace std;

vector<node*> node::get_children()
{
	return children;
}

void node::describe_node()
{
	cout << description << endl;
}

void node::add_decorator(decorator* decorator)
{
	decorators.push_back(decorator);
}

vector<decorator*> node::get_decorators()
{
	return decorators;
}
