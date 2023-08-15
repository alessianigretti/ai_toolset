#pragma once
#include <stack>
#include <memory>
#include "task.h"

using namespace std;

class builder
{
public:

	void build_htn();

	vector<shared_ptr<task>> run(float& input);

private:

	stack<shared_ptr<task>> tasks_to_process;
};

