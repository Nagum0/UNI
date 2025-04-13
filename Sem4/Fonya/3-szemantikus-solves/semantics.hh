#ifndef IMPLEMENTATION_HH
#define IMPLEMENTATION_HH

#include <map>
#include <string>
#include <list>

void semantic_error(int line, std::string text);

enum type {boolean, integer, my_date};

extern std::map<std::string, type> symbol_table;

extern std::map<std::string, int> label_table;

struct simultan_assignment {
  std::list<std::string> left;
  std::list<type> right;
  simultan_assignment(std::list<std::string> _l, std::list<type> _r) : left(_l), right(_r) {}
  simultan_assignment() {}
};

#endif // IMPLEMENTATION_HH

