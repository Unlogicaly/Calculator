//
// Created by tarog on 17.10.2019.
//

#ifndef CALCULATOR_DEBUG_GET_TOKEN_H
#define CALCULATOR_DEBUG_GET_TOKEN_H

#include "token.h"

Token dot_token(istream &in);

Token make_token(char ch, char type, istream &is);

Token number_token(istream &in);

Token str_token(istream &in);

#endif //CALCULATOR_DEBUG_GET_TOKEN_H
