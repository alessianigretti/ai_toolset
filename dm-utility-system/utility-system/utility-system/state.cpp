#include "state.h"

void state::change_value(float new_value, string new_description)
{
    value = new_value;
    description = new_description;
}

float state::get_value()
{
    return value;
}

string state::get_description()
{
    return description;
}
