//
// Created by tarog on 01.10.2019.
//

#ifndef CALCULATOR_DEBUG_VARIABLE_H
#define CALCULATOR_DEBUG_VARIABLE_H

#include "token.h"

struct Variable
{
    bool is_const = false;
    std::string name;
    double value;

    Variable (bool is_const, std::string n, double v);
};


class SymbolTable
{
public:
    SymbolTable() = default;

    double get(const string &s);

    double set(const string &s, double d);

    bool is_declared (const string &s);

    double define(bool is_const, const string &var, double val);

private:
    vector<Variable> var_table;
};








#endif //CALCULATOR_DEBUG_VARIABLE_H
