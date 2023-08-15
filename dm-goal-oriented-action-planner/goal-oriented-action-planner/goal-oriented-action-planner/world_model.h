#pragma once
#include <vector>
#include <string>
#include "action.h"
#include <memory>

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

	void apply_action(const shared_ptr<action>& action);

	bool update_if_contained(const shared_ptr<state>& effect);

	bool is_goal_fulfilled(const shared_ptr<state>& goal);

	void clear();

	vector<shared_ptr<state>> world_state;
};

