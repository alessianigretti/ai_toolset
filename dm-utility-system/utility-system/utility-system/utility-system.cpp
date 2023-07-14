// utility-system.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "builder.h"
#include "reasoner.h"

int main()
{
    builder* utility_builder = new builder();
    reasoner* reasoner = utility_builder->build();

    while (true)
    {
        cout << endl << "Press Enter to advance iteration..." << endl;

        cin.clear();
        cin.get();
        
        reasoner->run();
    }
}
