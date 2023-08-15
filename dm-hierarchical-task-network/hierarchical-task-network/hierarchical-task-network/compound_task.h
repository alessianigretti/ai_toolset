#pragma once
#include <vector>
#include <string>
#include <memory>
#include "method.h"
#include "task.h"

using namespace std;

class compound_task : public task
{
public:
	
	compound_task(const vector<shared_ptr<method>>& methods, string description);

	vector<shared_ptr<method>> get_methods();

	void describe_compound(const shared_ptr<method>& method);

private:

	vector<shared_ptr<method>> methods;
};

