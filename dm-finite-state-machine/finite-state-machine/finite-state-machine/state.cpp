#include "state.h"
#include <iostream>

state::state(vector<transition*> transitions, string description)
{
    this->transitions = transitions;
    this->description = description;
}

vector<transition*> state::get_transitions()
{
    return transitions;
}

void state::describe_state()
{
    cout << description;
}