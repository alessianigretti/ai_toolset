#pragma once
#include "action.h"

class move_action : public action
{
public:

	move_action(vector<node*> children, string description);

	bool execute(float& input) override;
};

