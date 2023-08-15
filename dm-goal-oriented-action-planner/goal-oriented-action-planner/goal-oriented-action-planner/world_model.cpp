#include "world_model.h"

void world_model::apply_action(const shared_ptr<action>& action)
{
    for (shared_ptr<state> effect : action->get_effects())
    {
        if (!update_if_contained(effect))
        {
            world_state.push_back(effect);
        }
    }
}

bool world_model::update_if_contained(const shared_ptr<state>& effect)
{
    for (shared_ptr<state> existing_state : world_state)
    {
        if (existing_state->state_type == effect->state_type)
        {
            existing_state->value = effect->value;
            return true;
        }
    }

    return false;
}

bool world_model::is_goal_fulfilled(const shared_ptr<state>& goal)
{
    for (shared_ptr<state> existing_state : world_state)
    {
        if (existing_state->state_type == goal->state_type &&
            existing_state->value == goal->value)
        {
            return true;
        }
    }

    return false;
}

void world_model::clear()
{
    world_state.clear();
}
