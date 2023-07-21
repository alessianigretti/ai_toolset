#pragma once

enum class operation_type
{
	greater_than,
	greater_equal_than,
	less_than,
	less_equal_than,
	equal_to
};

class operation
{
public:

	operation(operation_type op, float value);

	operation_type get_operation_type();

	float get_value();

private:

	operation_type op;

	float value;
};
