#include "compound_task.h"
#include <iostream>

using namespace std;

compound_task::compound_task(vector<method*> methods, string description)
    : methods(methods)
{
    this->description = description;
}

vector<method*> compound_task::get_methods()
{
    return methods;
}

void compound_task::describe_compound(method* method)
{
    cout << description << " " << method->get_description() << endl;
}
