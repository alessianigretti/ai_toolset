#pragma once
#include "consideration.h"
#include "state.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;

struct action
{
public:

	action(const vector<shared_ptr<consideration>>& considerations, const vector<shared_ptr<state>>& effects, string description)
		: considerations(considerations), effects(effects), description(description)
	{
	}

	const vector<shared_ptr<consideration>> considerations;

	const vector<shared_ptr<state>> effects;

	const string description;
};

