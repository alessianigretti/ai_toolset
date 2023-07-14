#pragma once
#include "consideration.h"
#include "state.h"
#include <string>
#include <vector>

using namespace std;

struct action
{
public:

	action(vector<consideration*> considerations, vector<state*> effects, string description)
		: considerations(considerations), effects(effects), description(description)
	{
	}

	const vector<consideration*> considerations;

	const vector<state*> effects;

	const string description;
};

