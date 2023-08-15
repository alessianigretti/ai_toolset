#pragma once
#include <string>
#include <vector>
#include <memory>
#include "world_model.h"

struct state;

using namespace std;

class action
{
public:
	action(string description, shared_ptr<state> condition, vector<shared_ptr<state>> effects)
	{
		this->description = description;
		this->condition = condition;
		this->effects = effects;
	}

	void describe_action();

	shared_ptr<state> get_condition();

	vector<shared_ptr<state>> get_effects();

private:

	string description;

	shared_ptr<state> condition;

	vector<shared_ptr<state>> effects;
};

