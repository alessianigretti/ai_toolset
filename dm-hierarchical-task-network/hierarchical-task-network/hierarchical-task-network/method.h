#pragma once
#include "task.h"
#include <vector>
#include <string>
#include "operation.h"

class method
{
public:
	
	method(vector<operation*> conditions, vector<task*> subtasks, string description);

	bool test_conditions(const float& input);

	vector<task*> get_subtasks();

	string get_description();

private:

	vector<task*> subtasks;

	vector<operation*> conditions;

	string description;
};

