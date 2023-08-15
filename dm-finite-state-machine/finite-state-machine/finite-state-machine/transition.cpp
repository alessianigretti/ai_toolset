#include "transition.h"
#include <iostream>
#include <memory>

using namespace std;

void transition::set_target_state(const shared_ptr<state>& target_state)
{
    this->target_state = target_state;
}

shared_ptr<state> transition::get_target_state()
{
    return target_state;
}

void transition::describe_transition()
{
    cout << description;
}
