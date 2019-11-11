//
// Created by tarog on 13.10.2019.
//

#include "states_generation.h"
#include <utility>

vector <string> _make_states(std::string line) {

    auto states = split(std::move(line), ';');

    for (auto &s: states) cut_state(s);

    for (auto i = 0; i < states.size(); i++)
    {
        if (states[i].empty())
        {
            states.erase(states.begin() + i, states.begin() + 1 + i);
            i--;
        }
        else
        {
            states[i] += _print;
        }
    }
    return states;
}


vector <string> make_states(string line) {
    auto states_and_comment = split(std::move(line), '\\');

    vector<string> result = _make_states(states_and_comment[0]);

    if (states_and_comment.size() == 2) result.push_back("\\" + states_and_comment[1]);

    return result;
}

