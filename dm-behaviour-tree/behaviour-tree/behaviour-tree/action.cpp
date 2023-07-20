#include "action.h"

action::action(string description, float cost)
{
	this->description = description;
	this->cost = cost;
}

bool action::execute(float& input)
{
	for (decorator* decorator : get_decorators())
	{
		if (!decorator->run_test(input))
		{
			return false;
		}
	}

	describe_node();

	input -= cost;

	return true;
}