%option c++ noyywrap yylineno

%{
#include <iostream>
#include <cstdlib>
#include "while.tab.hh"

using namespace yy;
%}

%%

program                     return parser::token::T_PROGRAM;
begin                       return parser::token::T_BEGIN;
end                         return parser::token::T_END;
boolean                     return parser::token::T_BOOLEAN;
natural                     return parser::token::T_NATURAL;
read                        return parser::token::T_READ;
write                       return parser::token::T_WRITE;
if                          return parser::token::T_IF;
then                        return parser::token::T_THEN;
else                        return parser::token::T_ELSE;
endif                       return parser::token::T_ENDIF;
while                       return parser::token::T_WHILE;
do                          return parser::token::T_DO;
done                        return parser::token::T_DONE;
true                        return parser::token::T_TRUE;
false                       return parser::token::T_FALSE;
real			            return parser::token::T_REAL;
int                         return parser::token::T_INT;
frac                        return parser::token::T_FRAC;
":="                        return parser::token::T_ASSIGN;
"+"                         return parser::token::T_ADD;
"-"                         return parser::token::T_SUB;
"*"                         return parser::token::T_MUL;
"/"                         return parser::token::T_DIV;
"%"                         return parser::token::T_MOD;
"<"                         return parser::token::T_LESS;
">"                         return parser::token::T_GREATER;
"<="                        return parser::token::T_LESSEQ;
">="                        return parser::token::T_GREATEREQ;
"="                         return parser::token::T_EQ;
and                         return parser::token::T_AND;
or                          return parser::token::T_OR;
not                         return parser::token::T_NOT;
"("                         return parser::token::T_OPEN;
")"                         return parser::token::T_CLOSE;
([0-9]|"1"[0-9]|"2"[0-3])":"[0-5][0-9] return parser::token::T_TIME;
(0|[1-9][0-9]*),([0-9]*[1-9])?  return parser::token::T_REAL_LITERAL;
hour			    return parser::token::T_HOUR;
minute			    return parser::token::T_MINUTE;
[a-zA-Z_][a-zA-Z0-9_]*      return parser::token::T_ID;
[0-9]+                      return parser::token::T_NUM;
[ \t\n]+                    // Whitespaces skipped.
#.*                         // Commens skipped.
.                           { std::cerr << "Line " << lineno() << ": Unexpected character: '" << YYText() << "'." << std::endl; exit(1); }
