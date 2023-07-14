#pragma once
#include <string>

enum class attribute_type;

using namespace std;

struct state
{
public:

	state(attribute_type attribute, float value, string description)
		: attribute(attribute), value(value), description(description)
	{
	}

	void change_value(float new_value, string new_description);

	float get_value();

	string get_description();

	const attribute_type attribute;

private:

	float value;

	string description;
};
