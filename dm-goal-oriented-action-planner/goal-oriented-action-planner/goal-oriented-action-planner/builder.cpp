#include "builder.h"
#include <memory>

using namespace std;

void builder::build_goap()
{
    shared_ptr<state> condition_eating = shared_ptr<state>(new state());
    condition_eating->state_type = state_type::has_food;
    condition_eating->value = true;
    condition_eating->description = "Has food";
    shared_ptr<state> effect_eating_1 = shared_ptr<state>(new state());
    effect_eating_1->state_type = state_type::is_hungry;
    effect_eating_1->value = false;
    effect_eating_1->description = "Is not hungry";
    shared_ptr<state> effect_eating_2 = shared_ptr<state>(new state());
    effect_eating_2->state_type = state_type::has_food;
    effect_eating_2->value = false;
    effect_eating_2->description = "Does not have food";
    vector<shared_ptr<state>> effects_eating = { effect_eating_1, effect_eating_2 };
    shared_ptr<action> action_eating = shared_ptr<action>(new action("Eating", condition_eating, effects_eating));

    shared_ptr<state> condition_getting_food = shared_ptr<state>(new state());
    condition_getting_food->state_type = state_type::none;
    condition_getting_food->value = true;
    condition_getting_food->description = "No condition";
    shared_ptr<state> effect_getting_food = shared_ptr<state>(new state());
    effect_getting_food->state_type = state_type::has_food;
    effect_getting_food->value = true;
    effect_getting_food->description = "Has food";
    vector<shared_ptr<state>> effects_getting_food = { effect_getting_food };
    shared_ptr<action> action_getting_food = shared_ptr<action>(new action("Getting food", condition_getting_food, effects_getting_food));

    shared_ptr<state> condition_sleeping = shared_ptr<state>(new state());
    condition_sleeping->state_type = state_type::none;
    condition_sleeping->value = true;
    condition_sleeping->description = "No condition";
    shared_ptr<state> effect_sleeping = shared_ptr<state>(new state());
    effect_sleeping->state_type = state_type::is_rested;
    effect_sleeping->value = true;
    effect_sleeping->description = "Is rested";
    vector<shared_ptr<state>> effects_sleeping = { effect_sleeping };
    shared_ptr<action> action_sleeping = shared_ptr<action>(new action("Sleeping", condition_sleeping, effects_sleeping));

    actions.push_back(action_eating);
    actions.push_back(action_getting_food);
    actions.push_back(action_sleeping);

    initial_state = shared_ptr<state>(new state());
    initial_state->state_type = state_type::is_hungry;
    initial_state->value = true;
    initial_state->description = "Is hungry";

    final_state = shared_ptr<state>(new state());
    final_state->state_type = state_type::is_hungry;
    final_state->value = false;
    final_state->description = "Is not hungry";

    reusable_world_model = shared_ptr<world_model>(new world_model());
}

vector<shared_ptr<action>> builder::plan_action()
{
    reusable_plan.clear();

    reusable_world_model->clear();
    reusable_world_model->world_state.push_back(initial_state);

    shared_ptr<state> temp_final_state = shared_ptr<state>(new state());
    temp_final_state->state_type = final_state->state_type;
    temp_final_state->value = final_state->value;

    while (!reusable_world_model->is_goal_fulfilled(final_state))
    {
        shared_ptr<action> current_action = get_action_fulfilling_goal(temp_final_state);
        if (current_action == nullptr)
        {
            break;
        }

        reusable_plan.push_back(current_action);

        if (current_action->get_condition()->state_type == state_type::none)
        {
            break;
        }

        temp_final_state->state_type = current_action->get_condition()->state_type;
        temp_final_state->value = current_action->get_condition()->value;

        if (initial_state->state_type == temp_final_state->state_type &&
            initial_state->value == temp_final_state->value)
        {
            break;
        }
    }

    reverse(reusable_plan.begin(), reusable_plan.end());

    for (shared_ptr<action> action : reusable_plan)
    {
        action->describe_action();
    }

    return reusable_plan;
}

shared_ptr<state> builder::get_initial_state()
{
    return initial_state;
}

shared_ptr<state> builder::get_final_state()
{
    return final_state;
}

shared_ptr<action> builder::get_action_fulfilling_goal(const shared_ptr<state>& goal_state)
{
    for (shared_ptr<action> action : actions)
    {
        if (does_fulfill_goal(goal_state, action))
        {
            return action;
        }
    }

    return nullptr;
}

bool builder::does_fulfill_goal(const shared_ptr<state>& goal_state, const shared_ptr<action>& action)
{
    for (shared_ptr<state> effect : action->get_effects())
    {
        if (effect->state_type == goal_state->state_type &&
            effect->value == goal_state->value)
        {
            return true;
        }
    }

    return false;
}