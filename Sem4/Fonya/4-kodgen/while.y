%language "c++"
%locations
%define api.value.type variant

%code requires {
#include "../semantics.hh"
}

%code provides {
int yylex(yy::parser::semantic_type* yylval, yy::parser::location_type* yylloc);
}

%token T_PROGRAM
%token T_BEGIN
%token T_END
%token T_INTEGER 
%token T_BOOLEAN
%token T_CHAR
%token T_SKIP
%token T_IF
%token T_THEN
%token T_ELSE
%token T_ENDIF
%token T_WHILE
%token T_DO
%token T_DONE
%token T_READ
%token T_WRITE
%token T_STDOUT
%token T_ASSERT
%token T_SEMICOLON
%token T_ASSIGN
%token T_OPEN
%token T_CLOSE
%token T_OPEN_BRACKET;
%token T_CLOSE_BRACKET;
%token <std::string> T_NUM
%token T_TRUE
%token T_FALSE
%token <std::string> T_ID
%token T_QMARK
%token T_COLON
%token T_MULTI
%token <std::string> T_CHAR_LIT
%token <std::string> T_STRING_LIT
%token T_COMMA;
%token T_LET;

%left T_OR T_AND
%left T_EQ
%left T_LESS T_GR
%left T_ADD T_SUB
%left T_MUL T_DIV T_MOD
%precedence T_NOT

%type <expression> expression
%type <type> variable
%type <std::string> statement statements

%%

start:
    T_PROGRAM T_ID declarations T_BEGIN statements T_END
    {
        std::cout << "global main" << std::endl;
        std::cout << "extern read_unsigned, write_unsigned" << std::endl;
        std::cout << "extern read_boolean, write_boolean" << std::endl;
        std::cout << "extern write_char, write_str" << std::endl;
        std::cout << "segment .bss" << std::endl;

        std::map<std::string, symbol_data>::iterator it; 
        for(it = symbol_table.begin(); it != symbol_table.end(); ++it) {
            std::string label = it->second.label;
            std::cout
                << it->second.label << ": "
                << ((it->second.typ == boolean || it->second.typ == ch) ? "resb " : "resd ")
                << (it->second.is_array ? it->second.array_size : 1)
                << std::endl;
        }

        std::cout << std::endl;
        std::cout << "segment .text" << std::endl;
        std::cout << "main:" << std::endl;
        std::cout << $5 << std::endl;

        size_t used_stack_size = vars_size(vars);
        std::cout << "add esp, " << std::to_string(used_stack_size) << std::endl;

        std::cout << "mov eax, 0" << std::endl;
        std::cout << "ret" << std::endl;
    }
;

declarations:
    // empty
    {
    }
|
    declaration declarations
    {
    }
;

variable:
    T_INTEGER 
    {
        $$ = integer;
    }
|
    T_BOOLEAN
    {
        $$ = boolean;
    }
|
    T_CHAR
    {
        $$ = ch;
    }
;

declaration:
    // Variable declaration
    variable T_ID T_SEMICOLON
    {
		if( symbol_table.count($2) > 0 )
		{
			semantic_error(@1.begin.line, "Re-declared variable: " + $2);
		}
		symbol_table[$2] = symbol_data($1);
        symbol_table[$2].is_array = false;
    }
|
    // Array declaration
    variable T_ID T_OPEN_BRACKET T_NUM T_CLOSE_BRACKET T_SEMICOLON
    {
        if( symbol_table.count($2) > 0 )
        {
            semantic_error(@1.begin.line, "Re-declared variable: " + $2);
        }
        
        int size = std::stoi($4);
        symbol_table[$2] = symbol_data($1);
        symbol_table[$2].is_array = true;
        symbol_table[$2].array_size = size;
    }
;

statements:
    statement
    {
        $$ = $1;
    }
|
    statement statements
    {
        $$ = $1 + $2;
    }
;

statement:
    T_SKIP T_SEMICOLON
    {
        $$ = "nop";
    }
|
    T_ID T_ASSIGN expression T_SEMICOLON
    {
		if (symbol_table.count($1) == 0 && vars.count($1) == 0)
			semantic_error(@1.begin.line, "Undeclared variable: " + $1);
        
        bool local = vars.count($1) == 1;
        
        if (!local) 
        {
		    if (symbol_table[$1].typ != $3.typ)
		        semantic_error(@1.begin.line, "Type error.");

            if ($3.typ == integer)
                $$ = "" +
                     $3.code +
                     "mov [" + symbol_table[$1].label + "], eax\n";
            else if ($3.typ == boolean || $3.typ == ch)
                $$ = "" +
                     $3.code +
                     "mov [" + symbol_table[$1].label + "], al\n";
        }
        else
        {
            if (vars[$1].typ != $3.typ)
		        semantic_error(@1.begin.line, "Type error.");
           
            std::string result_reg = (vars[$1].typ == integer) ? "eax" : "al";
            std::string value_size = (vars[$1].typ == integer) ? "DWORD" : "BYTE";

            $$ = $3.code + 
                "mov " + value_size + "[ebp - " + std::to_string(vars[$1].stack_pos) + "], " + result_reg + "\n";
        }
    }
|
    T_ID T_ASSIGN T_STRING_LIT T_SEMICOLON
    {
        if (symbol_table.count($1) == 0)
		{
			semantic_error(@1.begin.line, "Undeclared variable: " + $1);
		}
        
        if (symbol_table[$1].typ != ch || !symbol_table[$1].is_array)
        {
            semantic_error(@1.begin.line, "Type error.");
        }


        std::string str = extract_str($3);

        if (symbol_table[$1].array_size < str.size()) 
        {
            semantic_error(@3.begin.line, "Array size and string literal sizes do not match: " + std::to_string(symbol_table[$1].array_size) + ", " + std::to_string(str.size()));
        }

        $$ = "";
        for (size_t i = 0; i < str.size(); ++i)
        {   
            char c = str[i];
            $$ += "mov BYTE [" + symbol_table[$1].label + " + " + std::to_string(i) + "], " + std::to_string(static_cast<int>(c)) + "\n";
        }
    }
|
    T_ID T_OPEN_BRACKET expression T_CLOSE_BRACKET T_ASSIGN expression T_SEMICOLON
    {
        if( symbol_table.count($1) == 0 )
		{
			semantic_error(@1.begin.line, "Undeclared variable: " + $1);
		}

        if(symbol_table[$1].typ != $6.typ)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}

        if ($3.typ != integer) 
        {
		   semantic_error(@3.begin.line, "Type error.");
        }
        
        if (symbol_table[$1].typ == integer) 
        {
            $$ = "" +
                $3.code +
                "mov esi, eax\n" +
                $6.code +
                "mov [" + symbol_table[$1].label + " + esi * 4], eax\n";
        }
        else if (symbol_table[$1].typ == boolean || symbol_table[$1].typ == ch) 
        {
            $$ = "" +
                $3.code +
                "mov esi, eax\n" +
                $6.code +
                "mov [" + symbol_table[$1].label + " + esi * 1], al\n";
        }
    }
|
    T_LET variable T_ID T_SEMICOLON
    {
        if (symbol_table.count($3) != 0 || vars.count($3) != 0)
            semantic_error(@3.begin.line, "Redeclaration of variable: " + $3);

        size_t size = ($2 == boolean || $2 == ch) ? 1 : 4;
        size_t stack_pos = vars_get_largest_offset(vars) + size;

        vars[$3] = variable($2, size, stack_pos);

        $$ = "sub esp, " + std::to_string(size) + "\n";
    }
|
    T_LET variable T_ID T_ASSIGN expression T_SEMICOLON
    {
        if (symbol_table.count($3) != 0 || vars.count($3) != 0)
        {
            semantic_error(@3.begin.line, "Redeclaration of variable: " + $3);
        }

        if ($2 != $5.typ)
        {
            semantic_error(@2.begin.line, "Type error.");
        }
        
        size_t size = ($2 == boolean || $2 == ch) ? 1 : 4;
        std::string exp_result_reg = ($2 == boolean || $2 == ch) ? "al" : "eax";
        size_t stack_pos = vars_get_largest_offset(vars) + size;

        vars[$3] = variable($2, size, stack_pos);
        
        $$ = "sub esp, " + std::to_string(size) + "\n" +
            $5.code +
            "mov [ebp - " + std::to_string(stack_pos) + "], " + exp_result_reg + "\n";
    }
|
    T_LET variable T_OPEN_BRACKET T_NUM T_CLOSE_BRACKET T_ID T_SEMICOLON
    {
        if (vars.count($6) != 0)
            semantic_error(@6.begin.line, "Redeclaration of variable: " + $6);
        
        size_t array_size = std::stoi($4);
        size_t size = ($2 == integer ? 4 : 1) * array_size;
        size_t stack_pos = vars_get_largest_offset(vars) + size;

        vars[$6] = variable($2, size, stack_pos);
        vars[$6].is_array = true;
        vars[$6].array_size = array_size;
        
        $$ = "sub esp, " + std::to_string(size) + "\n";
    }
|
    T_READ T_OPEN T_ID T_CLOSE T_SEMICOLON
    {
		if( symbol_table.count($3) == 0 )
		{
			semantic_error(@1.begin.line, "Undeclared variable: " + $3);
		}
        if(symbol_table[$3].typ == integer)
        {
            $$ = "call read_unsigned\nmov [" + symbol_table[$3].label + "], eax\n";
        }
        if(symbol_table[$3].typ == boolean)
        {
            $$ = "call read_boolean\nmov [" + symbol_table[$3].label + "], al\n";
        }
    }
|
    T_STDOUT T_OPEN T_ID T_COMMA expression T_CLOSE T_SEMICOLON
    {
        if (symbol_table.count($3) == 0)
        {
			semantic_error(@3.begin.line, "Undeclared variable: " + $3);
        }

        if (symbol_table[$3].typ != ch)
        {
			semantic_error(@3.begin.line, "Type error.");
        }

        if ($5.typ != integer)
        {
			semantic_error(@5.begin.line, "Type error.");
        }
        
        $$ = "" +
            $5.code +
            "push eax\n" +
            "push " + symbol_table[$3].label + "\n" +
            "call write_str\n" +
            "add esp, 8\n";
    }
|
    T_WRITE T_OPEN expression T_CLOSE T_SEMICOLON
    {
        if($3.typ == integer)
        {
            $$ = "" +
                 $3.code +
                 "push eax\n" +
                 "call write_unsigned\n" +
                 "add esp,4\n";
        }
        else if($3.typ == boolean)
        {
            $$ = "xor eax, eax\n" +
                 $3.code +
                 "push eax\n" +
                 "call write_boolean\n" +
                 "add esp,4\n";
        }
        else if ($3.typ == ch)
        {
            $$ = "xor eax, eax\n" +
                 $3.code +
                 "push eax\n" +
                 "call write_char\n" +
                 "add esp,4\n";
        }
    }
|
    T_IF expression T_THEN statements T_ENDIF
    {
		if($2.typ != boolean)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
        std::string end = next_label();
        $$ = "" +
             $2.code +
             "cmp al, 1\n" +
             "jne near " + end + "\n" +
             $4 +
             end + ":\n";
    }
|
    T_IF expression T_THEN statements T_ELSE statements T_ENDIF
    {
		if($2.typ != boolean)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
        std::string elsel = next_label();
        std::string end = next_label();
        $$ = "" +
             $2.code +
             "cmp al, 1\n" +
             "jne near " + elsel + "\n" +
             $4 +
             "jmp " + end + "\n" +
             elsel + ":\n" +
             $6 +
             end + ":\n";
    }
|
    T_WHILE expression T_DO statements T_DONE
    {
		if($2.typ != boolean)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
        std::string start = next_label();
        std::string end = next_label();
        $$ = "" +
             start + ":\n" +
             $2.code +
             "cmp al, 1\n" +
             "jne near " + end + "\n" +
             $4 +
             "jmp " + start + "\n" +
             end + ":\n";
    }
|
    T_ASSERT T_OPEN expression T_CLOSE T_SEMICOLON
    {
        if ($3.typ != boolean)
        {
            semantic_error(@1.begin.line, "Type error.");
        }

        std::string end = next_label();

        $$ = "" +
            $3.code +
            "cmp al, 0\n" +
            "jne " + end + "\n" +
            "mov eax, 1\n" +
            "ret\n" +
            end + ":\n";
    }
|
    T_MULTI expression statement
    {
        if ($2.typ != integer)
        {
            semantic_error(@1.begin.line, "Type error.");
        }

        std::string start = next_label();
        std::string end = next_label();

        $$ = "" +
            $2.code +
            "mov ecx, eax\n" +
            start + ":\n" +
            "cmp ecx, 0\n" +
            "je " + end + "\n" +
            "dec ecx\n" +
            "push ecx\n" +
            $3 +
            "pop ecx\n" +
            "jmp " + start + "\n" +
            end + ":\n";
    }
;

expression:
    T_NUM
    {
		$$ = expression(integer, "mov eax, " + $1 + "\n");
    }
|
    T_TRUE
    {
		$$ = expression(boolean, "mov al, 1\n");
    }
|
    T_FALSE
    {
		$$ = expression(boolean, "mov al, 0\n");
    }
|
    T_CHAR_LIT
    {
        char c = extract_char($1);
        $$ = expression(ch, "mov al, " + std::to_string(c) + "\n");
    }
|
    T_ID
    {
		if(symbol_table.count($1) == 0 && vars.count($1) == 0)
			semantic_error(@1.begin.line, "Undeclared variable: " + $1);
        
        bool local = vars.count($1) == 1;
        type typ = local ? vars[$1].typ : symbol_table[$1].typ;
        std::string dest_reg = (typ == boolean || typ == ch) ? "al" : "eax";
        
        if (!local) 
            $$ = expression(typ, "mov " + dest_reg + ", [" + symbol_table[$1].label + "]\n");
        else 
            $$ = expression(typ, "mov " + dest_reg + ", [ebp - " + std::to_string(vars[$1].stack_pos) + "]\n");
    }
|
    T_ID T_OPEN_BRACKET expression T_CLOSE_BRACKET
    {
        if( symbol_table.count($1) == 0 )
		{
			semantic_error(@1.begin.line, "Undeclared variable: " + $1);
		}

        if ($3.typ != integer)
        {
            semantic_error(@1.begin.line, "Array must be indexed by an integer.");
        }

        int offset = (symbol_table[$1].typ == boolean || symbol_table[$1].typ == ch) ? 1 : 4;

        $$ = expression(symbol_table[$1].typ,
                        "" +
                        $3.code +
                        "mov esi, eax\n" +
                        "mov eax, [" + symbol_table[$1].label + " + esi * " + std::to_string(offset) + "]\n"
        );
    }
|
    expression T_ADD expression
    {
		if($1.typ != integer || $3.typ != integer)
		{
		   semantic_error(@1.begin.line, "Type error.");
           
		}
		$$ = expression(integer, "" +
                $3.code +
                "push eax\n" +
                $1.code +
                "pop ebx\n" +
                "add eax, ebx\n");
    }
|
    expression T_SUB expression
    {
		if($1.typ != integer || $3.typ != integer)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
		$$ = expression(integer, "" +
                $3.code +
                "push eax\n" +
                $1.code +
                "pop ebx\n" +
                "sub eax, ebx\n");
    }
|
    expression T_MUL expression
    {
		if($1.typ != integer || $3.typ != integer)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
		$$ = expression(integer, "" +
                $3.code +
                "push eax\n" +
                $1.code +
                "pop ebx\n" +
                "mul ebx\n");
    }
|
    expression T_DIV expression
    {
		if($1.typ != integer || $3.typ != integer)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
		$$ = expression(integer,
                "xor edx, edx\n" +
                $3.code +
                "push eax\n" +
                $1.code +
                "pop ebx\n" +
                "div ebx\n");
    }
|
    expression T_MOD expression
    {
		if($1.typ != integer || $3.typ != integer)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
		$$ = expression(integer, 
                "xor edx, edx\n" +
                $3.code +
                "push eax\n" +
                $1.code +
                "pop ebx\n" +
                "div ebx\n" +
                "mov eax, edx\n");
    }
|
    expression T_LESS expression
    {
		if($1.typ != integer || $3.typ != integer)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
		$$ = expression(boolean, "" +
                $3.code +
                "push eax\n" +
                $1.code +
                "pop ebx\n" +
                "cmp eax, ebx\n" +
                "setl al\n");
    }
|
    expression T_GR expression
    {
		if($1.typ != integer || $3.typ != integer)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
		$$ = expression(boolean, "" +
                $3.code +
                "push eax\n" +
                $1.code +
                "pop ebx\n" +
                "cmp eax, ebx\n" +
                "setg al\n");
    }
|
    expression T_EQ expression
    {
		if($1.typ != $3.typ)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
		$$ = expression(boolean, "" +
                $3.code +
                "push eax\n" +
                $1.code +
                "pop ebx\n" +
                "cmp eax, ebx\n" +
                "sete al\n");
    }
|
    expression T_AND expression
    {
		if($1.typ != boolean || $3.typ != boolean)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
		$$ = expression(boolean, "" +
                $3.code +
                "push ax\n" +
                $1.code +
                "pop bx\n" +
                "and al, bl\n");
    }
|
    expression T_OR expression
    {
		if($1.typ != boolean || $3.typ != boolean)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
		$$ = expression(boolean, "" +
                $3.code +
                "push ax\n" +
                $1.code +
                "pop bx\n" +
                "or al, bl\n");
    }
|
    T_NOT expression
    {
		if($2.typ != boolean)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
		$$ = expression(boolean, "" +
                $2.code +
                "xor al, 1\n");
    }
|
    T_OPEN expression T_CLOSE
    {
		$$ = expression($2.typ, "" + $2.code);
    }
|
    expression T_QMARK expression T_COLON expression
    {
        if ($1.typ != $5.typ || $3.typ != boolean)
        {
            semantic_error(@1.begin.line, "Type error.");
        }
        
        std::string second = next_label();
        std::string end = next_label();
        
        $$ = expression($1.typ,
            "" +
            $3.code +
            "cmp al, 1\n" +
            "jne " + second + "\n" +
            $1.code +
            "jmp " + end + "\n" +
            second + ":\n" +
            $5.code +
            end + ":\n"
        );
    }
;
