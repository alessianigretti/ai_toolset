#include "transition.h"
#include <iostream>

void transition::set_target_state(state* target_state)
{
    this->target_state = target_state;
}

state* transition::get_target_state()
{
    return target_state;
}

void transition::describe_transition()
{
    cout << description;
}
