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
date        return parser::token::T_DATE;
skip        return parser::token::T_SKIP;
if          return parser::token::T_IF;
then        return parser::token::T_THEN;
else        return parser::token::T_ELSE;
endif       return parser::token::T_ENDIF;
while       return parser::token::T_WHILE;
do          return parser::token::T_DO;
done        return parser::token::T_DONE;
repeat      return parser::token::T_REPEAT;
until       return parser::token::T_UNTIL; 
read        return parser::token::T_READ;
write       return parser::token::T_WRITE;
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
"?"         return parser::token::T_QUESTIONMARK;
":"         return parser::token::T_COLON;
","         return parser::token::T_COMMA;
"for"       return parser::token::T_FOR;
"from"      return parser::token::T_FROM;
"upto"      return parser::token::T_UPTO;
"downto"    return parser::token::T_DOWNTO;
[0-9]{4}"-"[0-9]{2}"-"[0-9]{2}  return parser::token::T_DATE_LIT;
"getDay"    return parser::token::T_GET_DAY;
"getMonth"  return parser::token::T_GET_MONTH;
"getYeat"   return parser::token::T_GET_YEAR;
"goto"      return parser::token::T_GOTO; 

{DIGIT}+	return parser::token::T_NUM;
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
