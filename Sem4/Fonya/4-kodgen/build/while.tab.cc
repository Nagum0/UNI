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
      case symbol_kind::S_T_CHAR_LIT: // T_CHAR_LIT
      case symbol_kind::S_T_STRING_LIT: // T_STRING_LIT
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
      case symbol_kind::S_T_CHAR_LIT: // T_CHAR_LIT
      case symbol_kind::S_T_STRING_LIT: // T_STRING_LIT
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
      case symbol_kind::S_T_CHAR_LIT: // T_CHAR_LIT
      case symbol_kind::S_T_STRING_LIT: // T_STRING_LIT
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
      case symbol_kind::S_T_CHAR_LIT: // T_CHAR_LIT
      case symbol_kind::S_T_STRING_LIT: // T_STRING_LIT
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
      case symbol_kind::S_T_CHAR_LIT: // T_CHAR_LIT
      case symbol_kind::S_T_STRING_LIT: // T_STRING_LIT
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
      case symbol_kind::S_T_CHAR_LIT: // T_CHAR_LIT
      case symbol_kind::S_T_STRING_LIT: // T_STRING_LIT
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
      case symbol_kind::S_T_CHAR_LIT: // T_CHAR_LIT
      case symbol_kind::S_T_STRING_LIT: // T_STRING_LIT
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
#line 64 "while.y"
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
        std::cout << yystack_[1].value.as < std::string > () << std::endl;

        size_t used_stack_size = vars_size(vars);
        std::cout << "add esp, " << std::to_string(used_stack_size) << std::endl;

        std::cout << "mov eax, 0" << std::endl;
        std::cout << "ret" << std::endl;
    }
#line 770 "while.tab.cc"
    break;

  case 3: // declarations: %empty
#line 96 "while.y"
    {
    }
#line 777 "while.tab.cc"
    break;

  case 4: // declarations: declaration declarations
#line 100 "while.y"
    {
    }
#line 784 "while.tab.cc"
    break;

  case 5: // variable: T_INTEGER
#line 106 "while.y"
    {
        yylhs.value.as < type > () = integer;
    }
#line 792 "while.tab.cc"
    break;

  case 6: // variable: T_BOOLEAN
#line 111 "while.y"
    {
        yylhs.value.as < type > () = boolean;
    }
#line 800 "while.tab.cc"
    break;

  case 7: // variable: T_CHAR
#line 116 "while.y"
    {
        yylhs.value.as < type > () = ch;
    }
#line 808 "while.tab.cc"
    break;

  case 8: // declaration: variable T_ID T_SEMICOLON
#line 124 "while.y"
    {
		if( symbol_table.count(yystack_[1].value.as < std::string > ()) > 0 )
		{
			semantic_error(yystack_[2].location.begin.line, "Re-declared variable: " + yystack_[1].value.as < std::string > ());
		}
		symbol_table[yystack_[1].value.as < std::string > ()] = symbol_data(yystack_[2].value.as < type > ());
        symbol_table[yystack_[1].value.as < std::string > ()].is_array = false;
    }
#line 821 "while.tab.cc"
    break;

  case 9: // declaration: variable T_ID T_OPEN_BRACKET T_NUM T_CLOSE_BRACKET T_SEMICOLON
#line 135 "while.y"
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
#line 837 "while.tab.cc"
    break;

  case 10: // statements: statement
#line 150 "while.y"
    {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
    }
#line 845 "while.tab.cc"
    break;

  case 11: // statements: statement statements
#line 155 "while.y"
    {
        yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + yystack_[0].value.as < std::string > ();
    }
#line 853 "while.tab.cc"
    break;

  case 12: // statement: T_SKIP T_SEMICOLON
#line 162 "while.y"
    {
        yylhs.value.as < std::string > () = "nop";
    }
#line 861 "while.tab.cc"
    break;

  case 13: // statement: T_ID T_ASSIGN expression T_SEMICOLON
#line 167 "while.y"
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
        else if(yystack_[1].value.as < expression > ().typ == boolean || yystack_[1].value.as < expression > ().typ == ch)
            yylhs.value.as < std::string > () = "" +
                 yystack_[1].value.as < expression > ().code +
                 "mov [" + symbol_table[yystack_[3].value.as < std::string > ()].label + "], al\n";
    }
#line 885 "while.tab.cc"
    break;

  case 14: // statement: T_ID T_ASSIGN T_STRING_LIT T_SEMICOLON
#line 188 "while.y"
    {
        if (symbol_table.count(yystack_[3].value.as < std::string > ()) == 0)
		{
			semantic_error(yystack_[3].location.begin.line, "Undeclared variable: " + yystack_[3].value.as < std::string > ());
		}
        
        if (symbol_table[yystack_[3].value.as < std::string > ()].typ != ch || !symbol_table[yystack_[3].value.as < std::string > ()].is_array)
        {
            semantic_error(yystack_[3].location.begin.line, "Type error.");
        }


        std::string str = extract_str(yystack_[1].value.as < std::string > ());

        if (symbol_table[yystack_[3].value.as < std::string > ()].array_size < str.size()) 
        {
            semantic_error(yystack_[1].location.begin.line, "Array size and string literal sizes do not match: " + std::to_string(symbol_table[yystack_[3].value.as < std::string > ()].array_size) + ", " + std::to_string(str.size()));
        }

        yylhs.value.as < std::string > () = "";
        for (size_t i = 0; i < str.size(); ++i)
        {   
            char c = str[i];
            yylhs.value.as < std::string > () += "mov BYTE [" + symbol_table[yystack_[3].value.as < std::string > ()].label + " + " + std::to_string(i) + "], " + std::to_string(static_cast<int>(c)) + "\n";
        }
    }
#line 916 "while.tab.cc"
    break;

  case 15: // statement: T_ID T_OPEN_BRACKET expression T_CLOSE_BRACKET T_ASSIGN expression T_SEMICOLON
#line 216 "while.y"
    {
        if( symbol_table.count(yystack_[6].value.as < std::string > ()) == 0 )
		{
			semantic_error(yystack_[6].location.begin.line, "Undeclared variable: " + yystack_[6].value.as < std::string > ());
		}

        if(symbol_table[yystack_[6].value.as < std::string > ()].typ != yystack_[1].value.as < expression > ().typ)
		{
		   semantic_error(yystack_[6].location.begin.line, "Type error.");
		}

        if (yystack_[4].value.as < expression > ().typ != integer) 
        {
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
        else if (symbol_table[yystack_[6].value.as < std::string > ()].typ == boolean || symbol_table[yystack_[6].value.as < std::string > ()].typ == ch) 
        {
            yylhs.value.as < std::string > () = "" +
                yystack_[4].value.as < expression > ().code +
                "mov esi, eax\n" +
                yystack_[1].value.as < expression > ().code +
                "mov [" + symbol_table[yystack_[6].value.as < std::string > ()].label + " + esi * 1], al\n";
        }
    }
#line 954 "while.tab.cc"
    break;

  case 16: // statement: T_LET variable T_ID T_ASSIGN expression T_SEMICOLON
#line 251 "while.y"
    {
        if (symbol_table.count(yystack_[3].value.as < std::string > ()) != 0 || vars.count(yystack_[3].value.as < std::string > ()) != 0)
        {
            semantic_error(yystack_[3].location.begin.line, "Redeclaration of variable: " + yystack_[3].value.as < std::string > ());
        }

        if (yystack_[4].value.as < type > () != yystack_[1].value.as < expression > ().typ)
        {
            semantic_error(yystack_[4].location.begin.line, "Type error.");
        }
        
        size_t size = (yystack_[4].value.as < type > () == boolean || yystack_[4].value.as < type > () == ch) ? 1 : 4;
        std::string exp_result_reg = (yystack_[4].value.as < type > () == boolean || yystack_[4].value.as < type > () == ch) ? "al" : "eax";

        size_t stack_pos = vars_get_largest_offset(vars) + size;
        vars[yystack_[3].value.as < std::string > ()] = variable(yystack_[4].value.as < type > (), stack_pos);
        
        yylhs.value.as < std::string > () = "sub esp, " + std::to_string(stack_pos) + "\n" +
            yystack_[1].value.as < expression > ().code +
            "mov [ebp - " + std::to_string(stack_pos) + "], " + exp_result_reg + "\n";
    }
#line 980 "while.tab.cc"
    break;

  case 17: // statement: T_READ T_OPEN T_ID T_CLOSE T_SEMICOLON
#line 274 "while.y"
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
#line 999 "while.tab.cc"
    break;

  case 18: // statement: T_STDOUT T_OPEN T_ID T_COMMA expression T_CLOSE T_SEMICOLON
#line 290 "while.y"
    {
        if (symbol_table.count(yystack_[4].value.as < std::string > ()) == 0)
        {
			semantic_error(yystack_[4].location.begin.line, "Undeclared variable: " + yystack_[4].value.as < std::string > ());
        }

        if (symbol_table[yystack_[4].value.as < std::string > ()].typ != ch)
        {
			semantic_error(yystack_[4].location.begin.line, "Type error.");
        }

        if (yystack_[2].value.as < expression > ().typ != integer)
        {
			semantic_error(yystack_[2].location.begin.line, "Type error.");
        }
        
        yylhs.value.as < std::string > () = "" +
            yystack_[2].value.as < expression > ().code +
            "push eax\n" +
            "push " + symbol_table[yystack_[4].value.as < std::string > ()].label + "\n" +
            "call write_str\n" +
            "add esp, 8\n";
    }
#line 1027 "while.tab.cc"
    break;

  case 19: // statement: T_WRITE T_OPEN expression T_CLOSE T_SEMICOLON
#line 315 "while.y"
    {
        if(yystack_[2].value.as < expression > ().typ == integer)
        {
            yylhs.value.as < std::string > () = "" +
                 yystack_[2].value.as < expression > ().code +
                 "push eax\n" +
                 "call write_unsigned\n" +
                 "add esp,4\n";
        }
        else if(yystack_[2].value.as < expression > ().typ == boolean)
        {
            yylhs.value.as < std::string > () = "xor eax, eax\n" +
                 yystack_[2].value.as < expression > ().code +
                 "push eax\n" +
                 "call write_boolean\n" +
                 "add esp,4\n";
        }
        else if (yystack_[2].value.as < expression > ().typ == ch)
        {
            yylhs.value.as < std::string > () = "xor eax, eax\n" +
                 yystack_[2].value.as < expression > ().code +
                 "push eax\n" +
                 "call write_char\n" +
                 "add esp,4\n";
        }
    }
#line 1058 "while.tab.cc"
    break;

  case 20: // statement: T_IF expression T_THEN statements T_ENDIF
#line 343 "while.y"
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
#line 1076 "while.tab.cc"
    break;

  case 21: // statement: T_IF expression T_THEN statements T_ELSE statements T_ENDIF
#line 358 "while.y"
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
#line 1098 "while.tab.cc"
    break;

  case 22: // statement: T_WHILE expression T_DO statements T_DONE
#line 377 "while.y"
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
#line 1119 "while.tab.cc"
    break;

  case 23: // statement: T_ASSERT T_OPEN expression T_CLOSE T_SEMICOLON
#line 395 "while.y"
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
#line 1140 "while.tab.cc"
    break;

  case 24: // statement: T_MULTI expression statement
#line 413 "while.y"
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
#line 1167 "while.tab.cc"
    break;

  case 25: // expression: T_NUM
#line 439 "while.y"
    {
		yylhs.value.as < expression > () = expression(integer, "mov eax, " + yystack_[0].value.as < std::string > () + "\n");
    }
#line 1175 "while.tab.cc"
    break;

  case 26: // expression: T_TRUE
#line 444 "while.y"
    {
		yylhs.value.as < expression > () = expression(boolean, "mov al, 1\n");
    }
#line 1183 "while.tab.cc"
    break;

  case 27: // expression: T_FALSE
#line 449 "while.y"
    {
		yylhs.value.as < expression > () = expression(boolean, "mov al, 0\n");
    }
#line 1191 "while.tab.cc"
    break;

  case 28: // expression: T_CHAR_LIT
#line 454 "while.y"
    {
        char c = extract_char(yystack_[0].value.as < std::string > ());
        yylhs.value.as < expression > () = expression(ch, "mov al, " + std::to_string(c) + "\n");
    }
#line 1200 "while.tab.cc"
    break;

  case 29: // expression: T_ID
#line 460 "while.y"
    {
		if(symbol_table.count(yystack_[0].value.as < std::string > ()) == 0 && vars.count(yystack_[0].value.as < std::string > ()) == 0)
		{
			semantic_error(yystack_[0].location.begin.line, "Undeclared variable: " + yystack_[0].value.as < std::string > ());
		}
        
        bool local = vars.count(yystack_[0].value.as < std::string > ()) == 1;
        
        if (!local) 
        {
            if (symbol_table[yystack_[0].value.as < std::string > ()].typ == integer)
            {
                yylhs.value.as < expression > () = expression(symbol_table[yystack_[0].value.as < std::string > ()].typ,
                        "mov eax, [" + symbol_table[yystack_[0].value.as < std::string > ()].label + "]\n");
            }
            else if (symbol_table[yystack_[0].value.as < std::string > ()].typ == boolean || symbol_table[yystack_[0].value.as < std::string > ()].typ == ch)
            {
                yylhs.value.as < expression > () = expression(symbol_table[yystack_[0].value.as < std::string > ()].typ,
                        "mov al, [" + symbol_table[yystack_[0].value.as < std::string > ()].label + "]\n");
            }
        }
        else 
        {
            if (vars[yystack_[0].value.as < std::string > ()].typ == integer)
            {
                yylhs.value.as < expression > () = expression(vars[yystack_[0].value.as < std::string > ()].typ, "mov DWORD eax, [ebp - " + std::to_string(vars[yystack_[0].value.as < std::string > ()].stack_pos) + "]\n");
            }
            else if (vars[yystack_[0].value.as < std::string > ()].typ == boolean || vars[yystack_[0].value.as < std::string > ()].typ == ch)
            {
                yylhs.value.as < expression > () = expression(vars[yystack_[0].value.as < std::string > ()].typ, "mov BYTE al, [ebp - " + std::to_string(vars[yystack_[0].value.as < std::string > ()].stack_pos) + "]\n");
            }
        }
    }
#line 1238 "while.tab.cc"
    break;

  case 30: // expression: T_ID T_OPEN_BRACKET expression T_CLOSE_BRACKET
#line 495 "while.y"
    {
        if( symbol_table.count(yystack_[3].value.as < std::string > ()) == 0 )
		{
			semantic_error(yystack_[3].location.begin.line, "Undeclared variable: " + yystack_[3].value.as < std::string > ());
		}

        if (yystack_[1].value.as < expression > ().typ != integer)
        {
            semantic_error(yystack_[3].location.begin.line, "Array must be indexed by an integer.");
        }

        int offset = (symbol_table[yystack_[3].value.as < std::string > ()].typ == boolean || symbol_table[yystack_[3].value.as < std::string > ()].typ == ch) ? 1 : 4;

        yylhs.value.as < expression > () = expression(symbol_table[yystack_[3].value.as < std::string > ()].typ,
                        "" +
                        yystack_[1].value.as < expression > ().code +
                        "mov esi, eax\n" +
                        "mov eax, [" + symbol_table[yystack_[3].value.as < std::string > ()].label + " + esi * " + std::to_string(offset) + "]\n"
        );
    }
#line 1263 "while.tab.cc"
    break;

  case 31: // expression: expression T_ADD expression
#line 517 "while.y"
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
#line 1281 "while.tab.cc"
    break;

  case 32: // expression: expression T_SUB expression
#line 532 "while.y"
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
#line 1298 "while.tab.cc"
    break;

  case 33: // expression: expression T_MUL expression
#line 546 "while.y"
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
#line 1315 "while.tab.cc"
    break;

  case 34: // expression: expression T_DIV expression
#line 560 "while.y"
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
#line 1333 "while.tab.cc"
    break;

  case 35: // expression: expression T_MOD expression
#line 575 "while.y"
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
#line 1352 "while.tab.cc"
    break;

  case 36: // expression: expression T_LESS expression
#line 591 "while.y"
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
#line 1370 "while.tab.cc"
    break;

  case 37: // expression: expression T_GR expression
#line 606 "while.y"
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
#line 1388 "while.tab.cc"
    break;

  case 38: // expression: expression T_EQ expression
#line 621 "while.y"
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
#line 1406 "while.tab.cc"
    break;

  case 39: // expression: expression T_AND expression
#line 636 "while.y"
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
#line 1423 "while.tab.cc"
    break;

  case 40: // expression: expression T_OR expression
#line 650 "while.y"
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
#line 1440 "while.tab.cc"
    break;

  case 41: // expression: T_NOT expression
#line 664 "while.y"
    {
		if(yystack_[0].value.as < expression > ().typ != boolean)
		{
		   semantic_error(yystack_[1].location.begin.line, "Type error.");
		}
		yylhs.value.as < expression > () = expression(boolean, "" +
                yystack_[0].value.as < expression > ().code +
                "xor al, 1\n");
    }
#line 1454 "while.tab.cc"
    break;

  case 42: // expression: T_OPEN expression T_CLOSE
#line 675 "while.y"
    {
		yylhs.value.as < expression > () = expression(yystack_[1].value.as < expression > ().typ, "" + yystack_[1].value.as < expression > ().code);
    }
#line 1462 "while.tab.cc"
    break;

  case 43: // expression: expression T_QMARK expression T_COLON expression
#line 680 "while.y"
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
#line 1488 "while.tab.cc"
    break;


#line 1492 "while.tab.cc"

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









  const signed char parser::yypact_ninf_ = -22;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
       1,   -21,    10,    65,   -22,   -22,   -22,   -22,    16,    -8,
      65,    -2,   -20,   -22,     3,   200,   200,     6,     7,     9,
      13,   -11,   200,    65,    28,    -2,   -22,    22,   -22,   200,
     -22,   -22,   -22,    33,   -22,   200,    77,    94,    23,   200,
      29,   200,    27,   200,    60,    55,   -22,   -22,    26,   211,
     200,    56,    -2,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,    -2,    70,   235,    53,   259,    74,
     121,   305,   -22,    88,    90,   -22,   327,   -10,   344,   378,
     378,   385,    20,    20,    37,    37,    56,    56,    56,    96,
      92,    93,   200,   105,   -22,   -22,   106,   200,   -22,   -22,
      -2,   -22,   200,   -22,   -22,   -22,   283,   -22,   200,   148,
     114,   361,   108,   175,   -22,   -22,   -22,   -22
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     3,     1,     5,     6,     7,     0,     0,
       3,     0,     0,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     8,     0,    12,     0,
      25,    26,    27,    29,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,    11,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,     0,     0,    42,     0,     0,     0,    40,
      39,    38,    36,    37,    31,    32,    33,    34,    35,     0,
       0,     0,     0,     0,    14,    13,     0,     0,     9,    30,
       0,    20,     0,    22,    17,    19,     0,    23,     0,     0,
       0,    43,     0,     0,    16,    21,    18,    15
  };

  const signed char
  parser::yypgoto_[] =
  {
     -22,   -22,   120,   122,   -22,    -4,    87,   -16
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     2,     8,     9,    10,    24,    25,    36
  };

  const signed char
  parser::yytable_[] =
  {
      37,    26,   100,   101,     1,    27,    44,    14,    15,     3,
       4,    42,    16,    49,    43,    17,    18,    19,    20,    51,
      11,    47,    12,    66,    28,    68,    70,    71,    21,    38,
      39,    22,    40,    46,    76,    23,    41,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    77,    48,
      29,    53,    74,    65,    30,    31,    32,    33,    50,    67,
      89,    34,    69,    59,    60,    61,    62,    63,    53,    14,
      15,     5,     6,     7,    16,    35,   106,    17,    18,    19,
      20,   109,    61,    62,    63,    73,   111,    53,    52,    92,
      21,    53,   113,    22,    90,    94,   110,    23,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    53,    64,
      97,    98,   103,   104,   105,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    53,   107,   115,   108,   116,
      13,    72,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    95,     0,     0,    45,     0,     0,     0,     0,
       0,     0,    53,     0,     0,     0,     0,     0,     0,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
       0,     0,     0,     0,     0,     0,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,     0,     0,     0,
       0,     0,     0,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    29,     0,     0,     0,    30,    31,    32,
      33,     0,     0,     0,    34,    75,     0,     0,     0,     0,
       0,     0,    53,     0,     0,     0,     0,     0,    35,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    91,
       0,     0,     0,     0,     0,     0,    53,     0,     0,     0,
       0,     0,     0,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    93,     0,     0,     0,     0,     0,     0,
      53,     0,     0,     0,     0,     0,     0,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,   112,     0,     0,
       0,     0,     0,     0,    53,     0,     0,     0,     0,     0,
       0,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    96,     0,     0,     0,     0,    53,     0,     0,     0,
       0,     0,     0,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    99,     0,     0,     0,     0,    53,     0,
       0,     0,     0,     0,     0,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    53,   102,     0,     0,     0,
       0,     0,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    53,     0,     0,     0,     0,     0,     0,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    53,
       0,     0,     0,     0,     0,     0,    53,     0,    56,    57,
      58,    59,    60,    61,    62,    63,    57,    58,    59,    60,
      61,    62,    63
  };

  const signed char
  parser::yycheck_[] =
  {
      16,    21,    12,    13,     3,    25,    22,     9,    10,    30,
       0,    22,    14,    29,    25,    17,    18,    19,    20,    35,
       4,    25,    30,    39,    21,    41,    42,    43,    30,    23,
      23,    33,    23,     5,    50,    37,    23,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    52,    27,
      23,    31,    26,    30,    27,    28,    29,    30,    25,    30,
      64,    34,    35,    43,    44,    45,    46,    47,    31,     9,
      10,     6,     7,     8,    14,    48,    92,    17,    18,    19,
      20,    97,    45,    46,    47,    30,   102,    31,    11,    36,
      30,    31,   108,    33,    24,    21,   100,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    31,    15,
      22,    21,    16,    21,    21,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    31,    21,    13,    22,    21,
      10,    44,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    21,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    23,    -1,    -1,    -1,    27,    28,    29,
      30,    -1,    -1,    -1,    34,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    48,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    26,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    31,    32,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    41,    42,    43,    44,
      45,    46,    47
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,    50,    30,     0,     6,     7,     8,    51,    52,
      53,     4,    30,    51,     9,    10,    14,    17,    18,    19,
      20,    30,    33,    37,    54,    55,    21,    25,    21,    23,
      27,    28,    29,    30,    34,    48,    56,    56,    23,    23,
      23,    23,    22,    25,    56,    52,     5,    54,    27,    56,
      25,    56,    11,    31,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    15,    30,    56,    30,    56,    35,
      56,    56,    55,    30,    26,    24,    56,    54,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    54,
      24,    24,    36,    24,    21,    21,    26,    22,    21,    26,
      12,    13,    32,    16,    21,    21,    56,    21,    22,    56,
      54,    56,    24,    56,    21,    13,    21,    21
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    49,    50,    51,    51,    52,    52,    52,    53,    53,
      54,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     6,     0,     2,     1,     1,     1,     3,     6,
       1,     2,     2,     4,     4,     7,     6,     5,     7,     5,
       5,     7,     5,     5,     3,     1,     1,     1,     1,     1,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     5
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "T_PROGRAM", "T_BEGIN",
  "T_END", "T_INTEGER", "T_BOOLEAN", "T_CHAR", "T_SKIP", "T_IF", "T_THEN",
  "T_ELSE", "T_ENDIF", "T_WHILE", "T_DO", "T_DONE", "T_READ", "T_WRITE",
  "T_STDOUT", "T_ASSERT", "T_SEMICOLON", "T_ASSIGN", "T_OPEN", "T_CLOSE",
  "T_OPEN_BRACKET", "T_CLOSE_BRACKET", "T_NUM", "T_TRUE", "T_FALSE",
  "T_ID", "T_QMARK", "T_COLON", "T_MULTI", "T_CHAR_LIT", "T_STRING_LIT",
  "T_COMMA", "T_LET", "T_OR", "T_AND", "T_EQ", "T_LESS", "T_GR", "T_ADD",
  "T_SUB", "T_MUL", "T_DIV", "T_MOD", "T_NOT", "$accept", "start",
  "declarations", "variable", "declaration", "statements", "statement",
  "expression", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    63,    63,    96,    99,   105,   110,   115,   123,   134,
     149,   154,   161,   166,   187,   215,   250,   273,   289,   314,
     342,   357,   376,   394,   412,   438,   443,   448,   453,   459,
     494,   516,   531,   545,   559,   574,   590,   605,   620,   635,
     649,   663,   674,   679
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
    };
    // Last valid token kind.
    const int code_max = 303;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1982 "while.tab.cc"

