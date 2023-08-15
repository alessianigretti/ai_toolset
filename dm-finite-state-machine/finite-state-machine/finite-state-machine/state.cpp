#include "state.h"
#include <iostream>
#include <memory>

using namespace std;

state::state(const vector<shared_ptr<transition>>& transitions, string description)
{
    this->transitions = transitions;
    this->description = description;
}

vector<shared_ptr<transition>> state::get_transitions()
{
    return transitions;
}

void state::describe_state()
{
    cout << description;
}