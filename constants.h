//
// Created by tarog on 17.10.2019.
//

#ifndef CALCULATOR_DEBUG_CONSTANTS_H
#define CALCULATOR_DEBUG_CONSTANTS_H

#include "containers.h"

constexpr char _print = ';';
constexpr char _number = '8';
constexpr char _name = 'a';
constexpr char _let = 'L';
constexpr char _const_key = 'C';
constexpr char _quit = 'q';
constexpr char _help = 'h';
constexpr char _sign = 's';
constexpr char _not_a_char = '~';
constexpr char _dot = '.';
constexpr char _func = 'f';

const string quit = "quit";
const string help = "help";
const string prompt = "> ";
const string result = "= ";
const string declkey = "let";
const string const_flag = "const";

const Func functions {map<string, double (*)(double)> {
        {"sin", sin},
        {"cos", cos},
        {"tg", tan},
        {"ctg", [](double x){return 1/tan(x);}},
        {"csc", [](double x){return 1/sin(x);}},
        {"sec", [](double x){return 1/cos(x);}},
        {"arcsin", asin},
        {"arccos", acos},
        {"arctg", atan},
        {"arcctg", [](double x){return 2 * atan(1) - atan(x);}},
        {"arccsc", [](double x){return asin(1 / x);}},
        {"arcsec", [](double x){return acos(1 / x);}},
        {"sinh", sinh},
        {"cosh", cosh},
        {"th", tanh},
        {"cth", [](double x){return 1/tanh(x);}},
        {"csch", [](double x){return 1/sinh(x);}},
        {"sech", [](double x){return 1/cosh(x);}},
        {"ln", log},
        {"exp", exp},
        {"sign", [](double x){return x > 0 ? 1. : x < 0 ? -1. : 0.;}},
}};

#endif //CALCULATOR_DEBUG_CONSTANTS_H
