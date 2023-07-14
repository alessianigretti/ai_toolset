#include "builder.h"
#include "reasoner.h"
#include "agent.h"
#include "state.h"
#include "action.h"
#include <vector>

using namespace std;

reasoner* builder::build()
{
	state* hunger_state = new state(attribute_type::hunger, 1.f, "Is hungry");
	state* thirst_state = new state(attribute_type::thirst, 0.7f, "Is thirsty");
	state* tiredness_state = new state(attribute_type::tiredness, 0.3f, "Is not tired");
	state* boredom_state = new state(attribute_type::boredom, 0.f, "Is not bored");

	agent* acting_agent = new agent({ hunger_state, thirst_state, tiredness_state, boredom_state });
	acting_agent->describe_state();

	consideration* cons_hunger_threshold = new consideration(attribute_type::hunger, operation_type::greater_than, 0.7f, "is hunger greater than 0.7f");
	state* effect_eat_hunger = new state(attribute_type::hunger, 0.f, "Is not hungry");
	state* effect_eat_tiredness = new state(attribute_type::tiredness, 1.f, "Is tired");
	action* action_eat = new action({ cons_hunger_threshold }, { effect_eat_hunger, effect_eat_tiredness }, "Eat");

	consideration* cons_thirst_threshold = new consideration(attribute_type::thirst, operation_type::greater_equal_than, 0.7f, "is thirst greater than 0.7f");
	state* effect_drink = new state(attribute_type::thirst, 0.f, "Is not thirsty");
	action* action_drink = new action({ cons_thirst_threshold }, { effect_drink }, "Drink");

	consideration* cons_tiredness_threshold = new consideration(attribute_type::tiredness, operation_type::greater_than, 0.7f, "is tiredness greater than 0.7f");
	state* effect_sleep_tiredness = new state(attribute_type::tiredness, 0.f, "Is not tired");
	state* effect_sleep_boredom = new state(attribute_type::boredom, 1.f, "Is bored");
	action* action_sleep = new action({ cons_tiredness_threshold }, { effect_sleep_tiredness, effect_sleep_boredom }, "Sleep");

	consideration* cons_boredom_threshold = new consideration(attribute_type::boredom, operation_type::greater_than, 0.7f, "is boredom greater than 0.7f");
	state* effect_watch_tv = new state(attribute_type::boredom, 0.5f, "Is less bored");
	action* action_watch_tv = new action({ cons_boredom_threshold }, { effect_watch_tv }, "Watch TV");

	consideration* cons_no_tiredness_threshold = new consideration(attribute_type::tiredness, operation_type::less_than, 0.3f, "is tiredness lower than");
	state* effect_do_sport_boredom = new state(attribute_type::boredom, 0.f, "Is not bored");
	state* effect_do_sport_tiredness = new state(attribute_type::tiredness, 1.f, "Is tired");
	state* effect_do_sport_hunger = new state(attribute_type::hunger, 1.f, "Is hungry");
	state* effect_do_sport_thirst = new state(attribute_type::thirst, 1.f, "Is thirsty");
	action* action_do_sport = new action({ cons_boredom_threshold, cons_no_tiredness_threshold }, { effect_do_sport_boredom, effect_do_sport_tiredness, effect_do_sport_hunger, effect_do_sport_thirst }, "Do sport");

	return new reasoner(acting_agent, { action_eat, action_drink, action_sleep, action_watch_tv, action_do_sport });
}