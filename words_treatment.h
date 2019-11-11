//
// Created by tarog on 13.10.2019.
//

#ifndef CALCULATOR_DEBUG_WORDS_TREATMENT_H
#define CALCULATOR_DEBUG_WORDS_TREATMENT_H

#include "std_lib_facilities.h"

vector<string> split(string s, char c = ' ');

void cut_state(string &s);

bool in(const string &src, char c);

bool in(const vector<string> &names, const string &s);

void check_signs(const string &s);

#endif //CALCULATOR_DEBUG_WORDS_TREATMENT_H
