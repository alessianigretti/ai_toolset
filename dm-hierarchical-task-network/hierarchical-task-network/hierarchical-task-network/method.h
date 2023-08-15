#pragma once
#include "task.h"
#include <vector>
#include <string>
#include <memory>
#include "operation.h"

class method
{
public:
	
	method(const vector<shared_ptr<operation>>& conditions, const vector<shared_ptr<task>>& subtasks, string description);

	bool test_conditions(const float& input);

	vector<shared_ptr<task>> get_subtasks();

	string get_description();

private:

	vector<shared_ptr<task>> subtasks;

	vector<shared_ptr<operation>> conditions;

	string description;
};

