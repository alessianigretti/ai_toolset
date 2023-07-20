#include "sequence.h"

sequence::sequence(vector<node*> children, string description)
{
	this->children = children;
	this->description = description;
}

bool sequence::execute(float& input)
{
	describe_node();

	for (node* child : children)
	{
		if (!child->execute(input))
		{
			return true;
		}
	}

	return false;
}
