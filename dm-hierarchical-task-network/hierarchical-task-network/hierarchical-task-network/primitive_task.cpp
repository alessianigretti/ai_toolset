#include "primitive_task.h"
#include <iostream>

using namespace std;

primitive_task::primitive_task(float effect, string description)
    : effect(effect)
{
    this->description = description;
}

void primitive_task::apply_effect(float& input)
{
    input += effect;

    cout << " (Updated stamina: " << input << ")" << endl;
}

bool primitive_task::test_condition(const float& input)
{
    if (condition == nullptr)
    {
        return true;
    }

    switch (condition->get_operation_type())
    {
        case operation_type::greater_equal_than:
        {
            return input >= condition->get_value();
        }
        case operation_type::greater_than:
        {
            return input > condition->get_value();
        }
        case operation_type::less_equal_than:
        {
            return input <= condition->get_value();
        }
        case operation_type::less_than:
        {
            return input < condition->get_value();
        }
        case operation_type::equal_to:
        {
            return input == condition->get_value();
        }
    }

    return true;
}
