//
// Created by tarog on 18.10.2019.
//

#ifndef CALCULATOR_DEBUG_GRAMMAR_H
#define CALCULATOR_DEBUG_GRAMMAR_H

#include "states_generation.h"

/**Грамматика для калькулятора
 * calculator:
 *      comment (for test mode)
 *      calculate [;calculate; calculate; ...]
 *
 * calculate:
 *      quit ("quit")
 *      help ("help")
 *      statement
 *
 * statement:
 *      var_treatment (if "=" detected)
 *      expression
 *
 * var_treatment:
 *      declaration ("let [const]" <name> "=" expression)
 *      assignment (<name> "=" expression)
 *
 * name:
 *      first symbol: latin character or "_"
 *      other symbols: latin characters or digits or "_"
 *
 * expression:
 *      term + term
 *      term - term
 *      term
 *
 * term:
 *      sub_term * sub_term
 *      sub_term / sub_term
 *      sub_term % sub_term
 *      sub_term
 *
 * sub_term:
 *      primary ^ primary
 *      primary
 *
 * primary:
 *      "(" expression ")"
 *      "+" primary
 *      "-" primary     (using two or more symbols in a row prohibited)
 *      function primary (may be used without brackets like sin 3, arctg 9)
 *      number
 *      variable
 *
 * variable:
 *      Is creating in declaration. If const, it won't be changed further. Examples:
 *          let g = 13  // "let" - key word for definition, "g" - name, "=" - key word for var_treatment, 13 - value
 *          let const h = 5  // "const" - key word for constant variables
 *          let g = 5  // error: defining existing variable
 *
 *      Is changing in assignment. If const, error will be occurred. Examples:
 *          g = 4  // if "=" discovered and "let" is absent, variable will be assigned by expression on the right side of "="
 *          h = 3  // error: changing const variable
 *
 * features of input statements:
 *      All statements must be separated by print symbol ";". Symbols "'\'n" and "\0" considered equal to print.
 *      One or several statements can be entered in one line, if they are separated. For example:
 *          1 + 1;  // one statement on line, end - ";". Correct input
 *          1 + 1   // one statement on line, end - "'\'n". Correct input
 *          1 + 1; 1  // two statements, separated by print. Correct input
 *          1 + 1 1  // two statements without separator ("1 + 1" and "1"). Incorrect input
 *      If calculator finds error in one of statements in line, it will calculate and show results of all statements
 *      except wrong ones. So output for
 *          1 + 1; 1 - 1; 1 / 0; 1 * 1
 *      will be:
 *          = 2
 *          = 0
 *          = divide by zero
 *          = 1
 *      That means, that you can enter in one line both correct and incorrect statements. Calculator will work correct
 */
void calculator(SymbolTable &var_table, istream &is, bool test_mode = false);

double primary(Token_stream &ts, SymbolTable &var_table);

double sub_term(Token_stream &ts, SymbolTable &var_table);

double term(Token_stream &ts, SymbolTable &var_table);

double expression(Token_stream &ts, SymbolTable &var_table);

double var_treatment(Token_stream &ts, SymbolTable &var_table, bool def);

void statement(Token_stream &ts, SymbolTable &var_table, bool var_treat);

void calculate(string &s, SymbolTable &var_table);

#endif //CALCULATOR_DEBUG_GRAMMAR_H
