#pragma once
#include <vector>
#include "world_model.h"
#include <memory>

class action;

using namespace std;

class builder
{
public:

	void build_goap();

	vector<shared_ptr<action>> plan_action();

	shared_ptr<state> get_initial_state();

	shared_ptr<state> get_final_state();

private:

	shared_ptr<action> get_action_fulfilling_goal(const shared_ptr<state>& goal_state);

	bool does_fulfill_goal(const shared_ptr<state>& goal_state, const shared_ptr<action>& action);

	vector<shared_ptr<action>> actions;
	
	shared_ptr<state> initial_state;

	shared_ptr<state> final_state;

	vector<shared_ptr<action>> reusable_plan;

	shared_ptr<world_model> reusable_world_model;
};

