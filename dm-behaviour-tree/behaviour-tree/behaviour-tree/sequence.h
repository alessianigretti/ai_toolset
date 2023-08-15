#pragma once
#include "node.h"

class sequence : public node
{
public:

	sequence(const vector<shared_ptr<node>>& children, string description);

	virtual bool execute(float& input) override;
};

