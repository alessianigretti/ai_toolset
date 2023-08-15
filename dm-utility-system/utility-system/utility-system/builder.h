#pragma once
#include <memory>

using namespace std;

class reasoner;

class builder
{
public:

	shared_ptr<reasoner> build();
};

