#include "action.h"
#include <iostream>

using namespace std;

void action::describe_action()
{
    cout << description << endl;
    cout << "Current state:" << endl;
    
    for (shared_ptr<state> state : effects)
    {
        cout << "- " << state->description << " " << endl;
    }

    cout << endl;
}

shared_ptr<state> action::get_condition()
{
    return condition;
}

vector<shared_ptr<state>> action::get_effects()
{
    return effects;
}
