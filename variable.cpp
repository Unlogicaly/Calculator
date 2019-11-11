//
// Created by tarog on 01.10.2019.
//

#include "variable.h"


Variable::Variable(bool is_const, std::string n, double v)
        : is_const{is_const}, name{std::move(n)}, value{v} {}

double SymbolTable::get(const string &s) {
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s)
            return var_table[i].value;

    error("get: undefined name ", s);
}

double SymbolTable::set(const string &s, double d)
{

    for (int i = 0; i <= var_table.size(); ++i) {
        if (var_table[i].name == s) {
            if (var_table[i].is_const) error("redefinition of constant variable");
            var_table[i].value = d;
            return d;
        }
    }

    error("set: undefined name ", s);
}

bool SymbolTable::is_declared(const string &s) {
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s) return true;
    return false;
}

double SymbolTable::define(bool is_const, const string &var, double val) {
    if (is_declared(var))
        error(var, " declared twice");

    var_table.push_back(Variable{is_const, var, val});

    return val;
}
