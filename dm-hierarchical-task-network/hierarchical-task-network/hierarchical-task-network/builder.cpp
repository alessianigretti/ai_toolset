#include "builder.h"
#include <typeinfo>
#include "primitive_task.h"
#include "compound_task.h"

using namespace std;

void builder::build_htn()
{
	primitive_task* task_taunt = new primitive_task(0.f, "- Task: Taunt");
	primitive_task* task_super_slam = new primitive_task(-0.5f, "- Task: Super Slam");
	primitive_task* task_tell = new primitive_task(0.f, "- Task: Tell");
	primitive_task* task_slam = new primitive_task(-0.3f, "- Task: Slam");
	primitive_task* task_recover = new primitive_task(0.1f, "- Task: Recover");
	primitive_task* task_nav_to_enemy = new primitive_task(0.f, "- Task: Nav To Enemy");
	operation* condition_has_much_stamina = new operation(operation_type::greater_equal_than, 0.8f);
	method* method_trunk_slam_0 = new method({ condition_has_much_stamina }, { task_super_slam, task_taunt }, "(Method 0)");
	operation* condition_has_some_stamina = new operation(operation_type::greater_equal_than, 0.3f);
	method* method_trunk_slam_1 = new method({ condition_has_some_stamina }, { task_slam, task_tell }, "(Method 1)");
	compound_task* compound_do_trunk_slam = new compound_task({ method_trunk_slam_0, method_trunk_slam_1 }, "Compound: Do Trunk Slam");
	method* method_trunk_thumper = new method({}, { task_recover, compound_do_trunk_slam, task_nav_to_enemy }, "(Method 0)");
	compound_task* compound_be_trunk_thumper = new compound_task({ method_trunk_thumper }, "Compound: Be Trunk Thumper");

	tasks_to_process.push(compound_be_trunk_thumper);
}

vector<task*> builder::run(float& input)
{
	task* current_task;

	vector<task*> final_plan;

	while (!tasks_to_process.empty())
	{
		current_task = tasks_to_process.top();

		tasks_to_process.pop();

		if (compound_task* compound = dynamic_cast<compound_task*>(current_task))
		{
			for (method* test : compound->get_methods())
			{
				if (test->test_conditions(input))
				{
					compound->describe_compound(test);

					for (task* subtask : test->get_subtasks())
					{
						tasks_to_process.push(subtask);
					}

					break;
				}
			}
		}
		else if (primitive_task* primitive = dynamic_cast<primitive_task*>(current_task))
		{
			if (primitive->test_condition(input))
			{
				primitive->describe_task();

				primitive->apply_effect(input);

				final_plan.push_back(current_task);
			}
		}
	}

	return final_plan;
}
