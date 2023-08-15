// bellman-ford.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "builder.h"

using namespace std;

int main()
{
    shared_ptr<builder> sp_builder = shared_ptr<builder>(new builder());
    
    sp_builder->build_and_run();
}
