#include "compound_task.h"
#include <iostream>

using namespace std;

compound_task::compound_task(const vector<shared_ptr<method>>& methods, string description)
    : methods(methods)
{
    this->description = description;
}

vector<shared_ptr<method>> compound_task::get_methods()
{
    return methods;
}

void compound_task::describe_compound(const shared_ptr<method>& method)
{
    cout << description << " " << method->get_description() << endl;
}
