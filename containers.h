//
// Created by tarog on 17.10.2019.
//

#ifndef CALCULATOR_DEBUG_CONTAINERS_H
#define CALCULATOR_DEBUG_CONTAINERS_H

#include "words_treatment.h"

class Func
{
public:

    Func(vector<string>, vector<double(*)(double)>);

    explicit Func(map<string, double(*)(double)>);

    auto &operator[](const string &s) const {return funcs.at(s);}

    vector<string> get_funcs_names() const;

private:
    map<string, double(*)(double)> funcs;
};

#endif //CALCULATOR_DEBUG_CONTAINERS_H
