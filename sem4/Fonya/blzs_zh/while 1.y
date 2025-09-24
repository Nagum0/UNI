%language "c++"
%locations
%define api.value.type variant

%code requires {
#include "implementation.hh"
}

%code provides {
int yylex(yy::parser::semantic_type* yylval, yy::parser::location_type* yylloc);
}

%token T_PROGRAM
%token T_BEGIN
%token T_END
%token T_BOOLEAN
%token T_NATURAL
%token T_READ
%token T_WRITE
%token T_IF
%token T_THEN
%token T_ELSE
%token T_ENDIF
%token T_WHILE
%token T_DO
%token T_DONE
%token T_TRUE
%token T_FALSE
%token T_ASSIGN
%token T_OPEN
%token T_CLOSE
%token T_REAL
%token <std::string> T_REAL_LITERAL
%token <std::string> T_TIME
%token T_HOUR
%token T_MINUTE
%token <std::string> T_ID
%token <std::string> T_NUM

%left T_OR
%left T_AND
%left T_EQ
%left T_LESS T_GREATER T_LESSEQ T_GREATEREQ
%left T_ADD T_SUB
%left T_MUL T_DIV T_MOD
%precedence T_NOT

%type <expression> expression
%type <std::string> commands
%type <std::string> command

%%

start:
    T_PROGRAM T_ID declarations T_BEGIN commands T_END
    {
        std::cout << "global main" << std::endl;
        std::cout << "extern write_natural" << std::endl;
        std::cout << "extern read_natural" << std::endl;
        std::cout << "extern write_boolean" << std::endl;
        std::cout << "extern read_boolean" << std::endl;
        std::cout << std::endl;
        std::cout << "section .bss" << std::endl;
        std::map<std::string,symbol_data>::iterator it;
        for(it = symbol_table.begin(); it != symbol_table.end(); ++it) {
            std::string label = it->second.label;
            std::cout
                << it->second.label << ": "
                << (it->second.typ == boolean ? "resb " : "resd ")
                << 1 << std::endl;
        }
        std::cout << std::endl;
        std::cout << "section .text" << std::endl;
        std::cout << "main:" << std::endl;
        std::cout << $5;
        std::cout << "xor eax,eax" << std::endl;
        std::cout << "ret" << std::endl;
    }
;

declarations:
    // empty
|
    declarations declaration
;

declaration:
    T_BOOLEAN T_ID
    {
        if(symbol_table.find($2) != symbol_table.end()) {
            semantic_error(@1.begin.line, "Re-declared variable: '" + $2 + "'.");
        }
        symbol_table[$2] = boolean;
    }
|
    T_NATURAL T_ID
    {
        if(symbol_table.find($2) != symbol_table.end()) {
            semantic_error(@1.begin.line, "Re-declared variable: '" + $2 + "'.");
        }
        symbol_table[$2] = natural;
    }
|
    T_TIME T_ID
    {
        if(symbol_table.find($2) != symbol_table.end()) {
            semantic_error(@1.begin.line, "Re-declared variable: '" + $2 + "'.");
        }
	symbol_table[$2] = t_time;
    }
|
    T_REAL T_ID
    {
        if(symbol_table.find($2) != symbol_table.end()) {
            semantic_error(@1.begin.line, "Re-declared variable: '" + $2 + "'.");
        }
	symbol_table[$2] = real;
    }
;

commands:
    // empty
    {
        $$ = "";
    }
|
    commands command
    {
        $$ = $1 + $2;
    }
;

command:
    T_READ T_OPEN T_ID T_CLOSE
    {
        if(symbol_table.find($3) == symbol_table.end()) {
            semantic_error(@3.begin.line, "Undeclared variable: '" + $3 + "'.");
        }
        std::stringstream ss;
        type typ = symbol_table[$3].typ;
        ss << "call " << (typ == boolean ? "read_boolean" : "read_natural") << std::endl;
        ss << "mov [" << symbol_table[$3].label << "], " << (typ == boolean ? "al" : "eax") << std::endl;
        $$ = ss.str();
    }
|
    T_WRITE T_OPEN expression T_CLOSE
    {
        std::stringstream ss;
        ss << $3.code;
        if($3.typ == boolean) {
            ss << "and eax,1" << std::endl;
        }
        ss << "push eax" << std::endl;
        ss << "call " << ($3.typ == boolean ? "write_boolean" : "write_natural") << std::endl;
        ss << "add esp,4" << std::endl;
        $$ = ss.str();
    }
|
    T_ID T_ASSIGN expression
    {
        if(symbol_table.find($1) == symbol_table.end()) {
            semantic_error(@1.begin.line, "Undeclared variable: '" + $1 + "'.");
        }
        if(symbol_table[$1].typ != $3.typ) {
            semantic_error(@1.begin.line, "Type error in assignment.");
        }
        std::stringstream ss;
        ss << $3.code;
        ss << "mov [" << symbol_table[$1].label << "], "
           << ($3.typ == boolean ? "al" : "eax") << std::endl; 
        $$ = ss.str();
    }
|
    T_IF expression T_THEN commands T_ENDIF
    {
        if($2.typ != boolean) {
            semantic_error(@2.begin.line, "Condition must be boolean.");
        }
        std::stringstream ss;
        std::string end_label = next_label();
        ss << $2.code
           << "cmp al,1\n"
           << "jne near " << end_label << std::endl
           << $4
           << end_label << ":\n";
        $$ = ss.str();
    }
|
    T_IF expression T_THEN commands T_ELSE commands T_ENDIF
    {
        if($2.typ != boolean) {
            semantic_error(@2.begin.line, "Condition must be boolean.");
        }
        std::stringstream ss;
        std::string else_label = next_label();
        std::string end_label = next_label();
        ss << $2.code
           << "cmp al,1\n"
           << "jne near " << else_label << std::endl
           << $4
           << "jmp " << end_label << std::endl
           << else_label << ":\n"
           << $6
           << end_label << ":\n";
        $$ = ss.str();
    }
|
    T_WHILE expression T_DO commands T_DONE
    {
        if($2.typ != boolean) {
            semantic_error(@2.begin.line, "Condition must be boolean.");
        }
        std::stringstream ss;
        std::string start_label = next_label();
        std::string end_label = next_label();
        ss << start_label << ":\n"
           << $2.code
           << "cmp al,1\n"
           << "jne near " << end_label << std::endl
           << $4
           << "jmp " << start_label << std::endl
           << end_label << ":\n";
        $$ = ss.str();
    }
|
    expression T_ADD expression
    {
        if($2.typ != boolean) {
            semantic_error(@2.begin.line, "Condition must be boolean.");
        }
        std::stringstream ss;
        std::string start_label = next_label();
        std::string end_label = next_label();
        ss << start_label << ":\n"
           << $2.code
           << "cmp al,1\n"
           << "jne near " << end_label << std::endl
           << $4
           << "jmp " << start_label << std::endl
           << end_label << ":\n";
        $$ = ss.str();
    }
;

expression:
    T_NUM
    {
        std::stringstream ss;
        ss << "mov eax," << $1 << std::endl;
        $$ = expression(natural, ss.str());
    }
|
    T_TRUE
    {
        std::stringstream ss;
        ss << "mov al,1" << std::endl;
        $$ =  expression(boolean, ss.str());
    }
|
    T_FALSE
    {
        std::stringstream ss;
        ss << "mov al,0" << std::endl;
        $$ =  expression(boolean, ss.str());
    }
|
    T_TIME
    {
        std::stringstream ss;
        ss << "mov al,1" << std::endl;
        $$ =  expression(t_time, ss.str());
    }
|
    T_MINUTE "("T_ID")"
    {
        if(symbol_table.find($3) == symbol_table.end()) {
	        semantic_error(@3.begin.line, "Undeclared variable: '" + $3 + "'.");
        }
	if(symbol_table[$3].typ != t_time) {
		semantic_error(@3.begin.line, "Must be t_time:" + $3 + "'.");
	}
        std::stringstream ss;
        ss << "mov al,1" << std::endl;
        $$ =  expression(natural, ss.str());
    }
|
    T_HOUR "("T_ID")"
    {
        if(symbol_table.find($3) == symbol_table.end()) {
            semantic_error(@3.begin.line, "Undeclared variable: '" + $3 + "'.");
        }
	if(symbol_table[$3].typ != t_time) {
		semantic_error(@3.begin.line, "Must be t_time:" + $3 + "'.");
	}
        std::stringstream ss;
        ss << "mov al,1" << std::endl;
        $$ =  expression(natural, ss.str());
    }
|
    T_REAL_LITERAL
    {
        std::stringstream ss;
        ss << "mov al,1" << std::endl;
        $$ =  expression(real, ss.str());
    }
|
    T_INT T_OPEN T_ID T_CLOSE
    {
	if(symbol_table.find($3) == symbol_table.end()) {
            semantic_error(@3.begin.line, "Undeclared variable: '" + $3 + "'.");
        }
	if(symbol_table[$3].typ != real) {
		semantic_error(@3.begin.line, "Must be real:" + $3 + "'.");
	}
        std::stringstream ss;
        ss << "mov al,1" << std::endl;
        $$ =  expression(natural, ss.str());
    }
|
    T_FRAC T_OPEN T_ID T_CLOSE
    {
	if(symbol_table.find($3) == symbol_table.end()) {
            semantic_error(@3.begin.line, "Undeclared variable: '" + $3 + "'.");
        }
	if(symbol_table[$3].typ != real) {
		semantic_error(@3.begin.line, "Must be real:" + $3 + "'.");
	}
        std::stringstream ss;
        ss << "mov al,1" << std::endl;
        $$ =  expression(natural, ss.str());
    }
|
    T_ID
    {
        if(symbol_table.find($1) == symbol_table.end()) {
            semantic_error(@1.begin.line, "Undeclared variable: '" + $1 + "'.");
        }
        type typ = symbol_table[$1].typ;
        std::stringstream ss;
        ss << "mov " << (typ == boolean ? "al" : "eax") << ",[" << symbol_table[$1].label << "]\n";
        $$ =  expression(typ, ss.str());
    }
|
    expression T_ADD expression
    {
        if($1.typ != natural) {
            semantic_error(@1.begin.line, "Type error in left argument of '+'.");
        }
        if($3.typ != natural) {
            semantic_error(@3.begin.line, "Type error in right argument of '+'.");
        }
        std::stringstream ss;
        ss << $1.code;
        ss << "push eax" << std::endl;
        ss << $3.code;
        ss << "mov ecx,eax" << std::endl;
        ss << "pop eax" << std::endl;
        ss << "add eax,ecx" << std::endl;
        $$ =  expression(natural, ss.str());
    }
|
    expression T_SUB expression
    {
        if($1.typ != natural) {
            semantic_error(@1.begin.line, "Type error in left argument of '-'.");
        }
        if($3.typ != natural) {
            semantic_error(@3.begin.line, "Type error in right argument of '-'.");
        }
        std::stringstream ss;
        ss << $1.code;
        ss << "push eax" << std::endl;
        ss << $3.code;
        ss << "mov ecx,eax" << std::endl;
        ss << "pop eax" << std::endl;
        ss << "sub eax,ecx" << std::endl;
        $$ =  expression(natural, ss.str());
    }
|
    expression T_MUL expression
    {
        if($1.typ != natural) {
            semantic_error(@1.begin.line, "Type error in left argument of '*'.");
        }
        if($3.typ != natural) {
            semantic_error(@3.begin.line, "Type error in right argument of '*'.");
        }
        std::stringstream ss;
        ss << $1.code;
        ss << "push eax" << std::endl;
        ss << $3.code;
        ss << "mov ecx,eax" << std::endl;
        ss << "pop eax" << std::endl;
        ss << "xor edx,edx" << std::endl;
        ss << "mul ecx" << std::endl;
        $$ =  expression(natural, ss.str());
    }
|
    expression T_DIV expression
    {
        if($1.typ != natural) {
            semantic_error(@1.begin.line, "Type error in left argument of '/'.");
        }
        if($3.typ != natural) {
            semantic_error(@3.begin.line, "Type error in right argument of '/'.");
        }
        std::stringstream ss;
        ss << $1.code;
        ss << "push eax" << std::endl;
        ss << $3.code;
        ss << "mov ecx,eax" << std::endl;
        ss << "pop eax" << std::endl;
        ss << "xor edx,edx" << std::endl;
        ss << "div ecx" << std::endl;
        $$ =  expression(natural, ss.str());
    }
|
    expression T_MOD expression
    {
        if($1.typ != natural) {
            semantic_error(@1.begin.line, "Type error in left argument of '%'.");
        }
        if($3.typ != natural) {
            semantic_error(@3.begin.line, "Type error in right argument of '%'.");
        }
        std::stringstream ss;
        ss << $1.code;
        ss << "push eax" << std::endl;
        ss << $3.code;
        ss << "mov ecx,eax" << std::endl;
        ss << "pop eax" << std::endl;
        ss << "xor edx,edx" << std::endl;
        ss << "div ecx" << std::endl;
        ss << "mov eax,edx" << std::endl;
        $$ =  expression(natural, ss.str());
    }
|
    expression T_LESS expression
    {
        if($1.typ != natural) {
            semantic_error(@1.begin.line, "Type error in left argument of '<'.");
        }
        if($3.typ != natural) {
            semantic_error(@3.begin.line, "Type error in right argument of '<'.");
        }
        std::stringstream ss;
        ss << $1.code;
        ss << "push eax" << std::endl;
        ss << $3.code;
        ss << "mov ecx,eax" << std::endl;
        ss << "pop eax" << std::endl;
        ss << "cmp eax,ecx" << std::endl;
        ss << "mov al,0" << std::endl;
        ss << "mov cx,1" << std::endl;
        ss << "cmovb ax,cx" << std::endl;
        $$ =  expression(boolean, ss.str());
    }
|
    expression T_GREATER expression
    {
        if($1.typ != natural) {
            semantic_error(@1.begin.line, "Type error in left argument of '>'.");
        }
        if($3.typ != natural) {
            semantic_error(@3.begin.line, "Type error in right argument of '>'.");
        }
        std::stringstream ss;
        ss << $1.code;
        ss << "push eax" << std::endl;
        ss << $3.code;
        ss << "mov ecx,eax" << std::endl;
        ss << "pop eax" << std::endl;
        ss << "cmp eax,ecx" << std::endl;
        ss << "mov al,0" << std::endl;
        ss << "mov cx,1" << std::endl;
        ss << "cmova ax,cx" << std::endl;
        $$ =  expression(boolean, ss.str());
    }
|
    expression T_LESSEQ expression
    {
        if($1.typ != natural) {
            semantic_error(@1.begin.line, "Type error in left argument of '<='.");
        }
        if($3.typ != natural) {
            semantic_error(@3.begin.line, "Type error in right argument of '<='.");
        }
        std::stringstream ss;
        ss << $1.code;
        ss << "push eax" << std::endl;
        ss << $3.code;
        ss << "mov ecx,eax" << std::endl;
        ss << "pop eax" << std::endl;
        ss << "cmp eax,ecx" << std::endl;
        ss << "mov al,0" << std::endl;
        ss << "mov cx,1" << std::endl;
        ss << "cmovbe ax,cx" << std::endl;
        $$ =  expression(boolean, ss.str());
    }
|
    expression T_GREATEREQ expression
    {
        if($1.typ != natural) {
            semantic_error(@1.begin.line, "Type error in left argument of '>='.");
        }
        if($3.typ != natural) {
            semantic_error(@3.begin.line, "Type error in right argument of '>='.");
        }
        std::stringstream ss;
        ss << $1.code;
        ss << "push eax" << std::endl;
        ss << $3.code;
        ss << "mov ecx,eax" << std::endl;
        ss << "pop eax" << std::endl;
        ss << "cmp eax,ecx" << std::endl;
        ss << "mov al,0" << std::endl;
        ss << "mov cx,1" << std::endl;
        ss << "cmovae ax,cx" << std::endl;
        $$ =  expression(boolean, ss.str());
    }
|
    expression T_AND expression
    {
        if($1.typ != boolean) {
            semantic_error(@1.begin.line, "Type error in left argument of 'and'.");
        }
        if($3.typ != boolean) {
            semantic_error(@3.begin.line, "Type error in right argument of 'and'.");
        }
        std::stringstream ss;
        ss << $1.code;
        ss << "push ax" << std::endl;
        ss << $3.code;
        ss << "mov cx,ax" << std::endl;
        ss << "pop ax" << std::endl;
        ss << "cmp al,1" << std::endl;
        ss << "cmove ax,cx" << std::endl;
        $$ =  expression(boolean, ss.str());
    }
|
    expression T_OR expression
    {
        if($1.typ != boolean) {
            semantic_error(@1.begin.line, "Type error in left argument of 'or'.");
        }
        if($3.typ != boolean) {
            semantic_error(@3.begin.line, "Type error in right argument of 'or'.");
        }
        std::stringstream ss;
        ss << $1.code;
        ss << "push ax" << std::endl;
        ss << $3.code;
        ss << "mov cx,ax" << std::endl;
        ss << "pop ax" << std::endl;
        ss << "cmp al,0" << std::endl;
        ss << "cmove ax,cx" << std::endl;
        $$ =  expression(boolean, ss.str());
    }
|
    expression T_EQ expression
    {
        if($1.typ != $3.typ) {
            semantic_error(@1.begin.line, "Type error in arguments of '='.");
        }
        std::stringstream ss;
        if($1.typ == boolean) {
            ss << $1.code;
            ss << "push ax" << std::endl;
            ss << $3.code;
            ss << "mov cx,ax" << std::endl;
            ss << "pop ax" << std::endl;
            ss << "cmp ax,cx" << std::endl;
            ss << "mov al,0" << std::endl;
            ss << "mov cx,1" << std::endl;
            ss << "cmove ax,cx" << std::endl;
        } else {
            ss << $1.code;
            ss << "push eax" << std::endl;
            ss << $3.code;
            ss << "mov ecx,eax" << std::endl;
            ss << "pop eax" << std::endl;
            ss << "cmp eax,ecx" << std::endl;
            ss << "mov al,0" << std::endl;
            ss << "mov cx,1" << std::endl;
            ss << "cmove ax,cx" << std::endl;
        }
        $$ =  expression(boolean, ss.str());
    }
|
    T_NOT expression
    {
        if($2.typ != boolean) {
            semantic_error(@1.begin.line, "Type error in argument of 'not'.");
        }
        std::stringstream ss;
        ss << $2.code;
        ss << "xor al,1" << std::endl;
        $$ =  expression(boolean, ss.str());
    }
|
    T_OPEN expression T_CLOSE
    {
        $$ = $2;
    }
;

%%
