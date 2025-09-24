#include "semantics.hh"
#include "build/while.tab.hh"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

void semantic_error(int line, std::string text) {
    std::cerr << "Line " << line << ": " << text << std::endl;
    exit(1);
}

long id = 0;

std::string next_label() {
    std::stringstream ss;
    ss << "label" << id++;
    return ss.str();
}

symbol_data::symbol_data() {}
symbol_data::symbol_data(type t) : typ(t), label(next_label()) {}
std::map<std::string, symbol_data> symbol_table;

expression::expression() : typ(integer), code("") {}
expression::expression(type t, std::string c) : typ(t), code(c) {}  

variable::variable() {}
variable::variable(type typ, size_t size, size_t stack_pos) : typ(typ), size(size), stack_pos(stack_pos) {}
std::map<std::string, variable> vars;

size_t vars_size(std::map<std::string, variable> vars) {
    size_t sum = 0;
    
    auto it = vars.begin();
    for (; it != vars.end(); ++it) {
        sum += it->second.size;
    }

    return sum;
}

size_t vars_get_largest_offset(std::map<std::string, variable> vars) {
    size_t offset = 0;

    auto it = vars.begin();
    for (; it != vars.end(); ++it) {
        if (it->second.stack_pos > offset)
            offset = it->second.stack_pos;
    }

    return offset;
}

char extract_char(std::string char_literal) {
    if (char_literal.size() == 3) {
        return char_literal[1];
    }
    else {
        if (char_literal == "'\\n'") 
            return '\n';
        else if (char_literal == "'\\t'")
            return '\t';
    }

    throw std::invalid_argument("Invalid argument: " + char_literal);
}

std::string extract_str(std::string str) {
    std::string result;
    bool escaping = false; 

    for (size_t i = 1; i < str.size() - 1; ++i) {
        char c = str[i];

        if (escaping) {
            switch (c) {
                case 'n': result += '\n'; break;
                case 't': result += '\t'; break;
            }
            escaping = false;
        } else if (c == '\\') {
            escaping = true;
        } else {
            result += c;
        }
    }

    return result;
}
