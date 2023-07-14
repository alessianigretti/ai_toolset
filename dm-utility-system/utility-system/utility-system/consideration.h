#pragma once
#include "builder.h"
#include <string>

enum class attribute_type;

using namespace std;

enum class operation_type
{
	greater_than,
	greater_equal_than,
	less_than,
	less_equal_than,
	equal_to
};

struct consideration
{
public:
	
	consideration(attribute_type attribute, operation_type operation, float value, string name)
		: attribute(attribute), operation(operation), value(value), name(name)
	{
	}

	const attribute_type attribute;

	const operation_type operation;

	const float value;

	const string name;
};

