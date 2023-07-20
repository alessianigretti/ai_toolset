#include "selector.h"

selector::selector(vector<node*> children, string description)
{
	this->children = children;
	this->description = description;
}

bool selector::execute(float& input)
{
	describe_node();

	for (node* child : children)
	{
		if (child->execute(input))
		{
			return true;
		}
	}

	return false;
}
