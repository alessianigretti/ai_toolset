#include "agent.h"
#include "state.h"
#include <iostream>

void agent::modify_or_add_state(state* new_state)
{
	for (state* agent_state : states)
	{
		if (new_state->attribute == agent_state->attribute)
		{
			agent_state->change_value(new_state->get_value(), new_state->get_description());

			return;
		}
	}

	states.push_back(new_state);
}

vector<state*> agent::get_states()
{
	return states;
}

void agent::describe_state()
{
	cout << "Current agent state:" << endl;

	for (state* state : states)
	{
		cout << "- " << state->get_description() << " (score " << state->get_value() << ")" << endl;
	}
}
