#pragma once
#include <vector>
#include "world_model.h"

class action;

using namespace std;

class builder
{
public:

	void build_goap();

	vector<action*> plan_action();

	state* get_initial_state();

	state* get_final_state();

private:

	action* get_action_fulfilling_goal(state goal_state);

	bool does_fulfill_goal(state goal_state, action* action);

	vector<action*> actions;
	
	state initial_state;

	state final_state;

	vector<action*> reusable_plan;

	world_model* reusable_world_model;
};

