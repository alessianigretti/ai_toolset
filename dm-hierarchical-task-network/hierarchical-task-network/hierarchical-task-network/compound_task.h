#pragma once
#include <vector>
#include <string>
#include "method.h"
#include "task.h"

using namespace std;

class compound_task : public task
{
public:
	
	compound_task(vector<method*> methods, string description);

	vector<method*> get_methods();

	void describe_compound(method* method);

private:

	vector<method*> methods;
};

