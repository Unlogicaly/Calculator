//
// Created by tarog on 01.10.2019.
//

#include "get_token.h"


Token::Token (char ch)
        : kind{ ch }, value{ 0 }
{ }

Token::Token (char ch, double val)
        : kind{ ch }, value{ val }
{ }

Token::Token(char ch, std::string name)
        : kind{ch}, name{std::move(name)}
{ }


Token_stream::Token_stream() : in{std::cin}{}

Token_stream::Token_stream(std::istream &s) : in{s}{}

void Token_stream::ignore (char c)
{
    if (full and c == buffer.kind)
    {
        full = false;
        return;
    }
    full = false;

    char ch;
    while (in.get(ch))
        if (ch == c or ch == '\n' or ch == '\0') return;
}

Token Token_stream::get ()
{
    if (full)
    {
        full = false;
        return buffer;
    }

    char ch;
    char type;

    in.get(ch);
    while (ch == ' ') in.get(ch);

    type = define_char_type(ch);

    return make_token(ch, type, in);
}

void Token_stream::putback (Token t)
{
    if (full)
        error("putback() into a full buffer");

    buffer = std::move(t);
    full = true;
}

bool Token_stream::eof() {
    return in.eof() and !full;
}
