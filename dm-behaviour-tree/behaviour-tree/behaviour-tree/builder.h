#pragma once
#include <vector>
#include "node.h"

using namespace std; 

class builder
{
public:

	void build_tree();

	void run(float& input);

private:
	
	node* root_node;
};

