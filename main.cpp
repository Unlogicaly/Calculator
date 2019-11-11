#include "grammar.h"

int main()
try {
    SymbolTable var_table{};
    var_table.define(true, "pi", 4 * atan(1));
    var_table.define(true, "e", exp(1));

    bool test_mode = false;

    calculator(var_table, cin, test_mode);
}
catch (exception &e) {
    cerr << "exception: " << e.what() << endl;
    return 1;
}
catch (...) {
    cerr << "Oops, unknown exception" << endl;
    return 2;
}
