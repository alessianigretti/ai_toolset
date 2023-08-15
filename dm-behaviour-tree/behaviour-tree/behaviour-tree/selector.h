#pragma once
#include "node.h"
#include <memory>

using namespace std;

class selector : public node
{
public:

	selector(const vector<shared_ptr<node>>& children, string description);

	virtual bool execute(float& input) override;
};

