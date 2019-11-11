//
// Created by tarog on 13.10.2019.
//

#include "words_treatment.h"


vector<string> *split(const string &s, char c) {
    new vector<string> result{s};

    if (!s.length()) return result;

    int prev = -1;

    for (auto i = 0; i < s.length(); ++i) {
        if (s[i] == c) {
            result[result.size() - 1] = string(s.begin() + prev + 1, s.end() - (s.length() - i));
            result.emplace_back("");

            prev = i;

            continue;
        }
    }
    result[result.size() - 1] = string(s.begin() + prev + 1, s.end());

    return &result;
}

void cut_state(string &s) {
    while (isspace(s[0])) s.erase(0, 1);
    while (isspace(s[s.length() - 1])) s.erase(s.length() - 1, s.length());
}


bool in(const string &src, const char c) {
    for (auto ch:src) if (ch == c) return true;
    return false;
}

bool in(const vector<string> &names, const string &s) {
    for (const auto &name:names) if (name == s) return true;
    return false;
}

void check_signs(const string &old_s)
{
    string s;
    for (auto c: old_s) if (c != ' ') s += c;

    for (auto i = 1; i < s.length(); ++i)
    {
        if (
                (s[i] == '+' or s[i] == '-') and
                (s[i - 1] == '-' or s[i - 1] == '+')
                )
            error("two or more signs without separator");
    }
}
