#include "builder.h"
#include "reasoner.h"
#include "agent.h"
#include "state.h"
#include "action.h"
#include <vector>
#include <memory>

using namespace std;

shared_ptr<reasoner> builder::build()
{
	shared_ptr<state> hunger_state = shared_ptr<state>(new state(attribute_type::hunger, 1.f, "Is hungry"));
	shared_ptr<state> thirst_state = shared_ptr<state>(new state(attribute_type::thirst, 0.7f, "Is thirsty"));
	shared_ptr<state> tiredness_state = shared_ptr<state>(new state(attribute_type::tiredness, 0.3f, "Is not tired"));
	shared_ptr<state> boredom_state = shared_ptr<state>(new state(attribute_type::boredom, 0.f, "Is not bored"));

	shared_ptr<agent> acting_agent = shared_ptr<agent>(new agent({ hunger_state, thirst_state, tiredness_state, boredom_state }));
	acting_agent->describe_state();

	shared_ptr<consideration> cons_hunger_threshold = shared_ptr<consideration>(new consideration(attribute_type::hunger, operation_type::greater_than, 0.7f, "is hunger greater than 0.7f"));
	shared_ptr<state> effect_eat_hunger = shared_ptr<state>(new state(attribute_type::hunger, 0.f, "Is not hungry"));
	shared_ptr<state> effect_eat_tiredness = shared_ptr<state>(new state(attribute_type::tiredness, 1.f, "Is tired"));
	shared_ptr<action> action_eat = shared_ptr<action>(new action({ cons_hunger_threshold }, { effect_eat_hunger, effect_eat_tiredness }, "Eat"));

	shared_ptr<consideration> cons_thirst_threshold = shared_ptr<consideration>(new consideration(attribute_type::thirst, operation_type::greater_equal_than, 0.7f, "is thirst greater than 0.7f"));
	shared_ptr<state> effect_drink = shared_ptr<state>(new state(attribute_type::thirst, 0.f, "Is not thirsty"));
	shared_ptr<action> action_drink = shared_ptr<action>(new action({ cons_thirst_threshold }, { effect_drink }, "Drink"));

	shared_ptr<consideration> cons_tiredness_threshold = shared_ptr<consideration>(new consideration(attribute_type::tiredness, operation_type::greater_than, 0.7f, "is tiredness greater than 0.7f"));
	shared_ptr<state> effect_sleep_tiredness = shared_ptr<state>(new state(attribute_type::tiredness, 0.f, "Is not tired"));
	shared_ptr<state> effect_sleep_boredom = shared_ptr<state>(new state(attribute_type::boredom, 1.f, "Is bored"));
	shared_ptr<action> action_sleep = shared_ptr<action>(new action({ cons_tiredness_threshold }, { effect_sleep_tiredness, effect_sleep_boredom }, "Sleep"));

	shared_ptr<consideration> cons_boredom_threshold = shared_ptr<consideration>(new consideration(attribute_type::boredom, operation_type::greater_than, 0.7f, "is boredom greater than 0.7f"));
	shared_ptr<state> effect_watch_tv = shared_ptr<state>(new state(attribute_type::boredom, 0.5f, "Is less bored"));
	shared_ptr<action> action_watch_tv = shared_ptr<action>(new action({ cons_boredom_threshold }, { effect_watch_tv }, "Watch TV"));

	shared_ptr<consideration> cons_no_tiredness_threshold = shared_ptr<consideration>(new consideration(attribute_type::tiredness, operation_type::less_than, 0.3f, "is tiredness lower than"));
	shared_ptr<state> effect_do_sport_boredom = shared_ptr<state>(new state(attribute_type::boredom, 0.f, "Is not bored"));
	shared_ptr<state> effect_do_sport_tiredness = shared_ptr<state>(new state(attribute_type::tiredness, 1.f, "Is tired"));
	shared_ptr<state> effect_do_sport_hunger = shared_ptr<state>(new state(attribute_type::hunger, 1.f, "Is hungry"));
	shared_ptr<state> effect_do_sport_thirst = shared_ptr<state>(new state(attribute_type::thirst, 1.f, "Is thirsty"));
	shared_ptr<action> action_do_sport = shared_ptr<action>(new action({ cons_boredom_threshold, cons_no_tiredness_threshold }, { effect_do_sport_boredom, effect_do_sport_tiredness, effect_do_sport_hunger, effect_do_sport_thirst }, "Do sport"));

	return shared_ptr<reasoner>(new reasoner(acting_agent, { action_eat, action_drink, action_sleep, action_watch_tv, action_do_sport }));
}