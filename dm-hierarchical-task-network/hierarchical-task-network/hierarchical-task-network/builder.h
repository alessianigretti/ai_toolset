#pragma once
#include <stack>
#include "task.h"

using namespace std;

class builder
{
public:

	void build_htn();

	vector<task*> run(float& input);

private:

	stack<task*> tasks_to_process;
};

