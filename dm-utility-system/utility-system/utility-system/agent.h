#pragma once
#include "reasoner.h"
#include "state.h"
#include <vector>

using namespace std;

struct agent
{
public:

	agent(vector<state*> states)
		: states(states)
	{
	}

	void modify_or_add_state(state* new_state);

	vector<state*> get_states();

	void describe_state();

private:

	vector<state*> states;
};

