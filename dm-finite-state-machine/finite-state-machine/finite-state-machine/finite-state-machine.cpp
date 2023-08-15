// finite-state-machine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "stdio.h"
#include "builder.h"
#include "transition.h"

class state;

using namespace std;

int main()
{
    cout << "Finite State Machine Demo" << endl;

    shared_ptr<builder> b = shared_ptr<builder>(new builder());
    shared_ptr<state> current_state = b->build_fsm();

    while (true)
    {
        cout << "Current state: ";
        current_state->describe_state();
        cout << endl;

        if (current_state->get_transitions().size() == 0)
        {
            return 0;
        }

        cout << "Choose an option: " << endl;

        for (int i = 0; i < current_state->get_transitions().size(); i++)
        {
            cout << i << " ";
            current_state->get_transitions().at(i)->describe_transition();
            cout << endl;
        }

        char c;
        cin >> c;
        int chosen_transition_index = c - '0';

        cout << "Option chosen: " << chosen_transition_index << endl;

        current_state = current_state->get_transitions().at(chosen_transition_index)->get_target_state();
    }

    return 0;
}
