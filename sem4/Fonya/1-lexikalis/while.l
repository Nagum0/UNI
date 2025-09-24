%option noyywrap c++ yylineno

%{
#include <iostream>
#include <cstdlib>
%}

DIGIT  		[0-9]
WS          [ \t\n]
LETTER      [a-zA-Z]

%%

program     std::cout << "T_PROGRAM" << std::endl;
begin       std::cout << "T_BEGIN" << std::endl;
end         std::cout << "T_END" << std::endl;
integer     std::cout << "T_INTEGER" << std::endl; 
date        std::cout << "T_DATE" << std::endl;
boolean     std::cout << "T_BOOLEAN" << std::endl;
skip        std::cout << "T_SKIP" << std::endl;
if          std::cout << "T_IF" << std::endl;
then        std::cout << "T_THEN" << std::endl;
else        std::cout << "T_ELSE" << std::endl;
endif       std::cout << "T_ENDIF" << std::endl;
while       std::cout << "T_WHILE" << std::endl;
do          std::cout << "T_DO" << std::endl;
done        std::cout << "T_DONE" << std::endl;
read        std::cout << "T_READ" << std::endl;
write       std::cout << "T_WRITE" << std::endl;
";"         std::cout << "T_SEMICOLON" << std::endl;
":="        std::cout << "T_ASSIGN" << std::endl;
"="         std::cout << "T_EQ" << std::endl;
"<"         std::cout << "T_LESS" << std::endl;
">"         std::cout << "T_GR" << std::endl;
"+"         std::cout << "T_ADD" << std::endl;
"-"         std::cout << "T_SUB" << std::endl;
"*"         std::cout << "T_MUL" << std::endl;
and         std::cout << "T_AND" << std::endl;
or          std::cout << "T_OR" << std::endl;
not         std::cout << "T_NOT" << std::endl;
div         std::cout << "T_DIV" << std::endl; 
mod         std::cout << "T_MOD" << std::endl;
"("         std::cout << "T_OPEN" << std::endl;
")"         std::cout << "T_CLOSE" << std::endl;
"?"         std::cout << "T_QUESTION_MARK" << std::endl;
":"         std::cout << "T_COLON" << std::endl;

(19[0-9]{2}|[2-9][0-9]{3})\-(0[1-9]|1[0-2])\-([0-2][1-9]|3[0-1])    std::cout << "T_RAW_DATE" << ' ' << YYText() << std::endl;
0b[0-1]+    std::cout << "T_BIN" << ' ' << YYText() << std::endl;
0o[0-7]+    std::cout << "T_OCT" << ' ' << YYText() << std::endl;
0x([0-9]|[A-F])+    std::cout << "T_HEX" << ' ' << YYText() << std::endl;
{DIGIT}+	std::cout << "T_NUM" << ' ' << YYText() << std::endl;
{DIGIT}+\.{DIGIT}{2}    std::cout << "T_FLOAT" << ' ' << YYText() << std::endl;
true        std::cout << "T_TRUE" << std::endl;
false       std::cout << "T_FALSE" << std::endl;

"#".*\n    // nothing to do

{LETTER}({LETTER}|{DIGIT}|_)*    std::cout << "T_ID" << ' ' << YYText() << std::endl;

{WS}+   // nothing to do

. {
    std::cerr << "Line " << lineno() << ": Unexpected character: '" << YYText() << "'." << std::endl; 
    exit(1);
}

%%
