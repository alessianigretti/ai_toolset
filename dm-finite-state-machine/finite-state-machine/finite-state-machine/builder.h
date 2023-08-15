#pragma once
#include "state.h"

class builder
{
public:

    shared_ptr<state> build_fsm();
};

