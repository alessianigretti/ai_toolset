#include "sequence.h"
#include <memory>

using namespace std;

sequence::sequence(const vector<shared_ptr<node>>& children, string description)
{
	this->children = children;
	this->description = description;
}

bool sequence::execute(float& input)
{
	describe_node();

	for (shared_ptr<node> child : children)
	{
		if (!child->execute(input))
		{
			return true;
		}
	}

	return false;
}
