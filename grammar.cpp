//
// Created by tarog on 18.10.2019.
//

#include "grammar.h"

double primary(Token_stream &ts, SymbolTable &var_table) {
    Token t = ts.get();
    switch (t.kind) 
    {
        case '(': {
            double d = expression(ts, var_table);
            t = ts.get();
            if (t.kind != ')')
                error("')' expected");
            return d;
        }

        case _func:
            return functions[t.name](primary(ts, var_table));

        case '-':
            return -primary(ts, var_table);
        case '+':
            return primary(ts, var_table);

        case _number:
            return t.value;

        case _name:
            return var_table.get(t.name);

        default:
            error("primary expected");
    }
}

double sub_term(Token_stream &ts, SymbolTable &var_table) {
    double left = primary(ts, var_table);
    while (!ts.eof()) {
        auto t = ts.get();

        if (t.kind == '^') {
            double p = primary(ts, var_table);
            if (p == 0 and left == 0) error("can't raise zero to the power of zero");
            left = pow(left, p);

            continue;
        }
        ts.putback(t);
        break;
    }
    return left;
}

double term(Token_stream &ts, SymbolTable &var_table) {
    double left = sub_term(ts, var_table);
    while (!ts.eof()) {
        Token t = ts.get();

        switch (t.kind) {
            case '*':
                left *= sub_term(ts, var_table);
                break;

            case '/': {
                double d = sub_term(ts, var_table);
                if (d == 0) error("divide by zero");
                left /= d;
                break;
            }

            case '%': {
                double d = sub_term(ts, var_table);
                if (d == 0) error("divide by zero");
                left = fmod(left, d);
                break;
            }


            default:
                ts.putback(t);
                return left;
        }
    }
    return left;
}

double expression(Token_stream &ts, SymbolTable &var_table) {
    double left = term(ts, var_table);
    while (!ts.eof()) {
        Token t = ts.get();

        switch (t.kind) {
            case '+':
                left += term(ts, var_table);
                break;

            case '-':
                left -= term(ts, var_table);
                break;

            default:
                ts.putback(t);
                return left;
        }
    }
    return left;
}

// Awful feature, but works. Better remake
double var_treatment(Token_stream &ts, SymbolTable &var_table, bool def) {
    bool is_const = false;

    Token t = ts.get();

    if (t.kind == _const_key) {
        is_const = true;
        t = ts.get();
    }

    if (t.kind != _name)
        error("name expected in var_treatment");

    string var = t.name;

    t = ts.get();

    if (t.kind != '=')
        error("'=' missing in var_treatment of ", var);

    if (!def and is_const) error("impossible to make variable constant");

    if (var_table.is_declared(var)) {
        if (def) error("can't redefine existing variable");
        return var_table.set(var, expression(ts, var_table));
    }
    if (!def) error("can't assign value to nonexistent variable");
    return var_table.define(is_const, var, expression(ts, var_table));
}

void statement(Token_stream &ts, SymbolTable &var_table, bool var_treat) {

    Token t = ts.get();

    if (var_treat) {
        switch (t.kind) {
            case _let:
            {
                auto temp = var_treatment(ts, var_table, true);
                cout << result << temp << endl;
                break;
            }
            case _name: {
                ts.putback(t);
                auto temp = var_treatment(ts, var_table, false);
                cout << result << temp << endl;
                break;
            }
            default:
                error("unexpected '=' symbol");
        }

    } else {
        ts.putback(t);
        auto temp = expression(ts, var_table);
        cout << result << temp << endl;
    }
}

void calculate(string &s, SymbolTable &var_table) {

    istringstream local_is{s};
    Token_stream ts{local_is};

    try {
        check_signs(s);

        Token t = ts.get();

        if (t.kind == _quit) {
            exit(0);
        }

        if (t.kind == _help) {
            cout << "Instructions: ..." << endl;
            return;
        }

        ts.putback(t);
        statement(ts, var_table, in(s, '='));

        if (!ts.eof() and ts.get().kind != _print) throw runtime_error("= end of statement expected");
    }
    catch (exception &e) {
        cerr << e.what() << endl;
        ts.ignore(_print);
    }
}

void calculator(SymbolTable &var_table, istream &is, bool test_mode) {

    while (!is.eof()) {
        if (!test_mode) cout << prompt;

        string line;
        getline(is, line);

        auto states = make_states(line);

        if (test_mode and !states.empty() and states.back()[0] == '\\') {
            cout << endl << states.back() << endl;
            states.pop_back();
        }

        for (auto &s :states) {
            calculate(s, var_table);
        }
    }
}
