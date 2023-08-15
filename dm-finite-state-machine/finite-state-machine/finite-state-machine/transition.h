#pragma once
#include <string>
#include <memory>

class state;

using namespace std;

class transition
{
public:

    transition(string description)
    {
        this->description = description;
    }

    void set_target_state(const shared_ptr<state>& target_state);

    shared_ptr<state> get_target_state();

    void describe_transition();

private:

    shared_ptr<state> target_state;

    string description;
};

