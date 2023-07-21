// hierarchical-task-network.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "builder.h"

int main()
{
    builder* htn_builder = new builder();

    float current_stamina = 1.f;

    while (true)
    {
        htn_builder->build_htn();
        
        vector<task*> final_plan = htn_builder->run(current_stamina);

        cout << endl << "Press Enter to run again..." << endl;

        cin.clear();
        cin.get();
    }
}