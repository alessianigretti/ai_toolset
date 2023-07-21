#pragma once
#include <vector>
#include <string>

using namespace std;

class task
{
public:

	virtual ~task();

	void describe_task();

protected:

	float effect;

	string description;
};

