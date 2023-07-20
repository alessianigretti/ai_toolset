#include "decorator.h"


decorator::decorator(operation_type operation, float value)
    : operation(operation), value(value)
{
}

bool decorator::run_test(float& input)
{
    switch (operation)
    {
	    case operation_type::greater_equal_than:
        {
            return input >= value;
        }
        case operation_type::greater_than:
        {
            return input > value;
        }
        case operation_type::less_equal_than:
        {
            return input <= value;
        }
        case operation_type::less_than:
        {
            return input < value;
        }
        case operation_type::equal_to:
        {
            return input == value;
        }
    }
}
