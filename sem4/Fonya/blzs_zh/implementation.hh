#ifndef IMPLEMENTATION_HH
#define IMPLEMENTATION_HH

#include <map>
#include <string>
#include <sstream>

void semantic_error(int line, std::string text);

enum type {boolean, natural, t_time, t_real};

extern long id;

std::string next_label();

struct symbol_data {
    type typ;
    std::string label;
    symbol_data();
    symbol_data(type t);
};

extern std::map<std::string, symbol_data> symbol_table;

struct expression {
    type typ;
    std::string code;
    expression();
    expression(type typ, std::string code);
};

#endif // IMPLEMENTATION_HH

