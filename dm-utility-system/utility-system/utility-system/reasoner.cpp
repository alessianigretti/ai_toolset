#include "reasoner.h"
#include <iostream>
#include "state.h"
#include "agent.h"

void reasoner::run()
{
    float highest_score = 0.f;
    action* best_action = nullptr;

    for (action* action : executable_actions)
    {
        float action_score = score(action);
        
        if (action_score > highest_score)
        {
            best_action = action;
            highest_score = action_score;
        }
    }

    if (best_action)
    {
        select(best_action);
    }
}

float reasoner::score(action* action)
{
    if (action->considerations.empty())
    {
        return 1.f;
    }

    float score = 0.;

    for (consideration* cons : action->considerations)
    {
        for (state* state : acting_agent->get_states())
        {
            if (state->attribute == cons->attribute)
            {
                switch (cons->operation)
                {
                case operation_type::greater_equal_than:
                {
                    if (state->get_value() >= cons->value)
                    {
                        score += 1.f;
                    }
                    break;
                }
                case operation_type::greater_than:
                {
                    if (state->get_value() > cons->value)
                    {
                        score += 1.f;
                    }
                    break;
                }
                case operation_type::less_equal_than:
                {
                    if (state->get_value() <= cons->value)
                    {
                        score += 1.f;
                    }
                    break;
                }
                case operation_type::less_than:
                {
                    if (state->get_value() < cons->value)
                    {
                        score += 1.f;
                    }
                    break;
                }
                case operation_type::equal_to:
                {
                    if (state->get_value() == cons->value)
                    {
                        score += 1.f;
                    }
                    break;
                }
                }
                break;
            }
        }
    }

    score /= action->considerations.size();

    cout << "Action " << action->description << " scored " << score << endl;

    return score;
}

void reasoner::select(action* action)
{
    cout << endl << "Selected action: " << action->description << endl << endl;

    for (state* effect : action->effects)
    {
        acting_agent->modify_or_add_state(effect);
    }

    acting_agent->describe_state();
}