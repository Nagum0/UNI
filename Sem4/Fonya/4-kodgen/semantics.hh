#ifndef IMPLEMENTATION_HH
#define IMPLEMENTATION_HH

#include <cstddef>
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

struct variable {
    type typ;
    size_t size;
    size_t stack_pos;
    variable();
    variable(type typ, size_t size, size_t stack_pos);
};

extern std::map<std::string, variable> vars;

size_t vars_size(std::map<std::string, variable> vars);
size_t vars_get_largest_offset(std::map<std::string, variable> vars);

char extract_char(std::string char_literal);
std::string extract_str(std::string string_literal);

#endif // IMPLEMENTATION_HH
