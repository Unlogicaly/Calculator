#include <utility>

//
// Created by tarog on 17.10.2019.
//

#include "containers.h"

Func::Func(vector<string> names, vector<double (*)(double)> funcs) {
    if (names.size() != funcs.size()) error("Inappropriate sizes of names vector and functions vector");

    for (auto i = 0; i < names.size(); ++i)
    {
        this->funcs.insert({names[i], funcs[i]});
    }
}

Func::Func(map<string, double (*)(double)> funcs) {
    for (auto func: funcs) this->funcs.insert(func);
}

vector<string> Func::get_funcs_names() const {
    vector<string> names;
    for(const auto &t: funcs) names.push_back(t.first);
    return names;
}


