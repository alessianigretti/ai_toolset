#include "builder.h"
#include "sequence.h"
#include "selector.h"
#include "decorator.h"
#include "action.h"

void builder::build_tree()
{
	action* action_attack = new action("Action: Attack", 0.25f);
	action* action_move = new action("Action: Move", 0.1f);
	action* action_rest = new action("Action: Rest", -0.75f);
	action* action_idle = new action("Action: Idle", 0.f);
	sequence* sequence_rest = new sequence({ action_rest, action_idle }, "Sequence: Rest and idle");
	decorator* decorator_stamina_max = new decorator(operation_type::greater_equal_than, 1.f);
	decorator* decorator_stamina_half = new decorator(operation_type::greater_equal_than, 0.5f);
	action_attack->add_decorator(decorator_stamina_max);
	action_move->add_decorator(decorator_stamina_half);
	selector* selector_action = new selector({ action_attack, action_move, sequence_rest }, "Selector: Attack, move or sequence");

	root_node = selector_action;
}

void builder::run(float& input)
{
	if (!root_node->execute(input))
	{
		return;
	}
}
