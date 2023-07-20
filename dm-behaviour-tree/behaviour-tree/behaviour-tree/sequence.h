#pragma once
#include "node.h"

class sequence : public node
{
public:

	sequence(vector<node*> children, string description);

	virtual bool execute(float& input) override;
};

