#pragma once
#include <string>
#include <vector>
#include "world_model.h"

struct state;

using namespace std;

class action
{
public:
	action(string description, state* condition, vector<state*> effects)
	{
		this->description = description;
		this->condition = condition;
		this->effects = effects;
	}

	void describe_action();

	state* get_condition();

	vector<state*> get_effects();

private:

	string description;

	state* condition;

	vector<state*> effects;
};

