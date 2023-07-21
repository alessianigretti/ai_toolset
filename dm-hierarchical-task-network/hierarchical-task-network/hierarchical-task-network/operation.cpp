#include "operation.h"

enum class operation_type;

operation::operation(operation_type op, float value)
    : op(op), value(value)
{
}

operation_type operation::get_operation_type()
{
    return op;
}

float operation::get_value()
{
    return value;
}
