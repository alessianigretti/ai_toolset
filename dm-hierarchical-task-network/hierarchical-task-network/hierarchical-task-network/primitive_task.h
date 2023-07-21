#pragma once
#include "task.h"
#include <vector>
#include "operation.h"
#include "method.h"
#include <string>

class primitive_task : public task
{
public:
	
	primitive_task(float effect, string description);

	void apply_effect(float& input);

	bool test_condition(const float& input);

private:

	operation* condition;

	float effect;
};

