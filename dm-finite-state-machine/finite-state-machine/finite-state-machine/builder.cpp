#include "builder.h"
#include <iostream>
#include <vector>
#include "state.h"
#include "transition.h"

using namespace std;

state* builder::build_fsm()
{
    transition* trans_see_small_enemy = new transition("You see a small enemy");
    transition* trans_see_large_enemy = new transition("You see a large enemy");
    transition* trans_losing_fight = new transition("You are losing the fight");
    transition* trans_won_fight = new transition("You won the fight");
    transition* trans_escaped = new transition("You successfully escaped");
    transition* trans_slipped = new transition("You slipped and fell");

    vector<transition*> transitions_guard = { trans_see_small_enemy, trans_see_large_enemy };
    state* state_guard = new state(transitions_guard, "Guarding");

    vector<transition*> transitions_fight = { trans_losing_fight, trans_won_fight };
    state* state_fight = new state(transitions_fight, "Fighting");

    vector<transition*> transitions_run = { trans_escaped, trans_slipped };
    state* state_run = new state(transitions_run, "Running");

    vector<transition*> transitions_dead = {};
    state* state_dead = new state(transitions_dead, "Dead");

    trans_see_small_enemy->set_target_state(state_fight);
    trans_see_large_enemy->set_target_state(state_run);
    trans_losing_fight->set_target_state(state_run);
    trans_won_fight->set_target_state(state_guard);
    trans_escaped->set_target_state(state_guard);
    trans_slipped->set_target_state(state_dead);

    cout << "FSM built" << endl;

    return state_guard;
}