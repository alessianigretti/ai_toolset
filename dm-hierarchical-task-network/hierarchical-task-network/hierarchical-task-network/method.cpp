#include "method.h"

method::method(vector<operation*> conditions, vector<task*> subtasks, string description)
    : conditions(conditions), subtasks(subtasks), description(description)
{
}

bool method::test_conditions(const float& input)
{
    if (conditions.empty())
    {
        return true;
    }

    for (operation* op : conditions)
    {
        switch (op->get_operation_type())
        {
            case operation_type::greater_equal_than:
            {
                return input >= op->get_value();
            }
            case operation_type::greater_than:
            {
                return input > op->get_value();
            }
            case operation_type::less_equal_than:
            {
                return input <= op->get_value();
            }
            case operation_type::less_than:
            {
                return input < op->get_value();
            }
            case operation_type::equal_to:
            {
                return input == op->get_value();
            }
        }
    }

    return true;
}

vector<task*> method::get_subtasks()
{
    return subtasks;
}

string method::get_description()
{
    return description;
}
