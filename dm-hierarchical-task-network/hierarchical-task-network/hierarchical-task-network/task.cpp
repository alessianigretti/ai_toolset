#include "task.h"
#include "operation.h"
#include <iostream>

using namespace std;

task::~task()
{
}

void task::describe_task()
{
    cout << description;
}
