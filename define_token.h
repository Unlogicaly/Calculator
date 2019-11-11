//
// Created by tarog on 17.10.2019.
//

#ifndef CALCULATOR_DEBUG_DEFINE_TOKEN_H
#define CALCULATOR_DEBUG_DEFINE_TOKEN_H

#include "constants.h"

bool is_sign(char c);

bool is_digit(char c);

bool is_dot(char c);

char define_char_type(char c);

char define_str_type(const string &s);

#endif //CALCULATOR_DEBUG_DEFINE_TOKEN_H
