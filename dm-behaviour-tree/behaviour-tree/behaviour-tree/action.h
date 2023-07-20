#pragma once
#include "node.h"

class action : public node
{
public:

	action(string description, float cost);

	virtual bool execute(float& input) override;

private:

	float cost;
};