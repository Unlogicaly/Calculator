//
// Created by tarog on 01.10.2019.
//

#ifndef CALCULATOR_DEBUG_TOKEN_H
#define CALCULATOR_DEBUG_TOKEN_H

#include "define_token.h"

struct Token {
    char kind;
    double value{};
    std::string name;

    explicit Token(char ch);

    Token(char ch, double val);

    Token(char ch, std::string name);
};

class Token_stream
        {
private:
    std::istream &in;
    bool full{false};
    Token buffer{'\0'};

public:
    explicit Token_stream();

    explicit Token_stream(std::istream &s);

    Token get();

    void putback(Token t);

    void ignore(char);

    bool eof();
};


#endif //CALCULATOR_DEBUG_TOKEN_H
