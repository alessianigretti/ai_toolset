#pragma once
#include "node.h"

class selector : public node
{
public:

	selector(vector<node*> children, string description);

	virtual bool execute(float& input) override;
};

