#pragma once
#include <vector>
#include <string>
#include <memory>

class transition;

using namespace std;

class state
{
public:

    state(const vector<shared_ptr<transition>>& transitions, string description);

    vector<shared_ptr<transition>> get_transitions();

    void describe_state();

private:

    vector<shared_ptr<transition>> transitions;

    string description;
};

