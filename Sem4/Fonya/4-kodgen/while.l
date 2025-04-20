%option noyywrap c++ yylineno

%{
#include <iostream>
#include <cstdlib>
#include "while.tab.hh"

using namespace yy;
%}

DIGIT  		[0-9]
WS          [ \t\n]
LETTER      [a-zA-Z]

%%

program     return parser::token::T_PROGRAM;
begin       return parser::token::T_BEGIN;
end         return parser::token::T_END;
integer     return parser::token::T_INTEGER; 
boolean     return parser::token::T_BOOLEAN;
char        return parser::token::T_CHAR;
skip        return parser::token::T_SKIP;
if          return parser::token::T_IF;
then        return parser::token::T_THEN;
else        return parser::token::T_ELSE;
endif       return parser::token::T_ENDIF;
while       return parser::token::T_WHILE;
do          return parser::token::T_DO;
done        return parser::token::T_DONE;
read        return parser::token::T_READ;
write       return parser::token::T_WRITE;
assert      return parser::token::T_ASSERT;
multi       return parser::token::T_MULTI;
stdout      return parser::token::T_STDOUT;
let         return parser::token::T_LET;
";"         return parser::token::T_SEMICOLON;
":="        return parser::token::T_ASSIGN;
"="         return parser::token::T_EQ;
"<"         return parser::token::T_LESS;
">"         return parser::token::T_GR;
"+"         return parser::token::T_ADD;
"-"         return parser::token::T_SUB;
"*"         return parser::token::T_MUL;
and         return parser::token::T_AND;
or          return parser::token::T_OR;
not         return parser::token::T_NOT;
div         return parser::token::T_DIV; 
mod         return parser::token::T_MOD;
"("         return parser::token::T_OPEN;
")"         return parser::token::T_CLOSE;
"["         return parser::token::T_OPEN_BRACKET;
"]"         return parser::token::T_CLOSE_BRACKET;
"?"         return parser::token::T_QMARK;
":"         return parser::token::T_COLON;
","         return parser::token::T_COMMA;

{DIGIT}+	return parser::token::T_NUM;
\"({LETTER}|{DIGIT}|{WS}|\\n|\\t)*\" return parser::token::T_STRING_LIT;
'({LETTER}|\\n|\\t)' return parser::token::T_CHAR_LIT;
true        return parser::token::T_TRUE;
false       return parser::token::T_FALSE;

"#".*\n    // nothing to do

{LETTER}({LETTER}|{DIGIT}|_)*    return parser::token::T_ID;

{WS}+   // nothing to do

. {
    std::cerr << "Line " << lineno() << ": Unexpected character: '" << YYText() << "'." << std::endl; 
    exit(1);
}

%%
