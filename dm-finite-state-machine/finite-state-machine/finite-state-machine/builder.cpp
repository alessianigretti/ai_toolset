#include "builder.h"
#include <iostream>
#include <vector>
#include "state.h"
#include "transition.h"
#include <memory>

using namespace std;

shared_ptr<state> builder::build_fsm()
{
    shared_ptr<transition> trans_see_small_enemy = shared_ptr<transition>(new transition("You see a small enemy"));
    shared_ptr<transition> trans_see_large_enemy = shared_ptr<transition>(new transition("You see a large enemy"));
    shared_ptr<transition> trans_losing_fight = shared_ptr<transition>(new transition("You are losing the fight"));
    shared_ptr<transition> trans_won_fight = shared_ptr<transition>(new transition("You won the fight"));
    shared_ptr<transition> trans_escaped = shared_ptr<transition>(new transition("You successfully escaped"));
    shared_ptr<transition> trans_slipped = shared_ptr<transition>(new transition("You slipped and fell"));

    vector<shared_ptr<transition>> transitions_guard = { trans_see_small_enemy, trans_see_large_enemy };
    shared_ptr<state> state_guard = shared_ptr<state>(new state(transitions_guard, "Guarding"));

    vector<shared_ptr<transition>> transitions_fight = { trans_losing_fight, trans_won_fight };
    shared_ptr<state> state_fight = shared_ptr<state>(new state(transitions_fight, "Fighting"));

    vector<shared_ptr<transition>> transitions_run = { trans_escaped, trans_slipped };
    shared_ptr<state> state_run = shared_ptr<state>(new state(transitions_run, "Running"));

    vector<shared_ptr<transition>> transitions_dead = {};
    shared_ptr<state> state_dead = shared_ptr<state>(new state(transitions_dead, "Dead"));

    trans_see_small_enemy->set_target_state(state_fight);
    trans_see_large_enemy->set_target_state(state_run);
    trans_losing_fight->set_target_state(state_run);
    trans_won_fight->set_target_state(state_guard);
    trans_escaped->set_target_state(state_guard);
    trans_slipped->set_target_state(state_dead);

    cout << "FSM built" << endl;

    return state_guard;
}