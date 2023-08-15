#pragma once
#include "reasoner.h"
#include "state.h"
#include <vector>

using namespace std;

struct agent
{
public:

	agent(const vector<shared_ptr<state>>& states)
		: states(states)
	{
	}

	void modify_or_add_state(const shared_ptr<state>& new_state);

	vector<shared_ptr<state>> get_states();

	void describe_state();

private:

	vector<shared_ptr<state>> states;
};

