#ifndef IMPLEMENTATION_HH
#define IMPLEMENTATION_HH

#include <map>
#include <string>

void semantic_error(int line, std::string text);

enum type {boolean, integer, ch};

extern long id;

std::string next_label();

struct symbol_data {
    type typ;
    std::string label;
    bool is_array;
    int array_size;
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

char extract_char(std::string char_literal);
std::string extract_str(std::string string_literal);

#endif // IMPLEMENTATION_HH
