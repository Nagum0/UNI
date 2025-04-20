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
