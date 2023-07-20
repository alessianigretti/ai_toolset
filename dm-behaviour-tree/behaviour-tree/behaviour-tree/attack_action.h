#pragma once
#include "action.h"

class attack_action : public action
{
public:

	attack_action(vector<node*> children, string description);

	bool execute(float& input) override;
};