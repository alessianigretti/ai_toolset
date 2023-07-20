#pragma once
#include "node.h"
#include <string>
#include <vector>
#include "decorator.h"

using namespace std;

class node
{
public:

	vector<node*> get_children();

	void describe_node();

	void add_decorator(decorator* decorator);

	vector<decorator*> get_decorators();

	virtual bool execute(float& input) = 0;

protected:

	string description;

	vector<node*> children;

	vector<decorator*> decorators;
};

