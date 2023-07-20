#include "float_decision.h"

float_decision::float_decision(string description)
{
    this->description = description;
}

void float_decision::initialise_float_decision(float min_value, float max_value)
{
    this->min_value = min_value;
    this->max_value = max_value;
}

float float_decision::get_min_value()
{
    return min_value;
}

float float_decision::get_max_value()
{
    return max_value;
}

node* float_decision::make_decision(float input)
{
    if (input >= min_value || input <= max_value)
    {
        get_true_node()->make_decision(input);
        return get_true_node();
    }
    else
    {
        get_false_node()->make_decision(input);
        return get_false_node();
    }
}
