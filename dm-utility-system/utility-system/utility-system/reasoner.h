#pragma once
#include <string>
#include <vector>
#include "action.h"
#include "state.h"

struct agent;

using namespace std;

enum class attribute_type
{
	hunger,
	thirst,
	tiredness,
	boredom
};

class reasoner
{
public:

	reasoner(agent* acting_agent, vector<action*> executable_actions)
	{
		this->acting_agent = acting_agent;
		this->executable_actions = executable_actions;
	}

	void run();

private:

	float score(action* action);

	void select(action* action);

	agent* acting_agent;

	vector<action*> executable_actions;
};

