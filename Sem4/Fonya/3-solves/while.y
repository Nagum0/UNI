%language "c++"
%locations
%define api.value.type variant

%code requires {
#include "semantics.hh"
}

%code provides {
int yylex(yy::parser::semantic_type* yylval, yy::parser::location_type* yylloc);
}

%token T_PROGRAM
%token T_BEGIN
%token T_END
%token T_INTEGER 
%token T_BOOLEAN
%token T_DATE
%token T_SKIP
%token T_IF
%token T_THEN
%token T_ELSE
%token T_ENDIF
%token T_WHILE
%token T_DO
%token T_DONE
%token T_REPEAT
%token T_UNTIL
%token T_READ
%token T_WRITE
%token T_SEMICOLON
%token T_ASSIGN
%token T_OPEN
%token T_CLOSE
%token <std::string> T_NUM
%token T_TRUE
%token T_FALSE
%token <std::string> T_ID
%token T_QUESTIONMARK
%token T_COLON
%token T_COMMA
%token T_FOR
%token T_FROM
%token T_UPTO
%token T_DOWNTO
%token T_DATE_LIT
%token T_GET_DAY
%token T_GET_MONTH
%token T_GET_YEAR
%token T_GOTO 

%left T_OR T_AND
%left T_EQ
%left T_LESS T_GR
%left T_ADD T_SUB
%left T_MUL T_DIV T_MOD
%precedence T_NOT

%type <type> expression;
%type <simultan_assignment> multi_assign;

%%

start:
    T_PROGRAM T_ID declarations T_BEGIN statements T_END
    {
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

declaration:
    T_INTEGER T_ID T_SEMICOLON
    {
		if( symbol_table.count($2) > 0 )
		{
			semantic_error(@1.begin.line, "Re-declared variable: " + $2);
		}
		symbol_table[$2] = integer;
    }
|
    T_BOOLEAN T_ID T_SEMICOLON
    {
		if( symbol_table.count($2) > 0 )
		{
			semantic_error(@1.begin.line, "Re-declared variable: " + $2);
		}
		symbol_table[$2] = boolean;
    }
|
    T_DATE T_ID T_SEMICOLON
    {
        if( symbol_table.count($2) > 0 )
		{
			semantic_error(@1.begin.line, "Re-declared variable: " + $2);
		}
		symbol_table[$2] = my_date;
    }
;

statements:
    statement
    {
    }
|
    statement statements
    {
    }
;

multi_assign:
    T_ID T_ASSIGN expression
    {
        std::list<std::string> left;
        left.push_front($1);
        std::list<type> right;
        right.push_back($3);
        $$ = simultan_assignment(left, right); 
    }
|
    T_COMMA T_ID multi_assign expression T_COMMA
    {
        ($3.left).push_front($2);
        ($3.right).push_back($4);
        $$ = $3; 
    }
;
 

statement:
    T_SKIP T_SEMICOLON
    {
    }
|
    multi_assign T_SEMICOLON 
    {
		std::list<std::string>::iterator it_left;
        std::list<type>::iterator it_right = ($1.right).begin();
        for (it_left = ($1.left).begin(); it_left != ($1.left).end(); ++it_left){
            if(symbol_table.count(*it_left) == 0) {
                semantic_error(@1.begin.line, std::string("Undefined variable: ") + *it_left);
            }
            if(symbol_table[*it_left] != *it_right) {
                semantic_error(@1.begin.line, "Left and right hand sides of assignment are of different types.");
            }
            ++it_right;
        } 
    }
|
    T_READ T_OPEN T_ID T_CLOSE T_SEMICOLON
    {
		if( symbol_table.count($3) == 0 )
		{
			semantic_error(@1.begin.line, "Undeclared variable: " + $3);
		}
    }
|
    T_WRITE T_OPEN expression T_CLOSE T_SEMICOLON
    {
    }
|
    T_IF expression T_THEN statements T_ENDIF
    {
		if($2 != boolean)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
    }
|
    T_IF expression T_THEN statements T_ELSE statements T_ENDIF
    {
		if($2 != boolean)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
    }
|
    T_WHILE expression T_DO statements T_DONE
    {
		if($2 != boolean)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
    }
|
    T_REPEAT statements T_UNTIL expression
    {
        if($4 != boolean)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
    }
|
    //version1
    T_FOR T_ID T_FROM expression T_UPTO expression T_DO statements T_DONE
    {
        if( symbol_table.count($2) == 0 )
		{
			semantic_error(@2.begin.line, "Undeclared variable: " + $2);
		}
		if(symbol_table[$2] != integer || $4 !=integer || $6 != integer)
		{
		   semantic_error(@2.begin.line, "Type error.");
		}
    }
|
    //version2
    T_FOR T_ID T_FROM T_NUM T_DOWNTO T_NUM T_DO statements T_DONE
    {
        if( symbol_table.count($2) == 0 )
		{
			semantic_error(@2.begin.line, "Undeclared variable: " + $2);
		}
        if(stoi($4)<stoi($6))
		{
		   semantic_error(@2.begin.line, "Logical error (for loop).");
		}
    }
|
    T_GOTO T_ID T_SEMICOLON
    {
        if( label_table.count($2) == 0 )
		{
			semantic_error(@1.begin.line, "Undeclared label: " + $2);
		}
    }
|
    T_ID T_COLON
    {
        if( label_table.count($1) > 0 )
		{
			semantic_error(@1.begin.line, "Re-declared label: " + $1);
		}
		label_table[$1] = @1.begin.line;
    } 
;

expression:
    T_NUM
    {
        std::cout << "Val: " << $1 << std::endl;
		$$ = integer;
    }
|
    T_TRUE
    {
		$$ = boolean;
    }
|
    T_FALSE
    {
		$$ = boolean;
    }
|
    T_ID
    {
		if( symbol_table.count($1) == 0 )
		{
			semantic_error(@1.begin.line, "Undeclared variable: " + $1);
		}
		$$ = symbol_table[$1];
    }
|
    T_DATE_LIT
    {
        $$ = my_date;
    }
|
    T_GET_DAY T_OPEN expression T_CLOSE
    {
        if($3 != my_date)
		{
		   semantic_error(@1.begin.line, "Type error.");
           
		}
		$$ = integer;
    }
|
    T_GET_MONTH T_OPEN expression T_CLOSE
    {
        if($3 != my_date)
		{
		   semantic_error(@1.begin.line, "Type error.");
           
		}
		$$ = integer;
    }
|
    T_GET_YEAR T_OPEN expression T_CLOSE
    {
        if($3 != my_date)
		{
		   semantic_error(@1.begin.line, "Type error.");
           
		}
		$$ = integer;
    } 
|
    expression T_ADD expression
    {
		if($1 != integer || $3 != integer)
		{
		   semantic_error(@1.begin.line, "Type error.");
           
		}
		$$ = integer;
    }
|
    expression T_SUB expression
    {
		if($1 != integer || $3 != integer)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
		$$ = integer;
    }
|
    expression T_MUL expression
    {
		if($1 != integer || $3 != integer)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
		$$ = integer;
    }
|
    expression T_DIV expression
    {
		if($1 != integer || $3 != integer)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
		$$ = integer;
    }
|
    expression T_MOD expression
    {
		if($1 != integer || $3 != integer)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
		$$ = integer;
    }
|
    expression T_LESS expression
    {
		if($1 != integer || $3 != integer)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
		$$ = boolean;
    }
|
    expression T_GR expression
    {
		if($1 != integer || $3 != integer)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
		$$ = boolean;
    }
|
    expression T_EQ expression
    {
		if($1 != $3)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
		$$ = boolean;
    }
|
    expression T_AND expression
    {
		if($1 != boolean || $3 != boolean)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
		$$ = boolean;
    }
|
    expression T_OR expression
    {
		if($1 != boolean || $3 != boolean)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
		$$ = boolean;
    }
|
    T_NOT expression
    {
		if($2 != boolean)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
		$$ = boolean;
    }
|
    T_OPEN expression T_CLOSE
    {
		$$ = $2;
    }
|
    T_OPEN expression T_QUESTIONMARK expression T_COLON expression T_CLOSE 
    {
        if($2 != boolean)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
        if($4 != $6)
		{
		   semantic_error(@1.begin.line, "Type error.");
		}
		$$ = $4;
    }
;
