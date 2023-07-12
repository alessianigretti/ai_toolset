#pragma once
#include <string>

class state;

using namespace std;

class transition
{
public:

    transition(string description)
    {
        this->description = description;
    }

    void set_target_state(state* target_state);

    state* get_target_state();

    void describe_transition();

private:

    state* target_state;

    string description;
};

