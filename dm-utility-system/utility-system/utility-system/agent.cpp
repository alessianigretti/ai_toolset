#include "agent.h"
#include "state.h"
#include <iostream>

void agent::modify_or_add_state(const shared_ptr<state>& new_state)
{
	for (shared_ptr<state>& agent_state : states)
	{
		if (new_state->attribute == agent_state->attribute)
		{
			agent_state->change_value(new_state->get_value(), new_state->get_description());

			return;
		}
	}

	states.push_back(new_state);
}

vector<shared_ptr<state>> agent::get_states()
{
	return states;
}

void agent::describe_state()
{
	cout << "Current agent state:" << endl;

	for (const shared_ptr<state>& state : states)
	{
		cout << "- " << state->get_description() << " (score " << state->get_value() << ")" << endl;
	}
}
