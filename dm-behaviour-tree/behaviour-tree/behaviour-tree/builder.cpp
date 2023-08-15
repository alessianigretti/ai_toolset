#include "builder.h"
#include "sequence.h"
#include "selector.h"
#include "decorator.h"
#include "action.h"
#include <memory>

using namespace std;

void builder::build_tree()
{
	shared_ptr<action> action_attack = shared_ptr<action>(new action("Action: Attack", 0.25f));
	shared_ptr<action> action_move = shared_ptr<action>(new action("Action: Move", 0.1f));
	shared_ptr<action> action_rest = shared_ptr<action>(new action("Action: Rest", -0.75f));
	shared_ptr<action> action_idle = shared_ptr<action>(new action("Action: Idle", 0.f));
	shared_ptr<sequence> sequence_rest = shared_ptr<sequence>(new sequence({ action_rest, action_idle }, "Sequence: Rest and idle"));
	shared_ptr<decorator> decorator_stamina_max = shared_ptr<decorator>(new decorator(operation_type::greater_equal_than, 1.f));
	shared_ptr<decorator> decorator_stamina_half = shared_ptr<decorator>(new decorator(operation_type::greater_equal_than, 0.5f));
	action_attack->add_decorator(decorator_stamina_max);
	action_move->add_decorator(decorator_stamina_half);
	shared_ptr<selector> selector_action = shared_ptr<selector>(new selector({ action_attack, action_move, sequence_rest }, "Selector: Attack, move or sequence"));

	root_node = selector_action;
}

void builder::run(float& input)
{
	if (!root_node->execute(input))
	{
		return;
	}
}
