#pragma once

enum class operation_type
{
	greater_than,
	greater_equal_than,
	less_than,
	less_equal_than,
	equal_to
};

class decorator
{
public:

	decorator(operation_type operation, float value);

	bool run_test(float& input);

private:

	operation_type operation;

	float value;
};

