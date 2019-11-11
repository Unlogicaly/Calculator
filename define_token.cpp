//
// Created by tarog on 17.10.2019.
//

#include "define_token.h"

bool is_sign(char c) {
    std::string all_signs = "=-+()*/%^";
    for (auto ch: all_signs) if(ch == c) return true;
    return false;
}

bool is_digit(char c) {
    return ((c >= '0' and c <= '9') or c == '.');
}

bool is_dot(char c) {
    return c == '.';
}

bool is_func(const string &s) {
    return in(functions.get_funcs_names(), s);
}

char define_char_type(char c) {

    if (is_sign(c))
    {
        return _sign;
    }
    if(is_digit(c))
    {
        return _number;
    }
    if(is_dot(c))
    {
        return _dot;
    }
    if(c == '\n' or c == '\0' or c == _print) return _print;

    return _not_a_char;
}

char define_str_type(const string &s)
{
    if (is_func(s)) return _func;
    if (s == help) return _help;
    if (s == declkey) return _let;
    if (s == const_flag) return _const_key;
    if (s == quit) return _quit;
    return _name;
}
