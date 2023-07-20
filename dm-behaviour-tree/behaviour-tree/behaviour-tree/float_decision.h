#pragma once
#include "decision.h"

class float_decision : public decision
{
public:

	float_decision(string description);

	void initialise_float_decision(float min_value, float max_value);

	float get_min_value();

	float get_max_value();

protected:

	node* make_decision(float input) override;

private:

	float min_value;

	float max_value;
};

