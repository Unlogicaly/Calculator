//
// Created by tarog on 17.10.2019.
//

#include "get_token.h"

Token dot_token(istream &in)
{
    char ch = _dot;
    string temp{"."};
    in.get(ch);
    while (isdigit(ch)) {
        temp += ch;
        in.get(ch);
    }
    in.putback(ch);
    double val = atof(temp.c_str());
    return Token{_number, val};
}

Token number_token(istream &in) {
    double val;
    in >> val;
    return Token{ _number, val };
}

Token str_token(istream &in)
{
    char ch; in.get(ch);

    if (isalpha(ch) or ch == '_')
    {

        if (!(isalpha(ch) or ch == '_')) error("Bad token");

        string s;
        s += ch;

        while (in.get(ch) and
               (isalpha(ch) or isdigit(ch) or ch == '_'))
            s += ch;

        in.putback(ch);

        char type = define_str_type(s);

        if (type == _name or type == _func) return Token{type, s};

        return Token{ type };
    }
    error("Bad token");
}

Token make_token(char ch, char type, istream &in) {
    switch (type)
    {
        case _print:
        case _sign:
            return Token{ ch };

        case _dot:
            return dot_token(in);

        case _number:
            in.putback(ch);
            return number_token(in);

        case _not_a_char:
            in.putback(ch);
            return str_token(in);

        default:
            error("Unknown error");
    }
}