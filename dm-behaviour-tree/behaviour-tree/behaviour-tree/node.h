#pragma once
#include "node.h"
#include <string>
#include <vector>
#include "decorator.h"
#include <memory>

using namespace std;

class node
{
public:

	vector<shared_ptr<node>> get_children();

	void describe_node();

	void add_decorator(const shared_ptr<decorator>& decorator);

	vector<shared_ptr<decorator>> get_decorators();

	virtual bool execute(float& input) = 0;

protected:

	string description;

	vector<shared_ptr<node>> children;

	vector<shared_ptr<decorator>> decorators;
};

