#pragma once
#include <string>
#include <vector>
#include <memory>
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

	reasoner(shared_ptr<agent> acting_agent, const vector<shared_ptr<action>>& executable_actions)
	{
		this->acting_agent = acting_agent;
		this->executable_actions = executable_actions;
	}

	void run();

private:

	float score(const shared_ptr<action>& action);

	void select(const shared_ptr<action>& action);

	shared_ptr<agent> acting_agent;

	vector<shared_ptr<action>> executable_actions;
};

