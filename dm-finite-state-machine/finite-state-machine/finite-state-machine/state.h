#pragma once
#include <vector>
#include <string>

class transition;

using namespace std;

class state
{
public:

    state(vector<transition*> transitions, string description);

    vector<transition*> get_transitions();

    void describe_state();

private:

    vector<transition*> transitions;

    string description;
};

