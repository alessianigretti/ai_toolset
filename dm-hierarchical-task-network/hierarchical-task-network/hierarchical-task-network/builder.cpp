#include "builder.h"
#include <typeinfo>
#include "primitive_task.h"
#include "compound_task.h"
#include <memory>

using namespace std;

void builder::build_htn()
{
	shared_ptr<primitive_task> task_taunt = shared_ptr<primitive_task>(new primitive_task(0.f, "- Task: Taunt"));
	shared_ptr<primitive_task> task_super_slam = shared_ptr<primitive_task>(new primitive_task(-0.5f, "- Task: Super Slam"));
	shared_ptr<primitive_task> task_tell = shared_ptr<primitive_task>(new primitive_task(0.f, "- Task: Tell"));
	shared_ptr<primitive_task> task_slam = shared_ptr<primitive_task>(new primitive_task(-0.3f, "- Task: Slam"));
	shared_ptr<primitive_task> task_recover = shared_ptr<primitive_task>(new primitive_task(0.1f, "- Task: Recover"));
	shared_ptr<primitive_task> task_nav_to_enemy = shared_ptr<primitive_task>(new primitive_task(0.f, "- Task: Nav To Enemy"));
	shared_ptr<operation> condition_has_much_stamina = shared_ptr<operation>(new operation(operation_type::greater_equal_than, 0.8f));
	shared_ptr<method> method_trunk_slam_0 = shared_ptr<method>(new method({ condition_has_much_stamina }, { task_super_slam, task_taunt }, "(Method 0)"));
	shared_ptr<operation> condition_has_some_stamina = shared_ptr<operation>(new operation(operation_type::greater_equal_than, 0.3f));
	shared_ptr<method> method_trunk_slam_1 = shared_ptr<method>(new method({ condition_has_some_stamina }, { task_slam, task_tell }, "(Method 1)"));
	shared_ptr<compound_task> compound_do_trunk_slam = shared_ptr<compound_task>(new compound_task({ method_trunk_slam_0, method_trunk_slam_1 }, "Compound: Do Trunk Slam"));
	shared_ptr<method> method_trunk_thumper = shared_ptr<method>(new method({}, { task_recover, compound_do_trunk_slam, task_nav_to_enemy }, "(Method 0)"));
	shared_ptr<compound_task> compound_be_trunk_thumper = shared_ptr<compound_task>(new compound_task({ method_trunk_thumper }, "Compound: Be Trunk Thumper"));

	tasks_to_process.push(compound_be_trunk_thumper);
}

vector<shared_ptr<task>> builder::run(float& input)
{
	shared_ptr<task> current_task;

	vector<shared_ptr<task>> final_plan;

	while (!tasks_to_process.empty())
	{
		current_task = tasks_to_process.top();

		tasks_to_process.pop();

		if (shared_ptr<compound_task> compound = dynamic_pointer_cast<compound_task>(current_task))
		{
			for (const shared_ptr<method>& test : compound->get_methods())
			{
				if (test->test_conditions(input))
				{
					compound->describe_compound(test);

					for (const shared_ptr<task>& subtask : test->get_subtasks())
					{
						tasks_to_process.push(subtask);
					}

					break;
				}
			}
		}
		else if (shared_ptr<primitive_task> primitive = dynamic_pointer_cast<primitive_task>(current_task))
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
