// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "while.tab.hh"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 136 "while.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_expression: // expression
        value.copy< expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_T_NUM: // T_NUM
      case symbol_kind::S_T_ID: // T_ID
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable: // variable
        value.copy< type > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_expression: // expression
        value.move< expression > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_T_NUM: // T_NUM
      case symbol_kind::S_T_ID: // T_ID
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_variable: // variable
        value.move< type > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
        value.YY_MOVE_OR_COPY< expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_T_NUM: // T_NUM
      case symbol_kind::S_T_ID: // T_ID
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable: // variable
        value.YY_MOVE_OR_COPY< type > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
        value.move< expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_T_NUM: // T_NUM
      case symbol_kind::S_T_ID: // T_ID
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable: // variable
        value.move< type > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
        value.copy< expression > (that.value);
        break;

      case symbol_kind::S_T_NUM: // T_NUM
      case symbol_kind::S_T_ID: // T_ID
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_variable: // variable
        value.copy< type > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
        value.move< expression > (that.value);
        break;

      case symbol_kind::S_T_NUM: // T_NUM
      case symbol_kind::S_T_ID: // T_ID
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_variable: // variable
        value.move< type > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_expression: // expression
        yylhs.value.emplace< expression > ();
        break;

      case symbol_kind::S_T_NUM: // T_NUM
      case symbol_kind::S_T_ID: // T_ID
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_variable: // variable
        yylhs.value.emplace< type > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // start: T_PROGRAM T_ID declarations T_BEGIN statements T_END
#line 58 "while.y"
    {
        std::cout << "global main" << std::endl;
        std::cout << "extern read_unsigned, write_unsigned" << std::endl;
        std::cout << "extern read_boolean, write_boolean" << std::endl;
        std::cout << "segment .bss" << std::endl;

        std::map<std::string, symbol_data>::iterator it; 
        for(it = symbol_table.begin(); it != symbol_table.end(); ++it) {
            std::string label = it->second.label;
            std::cout
                << it->second.label << ": "
                << (it->second.typ == boolean ? "resb " : "resd ")
                << (it->second.is_array ? it->second.array_size : 1)
                << std::endl;
        }

        std::cout << std::endl;
        std::cout << "segment .text" << std::endl;
        std::cout << "main:" << std::endl;
        std::cout << yystack_[1].value.as < std::string > () << std::endl;
        std::cout << "mov eax, 0" << std::endl;
        std::cout << "ret" << std::endl;
    }
#line 751 "while.tab.cc"
    break;

  case 3: // declarations: %empty
#line 85 "while.y"
    {
    }
#line 758 "while.tab.cc"
    break;

  case 4: // declarations: declaration declarations
#line 89 "while.y"
    {
    }
#line 765 "while.tab.cc"
    break;

  case 5: // variable: T_INTEGER
#line 95 "while.y"
    {
        yylhs.value.as < type > () = integer;
    }
#line 773 "while.tab.cc"
    break;

  case 6: // variable: T_BOOLEAN
#line 100 "while.y"
    {
        yylhs.value.as < type > () = boolean;
    }
#line 781 "while.tab.cc"
    break;

  case 7: // declaration: variable T_ID T_SEMICOLON
#line 107 "while.y"
    {
		if( symbol_table.count(yystack_[1].value.as < std::string > ()) > 0 )
		{
			semantic_error(yystack_[2].location.begin.line, "Re-declared variable: " + yystack_[1].value.as < std::string > ());
		}
		symbol_table[yystack_[1].value.as < std::string > ()] = symbol_data(yystack_[2].value.as < type > ());
        symbol_table[yystack_[1].value.as < std::string > ()].is_array = false;
    }
#line 794 "while.tab.cc"
    break;

  case 8: // declaration: variable T_ID T_OPEN_BRACKET T_NUM T_CLOSE_BRACKET T_SEMICOLON
#line 117 "while.y"
    {
        if( symbol_table.count(yystack_[4].value.as < std::string > ()) > 0 )
        {
            semantic_error(yystack_[5].location.begin.line, "Re-declared variable: " + yystack_[4].value.as < std::string > ());
        }
        
        int size = std::stoi(yystack_[2].value.as < std::string > ());
        symbol_table[yystack_[4].value.as < std::string > ()] = symbol_data(yystack_[5].value.as < type > ());
        symbol_table[yystack_[4].value.as < std::string > ()].is_array = true;
        symbol_table[yystack_[4].value.as < std::string > ()].array_size = size;
    }
#line 810 "while.tab.cc"
    break;

  case 9: // statements: statement
#line 132 "while.y"
    {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
    }
#line 818 "while.tab.cc"
    break;

  case 10: // statements: statement statements
#line 137 "while.y"
    {
        yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + yystack_[0].value.as < std::string > ();
    }
#line 826 "while.tab.cc"
    break;

  case 11: // statement: T_SKIP T_SEMICOLON
#line 144 "while.y"
    {
        yylhs.value.as < std::string > () = "nop";
    }
#line 834 "while.tab.cc"
    break;

  case 12: // statement: T_ID T_ASSIGN expression T_SEMICOLON
#line 149 "while.y"
    {
		if( symbol_table.count(yystack_[3].value.as < std::string > ()) == 0 )
		{
			semantic_error(yystack_[3].location.begin.line, "Undeclared variable: " + yystack_[3].value.as < std::string > ());
		}
		if(symbol_table[yystack_[3].value.as < std::string > ()].typ != yystack_[1].value.as < expression > ().typ)
		{
		   semantic_error(yystack_[3].location.begin.line, "Type error.");
		}

        if(yystack_[1].value.as < expression > ().typ == integer)
            yylhs.value.as < std::string > () = "" +
                 yystack_[1].value.as < expression > ().code +
                 "mov [" + symbol_table[yystack_[3].value.as < std::string > ()].label + "], eax\n";
        if(yystack_[1].value.as < expression > ().typ == boolean)
            yylhs.value.as < std::string > () = "" +
                 yystack_[1].value.as < expression > ().code +
                 "mov [" + symbol_table[yystack_[3].value.as < std::string > ()].label + "], al\n";
    }
#line 858 "while.tab.cc"
    break;

  case 13: // statement: T_ID T_OPEN_BRACKET expression T_CLOSE_BRACKET T_ASSIGN expression T_SEMICOLON
#line 170 "while.y"
    {
        if( symbol_table.count(yystack_[6].value.as < std::string > ()) == 0 )
		{
			semantic_error(yystack_[6].location.begin.line, "Undeclared variable: " + yystack_[6].value.as < std::string > ());
		}

        if(symbol_table[yystack_[6].value.as < std::string > ()].typ != yystack_[1].value.as < expression > ().typ)
		{
		   semantic_error(yystack_[6].location.begin.line, "Type error.");
		}

        if (yystack_[4].value.as < expression > ().typ != integer) {
		   semantic_error(yystack_[4].location.begin.line, "Type error.");
        }
        
        if (symbol_table[yystack_[6].value.as < std::string > ()].typ == integer) 
        {
            yylhs.value.as < std::string > () = "" +
                yystack_[4].value.as < expression > ().code +
                "mov esi, eax\n" +
                yystack_[1].value.as < expression > ().code +
                "mov [" + symbol_table[yystack_[6].value.as < std::string > ()].label + " + esi * 4], eax\n";
        }
        else if (symbol_table[yystack_[6].value.as < std::string > ()].typ == boolean) 
        {
            yylhs.value.as < std::string > () = "" +
                yystack_[4].value.as < expression > ().code +
                "mov esi, eax\n" +
                yystack_[1].value.as < expression > ().code +
                "mov [" + symbol_table[yystack_[6].value.as < std::string > ()].label + " + esi * 1], al\n";
        }
    }
#line 895 "while.tab.cc"
    break;

  case 14: // statement: T_READ T_OPEN T_ID T_CLOSE T_SEMICOLON
#line 204 "while.y"
    {
		if( symbol_table.count(yystack_[2].value.as < std::string > ()) == 0 )
		{
			semantic_error(yystack_[4].location.begin.line, "Undeclared variable: " + yystack_[2].value.as < std::string > ());
		}
        if(symbol_table[yystack_[2].value.as < std::string > ()].typ == integer)
        {
            yylhs.value.as < std::string > () = "call read_unsigned\nmov [" + symbol_table[yystack_[2].value.as < std::string > ()].label + "], eax\n";
        }
        if(symbol_table[yystack_[2].value.as < std::string > ()].typ == boolean)
        {
            yylhs.value.as < std::string > () = "call read_boolean\nmov [" + symbol_table[yystack_[2].value.as < std::string > ()].label + "], al\n";
        }
    }
#line 914 "while.tab.cc"
    break;

  case 15: // statement: T_WRITE T_OPEN expression T_CLOSE T_SEMICOLON
#line 220 "while.y"
    {
        if(yystack_[2].value.as < expression > ().typ == integer)
        {
            yylhs.value.as < std::string > () = "" +
                 yystack_[2].value.as < expression > ().code +
                 "push eax\n" +
                 "call write_unsigned\n" +
                 "add esp,4\n";
        }
        if(yystack_[2].value.as < expression > ().typ == boolean)
        {
            yylhs.value.as < std::string > () = "xor eax, eax\n" +
                 yystack_[2].value.as < expression > ().code +
                 "push eax\n" +
                 "call write_boolean\n" +
                 "add esp,4\n";
        }
    }
#line 937 "while.tab.cc"
    break;

  case 16: // statement: T_IF expression T_THEN statements T_ENDIF
#line 240 "while.y"
    {
		if(yystack_[3].value.as < expression > ().typ != boolean)
		{
		   semantic_error(yystack_[4].location.begin.line, "Type error.");
		}
        std::string end = next_label();
        yylhs.value.as < std::string > () = "" +
             yystack_[3].value.as < expression > ().code +
             "cmp al, 1\n" +
             "jne near " + end + "\n" +
             yystack_[1].value.as < std::string > () +
             end + ":\n";
    }
#line 955 "while.tab.cc"
    break;

  case 17: // statement: T_IF expression T_THEN statements T_ELSE statements T_ENDIF
#line 255 "while.y"
    {
		if(yystack_[5].value.as < expression > ().typ != boolean)
		{
		   semantic_error(yystack_[6].location.begin.line, "Type error.");
		}
        std::string elsel = next_label();
        std::string end = next_label();
        yylhs.value.as < std::string > () = "" +
             yystack_[5].value.as < expression > ().code +
             "cmp al, 1\n" +
             "jne near " + elsel + "\n" +
             yystack_[3].value.as < std::string > () +
             "jmp " + end + "\n" +
             elsel + ":\n" +
             yystack_[1].value.as < std::string > () +
             end + ":\n";
    }
#line 977 "while.tab.cc"
    break;

  case 18: // statement: T_WHILE expression T_DO statements T_DONE
#line 274 "while.y"
    {
		if(yystack_[3].value.as < expression > ().typ != boolean)
		{
		   semantic_error(yystack_[4].location.begin.line, "Type error.");
		}
        std::string start = next_label();
        std::string end = next_label();
        yylhs.value.as < std::string > () = "" +
             start + ":\n" +
             yystack_[3].value.as < expression > ().code +
             "cmp al, 1\n" +
             "jne near " + end + "\n" +
             yystack_[1].value.as < std::string > () +
             "jmp " + start + "\n" +
             end + ":\n";
    }
#line 998 "while.tab.cc"
    break;

  case 19: // statement: T_ASSERT T_OPEN expression T_CLOSE T_SEMICOLON
#line 292 "while.y"
    {
        if (yystack_[2].value.as < expression > ().typ != boolean)
        {
            semantic_error(yystack_[4].location.begin.line, "Type error.");
        }

        std::string end = next_label();

        yylhs.value.as < std::string > () = "" +
            yystack_[2].value.as < expression > ().code +
            "cmp al, 0\n" +
            "jne " + end + "\n" +
            "mov eax, 1\n" +
            "ret\n" +
            end + ":\n";
    }
#line 1019 "while.tab.cc"
    break;

  case 20: // statement: T_MULTI expression statement
#line 310 "while.y"
    {
        if (yystack_[1].value.as < expression > ().typ != integer)
        {
            semantic_error(yystack_[2].location.begin.line, "Type error.");
        }

        std::string start = next_label();
        std::string end = next_label();

        yylhs.value.as < std::string > () = "" +
            yystack_[1].value.as < expression > ().code +
            "mov ecx, eax\n" +
            start + ":\n" +
            "cmp ecx, 0\n" +
            "je " + end + "\n" +
            "dec ecx\n" +
            "push ecx\n" +
            yystack_[0].value.as < std::string > () +
            "pop ecx\n" +
            "jmp " + start + "\n" +
            end + ":\n";
    }
#line 1046 "while.tab.cc"
    break;

  case 21: // expression: T_NUM
#line 336 "while.y"
    {
		yylhs.value.as < expression > () = expression(integer, "mov eax, " + yystack_[0].value.as < std::string > () + "\n");
    }
#line 1054 "while.tab.cc"
    break;

  case 22: // expression: T_TRUE
#line 341 "while.y"
    {
		yylhs.value.as < expression > () = expression(boolean, "mov al, 1\n");
    }
#line 1062 "while.tab.cc"
    break;

  case 23: // expression: T_FALSE
#line 346 "while.y"
    {
		yylhs.value.as < expression > () = expression(boolean, "mov al, 0\n");
    }
#line 1070 "while.tab.cc"
    break;

  case 24: // expression: T_ID
#line 351 "while.y"
    {
		if( symbol_table.count(yystack_[0].value.as < std::string > ()) == 0 )
		{
			semantic_error(yystack_[0].location.begin.line, "Undeclared variable: " + yystack_[0].value.as < std::string > ());
		}
		if(symbol_table[yystack_[0].value.as < std::string > ()].typ == integer)
        {
            yylhs.value.as < expression > () = expression(symbol_table[yystack_[0].value.as < std::string > ()].typ,
                    "mov eax, [" + symbol_table[yystack_[0].value.as < std::string > ()].label + "]\n");
        }
        if(symbol_table[yystack_[0].value.as < std::string > ()].typ == boolean)
        {
            yylhs.value.as < expression > () = expression(symbol_table[yystack_[0].value.as < std::string > ()].typ,
                    "mov al, [" + symbol_table[yystack_[0].value.as < std::string > ()].label + "]\n");
        }
    }
#line 1091 "while.tab.cc"
    break;

  case 25: // expression: T_ID T_OPEN_BRACKET expression T_CLOSE_BRACKET
#line 369 "while.y"
    {
        if( symbol_table.count(yystack_[3].value.as < std::string > ()) == 0 )
		{
			semantic_error(yystack_[3].location.begin.line, "Undeclared variable: " + yystack_[3].value.as < std::string > ());
		}

        if (yystack_[1].value.as < expression > ().typ != integer)
        {
            semantic_error(yystack_[3].location.begin.line, "Array must be indexed by an integer.");
        }

        int offset = symbol_table[yystack_[3].value.as < std::string > ()].typ == boolean ? 1 : 4;

        yylhs.value.as < expression > () = expression(symbol_table[yystack_[3].value.as < std::string > ()].typ,
                        "" +
                        yystack_[1].value.as < expression > ().code +
                        "mov esi, eax\n" +
                        "mov eax, [" + symbol_table[yystack_[3].value.as < std::string > ()].label + " + esi * " + std::to_string(offset) + "]\n"
        );
    }
#line 1116 "while.tab.cc"
    break;

  case 26: // expression: expression T_ADD expression
#line 391 "while.y"
    {
		if(yystack_[2].value.as < expression > ().typ != integer || yystack_[0].value.as < expression > ().typ != integer)
		{
		   semantic_error(yystack_[2].location.begin.line, "Type error.");
           
		}
		yylhs.value.as < expression > () = expression(integer, "" +
                yystack_[0].value.as < expression > ().code +
                "push eax\n" +
                yystack_[2].value.as < expression > ().code +
                "pop ebx\n" +
                "add eax, ebx\n");
    }
#line 1134 "while.tab.cc"
    break;

  case 27: // expression: expression T_SUB expression
#line 406 "while.y"
    {
		if(yystack_[2].value.as < expression > ().typ != integer || yystack_[0].value.as < expression > ().typ != integer)
		{
		   semantic_error(yystack_[2].location.begin.line, "Type error.");
		}
		yylhs.value.as < expression > () = expression(integer, "" +
                yystack_[0].value.as < expression > ().code +
                "push eax\n" +
                yystack_[2].value.as < expression > ().code +
                "pop ebx\n" +
                "sub eax, ebx\n");
    }
#line 1151 "while.tab.cc"
    break;

  case 28: // expression: expression T_MUL expression
#line 420 "while.y"
    {
		if(yystack_[2].value.as < expression > ().typ != integer || yystack_[0].value.as < expression > ().typ != integer)
		{
		   semantic_error(yystack_[2].location.begin.line, "Type error.");
		}
		yylhs.value.as < expression > () = expression(integer, "" +
                yystack_[0].value.as < expression > ().code +
                "push eax\n" +
                yystack_[2].value.as < expression > ().code +
                "pop ebx\n" +
                "mul ebx\n");
    }
#line 1168 "while.tab.cc"
    break;

  case 29: // expression: expression T_DIV expression
#line 434 "while.y"
    {
		if(yystack_[2].value.as < expression > ().typ != integer || yystack_[0].value.as < expression > ().typ != integer)
		{
		   semantic_error(yystack_[2].location.begin.line, "Type error.");
		}
		yylhs.value.as < expression > () = expression(integer,
                "xor edx, edx\n" +
                yystack_[0].value.as < expression > ().code +
                "push eax\n" +
                yystack_[2].value.as < expression > ().code +
                "pop ebx\n" +
                "div ebx\n");
    }
#line 1186 "while.tab.cc"
    break;

  case 30: // expression: expression T_MOD expression
#line 449 "while.y"
    {
		if(yystack_[2].value.as < expression > ().typ != integer || yystack_[0].value.as < expression > ().typ != integer)
		{
		   semantic_error(yystack_[2].location.begin.line, "Type error.");
		}
		yylhs.value.as < expression > () = expression(integer, 
                "xor edx, edx\n" +
                yystack_[0].value.as < expression > ().code +
                "push eax\n" +
                yystack_[2].value.as < expression > ().code +
                "pop ebx\n" +
                "div ebx\n" +
                "mov eax, edx\n");
    }
#line 1205 "while.tab.cc"
    break;

  case 31: // expression: expression T_LESS expression
#line 465 "while.y"
    {
		if(yystack_[2].value.as < expression > ().typ != integer || yystack_[0].value.as < expression > ().typ != integer)
		{
		   semantic_error(yystack_[2].location.begin.line, "Type error.");
		}
		yylhs.value.as < expression > () = expression(boolean, "" +
                yystack_[0].value.as < expression > ().code +
                "push eax\n" +
                yystack_[2].value.as < expression > ().code +
                "pop ebx\n" +
                "cmp eax, ebx\n" +
                "setl al\n");
    }
#line 1223 "while.tab.cc"
    break;

  case 32: // expression: expression T_GR expression
#line 480 "while.y"
    {
		if(yystack_[2].value.as < expression > ().typ != integer || yystack_[0].value.as < expression > ().typ != integer)
		{
		   semantic_error(yystack_[2].location.begin.line, "Type error.");
		}
		yylhs.value.as < expression > () = expression(boolean, "" +
                yystack_[0].value.as < expression > ().code +
                "push eax\n" +
                yystack_[2].value.as < expression > ().code +
                "pop ebx\n" +
                "cmp eax, ebx\n" +
                "setg al\n");
    }
#line 1241 "while.tab.cc"
    break;

  case 33: // expression: expression T_EQ expression
#line 495 "while.y"
    {
		if(yystack_[2].value.as < expression > ().typ != yystack_[0].value.as < expression > ().typ)
		{
		   semantic_error(yystack_[2].location.begin.line, "Type error.");
		}
		yylhs.value.as < expression > () = expression(boolean, "" +
                yystack_[0].value.as < expression > ().code +
                "push eax\n" +
                yystack_[2].value.as < expression > ().code +
                "pop ebx\n" +
                "cmp eax, ebx\n" +
                "sete al\n");
    }
#line 1259 "while.tab.cc"
    break;

  case 34: // expression: expression T_AND expression
#line 510 "while.y"
    {
		if(yystack_[2].value.as < expression > ().typ != boolean || yystack_[0].value.as < expression > ().typ != boolean)
		{
		   semantic_error(yystack_[2].location.begin.line, "Type error.");
		}
		yylhs.value.as < expression > () = expression(boolean, "" +
                yystack_[0].value.as < expression > ().code +
                "push ax\n" +
                yystack_[2].value.as < expression > ().code +
                "pop bx\n" +
                "and al, bl\n");
    }
#line 1276 "while.tab.cc"
    break;

  case 35: // expression: expression T_OR expression
#line 524 "while.y"
    {
		if(yystack_[2].value.as < expression > ().typ != boolean || yystack_[0].value.as < expression > ().typ != boolean)
		{
		   semantic_error(yystack_[2].location.begin.line, "Type error.");
		}
		yylhs.value.as < expression > () = expression(boolean, "" +
                yystack_[0].value.as < expression > ().code +
                "push ax\n" +
                yystack_[2].value.as < expression > ().code +
                "pop bx\n" +
                "or al, bl\n");
    }
#line 1293 "while.tab.cc"
    break;

  case 36: // expression: T_NOT expression
#line 538 "while.y"
    {
		if(yystack_[0].value.as < expression > ().typ != boolean)
		{
		   semantic_error(yystack_[1].location.begin.line, "Type error.");
		}
		yylhs.value.as < expression > () = expression(boolean, "" +
                yystack_[0].value.as < expression > ().code +
                "xor al, 1\n");
    }
#line 1307 "while.tab.cc"
    break;

  case 37: // expression: T_OPEN expression T_CLOSE
#line 549 "while.y"
    {
		yylhs.value.as < expression > () = expression(yystack_[1].value.as < expression > ().typ, "" + yystack_[1].value.as < expression > ().code);
    }
#line 1315 "while.tab.cc"
    break;

  case 38: // expression: expression T_QMARK expression T_COLON expression
#line 554 "while.y"
    {
        if (yystack_[4].value.as < expression > ().typ != yystack_[0].value.as < expression > ().typ || yystack_[2].value.as < expression > ().typ != boolean)
        {
            semantic_error(yystack_[4].location.begin.line, "Type error.");
        }
        
        std::string second = next_label();
        std::string end = next_label();
        
        yylhs.value.as < expression > () = expression(yystack_[4].value.as < expression > ().typ,
            "" +
            yystack_[2].value.as < expression > ().code +
            "cmp al, 1\n" +
            "jne " + second + "\n" +
            yystack_[4].value.as < expression > ().code +
            "jmp " + end + "\n" +
            second + ":\n" +
            yystack_[0].value.as < expression > ().code +
            end + ":\n"
        );
    }
#line 1341 "while.tab.cc"
    break;


#line 1345 "while.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char parser::yypact_ninf_ = -28;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
       3,   -13,    25,    11,   -28,   -28,   -28,    27,    17,    11,
     118,     7,   -28,    28,   -18,   -18,    23,    30,    31,   -19,
     -18,    41,   118,   -28,    24,   -28,   -18,   -28,   -28,   -28,
      42,   -18,    68,    84,    20,   -18,   -18,   -18,   -18,    55,
     -28,   -28,    29,   162,   -18,    37,   118,   -18,   -18,   -18,
     -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   118,    32,
     182,   202,   119,   220,   -28,    48,   -28,   238,    16,   251,
     277,   277,    21,   103,   103,   -27,   -27,    37,    37,    37,
      54,    51,    57,    58,   -28,    59,   -28,   -28,   118,   -28,
     -18,   -28,   -28,   -28,   -28,   -18,    62,   264,   142,   -28,
     -28
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     3,     1,     5,     6,     0,     0,     3,
       0,     0,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,     7,     0,    11,     0,    21,    22,    23,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,    10,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,     0,    37,     0,     0,     0,
      35,    34,    33,    31,    32,    26,    27,    28,    29,    30,
       0,     0,     0,     0,    12,     0,     8,    25,     0,    16,
       0,    18,    14,    15,    19,     0,     0,    38,     0,    17,
      13
  };

  const signed char
  parser::yypgoto_[] =
  {
     -28,   -28,    72,   -28,   -28,    -3,    43,   -15
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     2,     7,     8,     9,    21,    22,    32
  };

  const signed char
  parser::yytable_[] =
  {
      33,    37,    47,    26,    38,    39,     1,    27,    28,    29,
      30,    43,    55,    56,    57,     3,    45,     5,     6,    41,
      60,    61,    62,    63,    31,     4,    23,    88,    89,    67,
      24,    10,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    68,    34,    11,    40,    25,    59,    42,
      47,    35,    36,    65,    81,    80,    51,    52,    53,    54,
      55,    56,    57,    13,    14,    44,    47,    86,    15,    91,
      92,    16,    17,    18,    99,    97,    93,    94,    46,    95,
      98,    12,    64,    19,    47,    96,    20,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    47,    58,     0,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       0,     0,     0,    47,     0,     0,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    13,    14,     0,     0,
       0,    15,    47,     0,    16,    17,    18,     0,    84,     0,
      53,    54,    55,    56,    57,     0,    19,     0,    47,    20,
       0,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,     0,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    66,     0,     0,     0,     0,     0,
       0,    47,     0,     0,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    82,     0,     0,     0,     0,     0,
       0,    47,     0,     0,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    83,     0,     0,     0,     0,     0,
       0,    47,     0,     0,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    85,     0,     0,     0,     0,    47,
       0,     0,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    87,     0,     0,     0,     0,    47,     0,     0,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      47,    90,     0,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    47,     0,     0,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    47,     0,     0,     0,
       0,    50,    51,    52,    53,    54,    55,    56,    57
  };

  const signed char
  parser::yycheck_[] =
  {
      15,    20,    29,    21,    23,    20,     3,    25,    26,    27,
      28,    26,    39,    40,    41,    28,    31,     6,     7,    22,
      35,    36,    37,    38,    42,     0,    19,    11,    12,    44,
      23,     4,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    46,    21,    28,     5,    19,    28,    25,
      29,    21,    21,    24,    22,    58,    35,    36,    37,    38,
      39,    40,    41,     8,     9,    23,    29,    19,    13,    15,
      19,    16,    17,    18,    12,    90,    19,    19,    10,    20,
      95,     9,    39,    28,    29,    88,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    29,    14,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    29,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     8,     9,    -1,    -1,
      -1,    13,    29,    -1,    16,    17,    18,    -1,    19,    -1,
      37,    38,    39,    40,    41,    -1,    28,    -1,    29,    31,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    24,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      29,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    29,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    29,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,    44,    28,     0,     6,     7,    45,    46,    47,
       4,    28,    45,     8,     9,    13,    16,    17,    18,    28,
      31,    48,    49,    19,    23,    19,    21,    25,    26,    27,
      28,    42,    50,    50,    21,    21,    21,    20,    23,    50,
       5,    48,    25,    50,    23,    50,    10,    29,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    14,    28,
      50,    50,    50,    50,    49,    24,    22,    50,    48,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      48,    22,    22,    22,    19,    24,    19,    24,    11,    12,
      30,    15,    19,    19,    19,    20,    48,    50,    50,    12,
      19
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    43,    44,    45,    45,    46,    46,    47,    47,    48,
      48,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     6,     0,     2,     1,     1,     3,     6,     1,
       2,     2,     4,     7,     5,     5,     5,     7,     5,     5,
       3,     1,     1,     1,     1,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     5
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "T_PROGRAM", "T_BEGIN",
  "T_END", "T_INTEGER", "T_BOOLEAN", "T_SKIP", "T_IF", "T_THEN", "T_ELSE",
  "T_ENDIF", "T_WHILE", "T_DO", "T_DONE", "T_READ", "T_WRITE", "T_ASSERT",
  "T_SEMICOLON", "T_ASSIGN", "T_OPEN", "T_CLOSE", "T_OPEN_BRACKET",
  "T_CLOSE_BRACKET", "T_NUM", "T_TRUE", "T_FALSE", "T_ID", "T_QMARK",
  "T_COLON", "T_MULTI", "T_OR", "T_AND", "T_EQ", "T_LESS", "T_GR", "T_ADD",
  "T_SUB", "T_MUL", "T_DIV", "T_MOD", "T_NOT", "$accept", "start",
  "declarations", "variable", "declaration", "statements", "statement",
  "expression", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    57,    57,    85,    88,    94,    99,   106,   116,   131,
     136,   143,   148,   169,   203,   219,   239,   254,   273,   291,
     309,   335,   340,   345,   350,   368,   390,   405,   419,   433,
     448,   464,   479,   494,   509,   523,   537,   548,   553
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
    };
    // Last valid token kind.
    const int code_max = 297;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1803 "while.tab.cc"

