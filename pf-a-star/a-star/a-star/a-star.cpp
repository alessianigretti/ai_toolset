// a-star.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "builder.h"

int main()
{
    builder* a_builder = new builder();
    
    a_builder->build_and_run();
}
