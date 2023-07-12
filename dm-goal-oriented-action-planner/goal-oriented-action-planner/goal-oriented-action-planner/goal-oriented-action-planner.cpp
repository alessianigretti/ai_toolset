// goal-oriented-action-planner.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "builder.h"

int main()
{
    cout << "Goal Oriented Action Planner Demo" << endl;
    system("pause");

    builder* goap_builder = new builder();
    goap_builder->build_goap();

    cout << "Planner built." << endl << endl;

    cout << "Initial state: " << goap_builder->get_initial_state()->description << endl;
    cout << "Goal state: " << goap_builder->get_final_state()->description << endl;
    cout << endl << "Executing plan..." << endl << endl;

    goap_builder->plan_action();
}
