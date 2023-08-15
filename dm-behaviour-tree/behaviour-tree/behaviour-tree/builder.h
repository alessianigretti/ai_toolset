#pragma once
#include <vector>
#include "node.h"
#include <memory>

using namespace std; 

class builder
{
public:

	void build_tree();

	void run(float& input);

private:
	
	shared_ptr<node> root_node;
};

