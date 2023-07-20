#include "move_action.h"

move_action::move_action(vector<node*> children, string description)
{
	this->children = children;
	this->description = description;
}

bool move_action::execute()
{
	describe_node();

	return false;
}
