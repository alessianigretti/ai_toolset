#include "action.h"
#include <iostream>

using namespace std;

void action::describe_action()
{
    cout << description << endl;
    cout << "Current state:" << endl;
    
    for (state* state : effects)
    {
        cout << "- " << state->description << " " << endl;
    }

    cout << endl;
}

state* action::get_condition()
{
    return condition;
}

vector<state*> action::get_effects()
{
    return effects;
}
