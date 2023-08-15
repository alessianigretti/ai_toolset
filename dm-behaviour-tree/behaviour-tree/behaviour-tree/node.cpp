#include "node.h"
#include <iostream>
#include <vector>

using namespace std;

vector<shared_ptr<node>> node::get_children()
{
	return children;
}

void node::describe_node()
{
	cout << description << endl;
}

void node::add_decorator(const shared_ptr<decorator>& decorator)
{
	decorators.push_back(decorator);
}

vector<shared_ptr<decorator>> node::get_decorators()
{
	return decorators;
}
