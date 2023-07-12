#pragma once
#include <vector>
#include <string>
#include "action.h"

using namespace std;

enum class state_type
{
	none,
	is_hungry,
	has_food,
	has_water,
	is_rested
};

struct state
{
	state_type state_type;

	bool value;

	string description;
};

class action;

class world_model
{
public:

	void apply_action(action* action);

	bool update_if_contained(state* effect);

	bool is_goal_fulfilled(state* goal);

	void clear();

	vector<state*> world_state;
};

