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
		if (symbol_table.count(yystack_[3].value.as < std::string > ()) == 0 && vars.count(yystack_[3].value.as < std::string > ()) == 0)
			semantic_error(yystack_[3].location.begin.line, "Undeclared variable: " + yystack_[3].value.as < std::string > ());
        
        bool local = vars.count(yystack_[3].value.as < std::string > ()) == 1;
        
        if (!local) 
        {
		    if (symbol_table[yystack_[3].value.as < std::string > ()].typ != yystack_[1].value.as < expression > ().typ)
		        semantic_error(yystack_[3].location.begin.line, "Type error.");

            if (yystack_[1].value.as < expression > ().typ == integer)
                yylhs.value.as < std::string > () = "" +
                     yystack_[1].value.as < expression > ().code +
                     "mov [" + symbol_table[yystack_[3].value.as < std::string > ()].label + "], eax\n";
            else if (yystack_[1].value.as < expression > ().typ == boolean || yystack_[1].value.as < expression > ().typ == ch)
                yylhs.value.as < std::string > () = "" +
                     yystack_[1].value.as < expression > ().code +
                     "mov [" + symbol_table[yystack_[3].value.as < std::string > ()].label + "], al\n";
        }
        else
        {
            if (vars[yystack_[3].value.as < std::string > ()].typ != yystack_[1].value.as < expression > ().typ)
		        semantic_error(yystack_[3].location.begin.line, "Type error.");
           
            std::string result_reg = (vars[yystack_[3].value.as < std::string > ()].typ == integer) ? "eax" : "al";
            std::string value_size = (vars[yystack_[3].value.as < std::string > ()].typ == integer) ? "DWORD" : "BYTE";

            yylhs.value.as < std::string > () = yystack_[1].value.as < expression > ().code + 
                "mov " + value_size + "[ebp - " + std::to_string(vars[yystack_[3].value.as < std::string > ()].stack_pos) + "], " + result_reg + "\n";
        }
    }
#line 898 "while.tab.cc"
    break;

  case 14: // statement: T_ID T_ASSIGN T_STRING_LIT T_SEMICOLON
#line 201 "while.y"
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
#line 929 "while.tab.cc"
    break;

  case 15: // statement: T_ID T_OPEN_BRACKET expression T_CLOSE_BRACKET T_ASSIGN expression T_SEMICOLON
#line 229 "while.y"
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
#line 967 "while.tab.cc"
    break;

  case 16: // statement: T_LET variable T_ID T_SEMICOLON
#line 264 "while.y"
    {
        if (symbol_table.count(yystack_[1].value.as < std::string > ()) != 0 || vars.count(yystack_[1].value.as < std::string > ()) != 0)
            semantic_error(yystack_[1].location.begin.line, "Redeclaration of variable: " + yystack_[1].value.as < std::string > ());

        size_t size = (yystack_[2].value.as < type > () == boolean || yystack_[2].value.as < type > () == ch) ? 1 : 4;
        size_t stack_pos = vars_get_largest_offset(vars) + size;

        vars[yystack_[1].value.as < std::string > ()] = variable(yystack_[2].value.as < type > (), size, stack_pos);

        yylhs.value.as < std::string > () = "sub esp, " + std::to_string(size) + "\n";
    }
#line 983 "while.tab.cc"
    break;

  case 17: // statement: T_LET variable T_ID T_ASSIGN expression T_SEMICOLON
#line 277 "while.y"
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

        vars[yystack_[3].value.as < std::string > ()] = variable(yystack_[4].value.as < type > (), size, stack_pos);
        
        yylhs.value.as < std::string > () = "sub esp, " + std::to_string(size) + "\n" +
            yystack_[1].value.as < expression > ().code +
            "mov [ebp - " + std::to_string(stack_pos) + "], " + exp_result_reg + "\n";
    }
#line 1009 "while.tab.cc"
    break;

  case 18: // statement: T_READ T_OPEN T_ID T_CLOSE T_SEMICOLON
#line 300 "while.y"
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
#line 1028 "while.tab.cc"
    break;

  case 19: // statement: T_STDOUT T_OPEN T_ID T_COMMA expression T_CLOSE T_SEMICOLON
#line 316 "while.y"
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
#line 1056 "while.tab.cc"
    break;

  case 20: // statement: T_WRITE T_OPEN expression T_CLOSE T_SEMICOLON
#line 341 "while.y"
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
#line 1087 "while.tab.cc"
    break;

  case 21: // statement: T_IF expression T_THEN statements T_ENDIF
#line 369 "while.y"
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
#line 1105 "while.tab.cc"
    break;

  case 22: // statement: T_IF expression T_THEN statements T_ELSE statements T_ENDIF
#line 384 "while.y"
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
#line 1127 "while.tab.cc"
    break;

  case 23: // statement: T_WHILE expression T_DO statements T_DONE
#line 403 "while.y"
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
#line 1148 "while.tab.cc"
    break;

  case 24: // statement: T_ASSERT T_OPEN expression T_CLOSE T_SEMICOLON
#line 421 "while.y"
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
#line 1169 "while.tab.cc"
    break;

  case 25: // statement: T_MULTI expression statement
#line 439 "while.y"
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
#line 1196 "while.tab.cc"
    break;

  case 26: // expression: T_NUM
#line 465 "while.y"
    {
		yylhs.value.as < expression > () = expression(integer, "mov eax, " + yystack_[0].value.as < std::string > () + "\n");
    }
#line 1204 "while.tab.cc"
    break;

  case 27: // expression: T_TRUE
#line 470 "while.y"
    {
		yylhs.value.as < expression > () = expression(boolean, "mov al, 1\n");
    }
#line 1212 "while.tab.cc"
    break;

  case 28: // expression: T_FALSE
#line 475 "while.y"
    {
		yylhs.value.as < expression > () = expression(boolean, "mov al, 0\n");
    }
#line 1220 "while.tab.cc"
    break;

  case 29: // expression: T_CHAR_LIT
#line 480 "while.y"
    {
        char c = extract_char(yystack_[0].value.as < std::string > ());
        yylhs.value.as < expression > () = expression(ch, "mov al, " + std::to_string(c) + "\n");
    }
#line 1229 "while.tab.cc"
    break;

  case 30: // expression: T_ID
#line 486 "while.y"
    {
		if(symbol_table.count(yystack_[0].value.as < std::string > ()) == 0 && vars.count(yystack_[0].value.as < std::string > ()) == 0)
			semantic_error(yystack_[0].location.begin.line, "Undeclared variable: " + yystack_[0].value.as < std::string > ());
        
        bool local = vars.count(yystack_[0].value.as < std::string > ()) == 1;
        type typ = local ? vars[yystack_[0].value.as < std::string > ()].typ : symbol_table[yystack_[0].value.as < std::string > ()].typ;
        std::string dest_reg = (typ == boolean || typ == ch) ? "al" : "eax";
        
        if (!local) 
            yylhs.value.as < expression > () = expression(typ, "mov " + dest_reg + ", [" + symbol_table[yystack_[0].value.as < std::string > ()].label + "]\n");
        else 
            yylhs.value.as < expression > () = expression(typ, "mov " + dest_reg + ", [ebp - " + std::to_string(vars[yystack_[0].value.as < std::string > ()].stack_pos) + "]\n");
    }
#line 1247 "while.tab.cc"
    break;

  case 31: // expression: T_ID T_OPEN_BRACKET expression T_CLOSE_BRACKET
#line 501 "while.y"
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
#line 1272 "while.tab.cc"
    break;

  case 32: // expression: expression T_ADD expression
#line 523 "while.y"
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
#line 1290 "while.tab.cc"
    break;

  case 33: // expression: expression T_SUB expression
#line 538 "while.y"
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
#line 1307 "while.tab.cc"
    break;

  case 34: // expression: expression T_MUL expression
#line 552 "while.y"
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
#line 1324 "while.tab.cc"
    break;

  case 35: // expression: expression T_DIV expression
#line 566 "while.y"
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
#line 1342 "while.tab.cc"
    break;

  case 36: // expression: expression T_MOD expression
#line 581 "while.y"
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
#line 1361 "while.tab.cc"
    break;

  case 37: // expression: expression T_LESS expression
#line 597 "while.y"
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
#line 1379 "while.tab.cc"
    break;

  case 38: // expression: expression T_GR expression
#line 612 "while.y"
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
#line 1397 "while.tab.cc"
    break;

  case 39: // expression: expression T_EQ expression
#line 627 "while.y"
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
#line 1415 "while.tab.cc"
    break;

  case 40: // expression: expression T_AND expression
#line 642 "while.y"
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
#line 1432 "while.tab.cc"
    break;

  case 41: // expression: expression T_OR expression
#line 656 "while.y"
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
#line 1449 "while.tab.cc"
    break;

  case 42: // expression: T_NOT expression
#line 670 "while.y"
    {
		if(yystack_[0].value.as < expression > ().typ != boolean)
		{
		   semantic_error(yystack_[1].location.begin.line, "Type error.");
		}
		yylhs.value.as < expression > () = expression(boolean, "" +
                yystack_[0].value.as < expression > ().code +
                "xor al, 1\n");
    }
#line 1463 "while.tab.cc"
    break;

  case 43: // expression: T_OPEN expression T_CLOSE
#line 681 "while.y"
    {
		yylhs.value.as < expression > () = expression(yystack_[1].value.as < expression > ().typ, "" + yystack_[1].value.as < expression > ().code);
    }
#line 1471 "while.tab.cc"
    break;

  case 44: // expression: expression T_QMARK expression T_COLON expression
#line 686 "while.y"
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
#line 1497 "while.tab.cc"
    break;


#line 1501 "while.tab.cc"

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









  const signed char parser::yypact_ninf_ = -21;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
       1,   -10,    22,    43,   -21,   -21,   -21,   -21,    20,    -1,
      43,    -2,   -20,   -21,     9,    38,    38,    10,    13,    30,
      31,   -11,    38,    43,    27,    -2,   -21,    28,   -21,    38,
     -21,   -21,   -21,    37,   -21,    38,    78,    95,    39,    38,
      44,    38,    29,    38,    61,    53,   -21,   -21,    47,   200,
      38,    54,    -2,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    -2,    60,   224,    52,   248,    69,
     122,   294,   -21,   -19,    74,   -21,   316,    -3,   333,   367,
     367,   374,    84,    84,   101,   101,    54,    54,    54,    80,
      90,    91,    38,    92,   -21,   -21,   123,   -21,    38,   -21,
     -21,    -2,   -21,    38,   -21,   -21,   -21,   272,   -21,    38,
     149,   131,   350,    93,   176,   -21,   -21,   -21,   -21
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     3,     1,     5,     6,     7,     0,     0,
       3,     0,     0,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     8,     0,    12,     0,
      26,    27,    28,    30,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,    11,     0,     0,
       0,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,     0,     0,    43,     0,     0,     0,    41,
      40,    39,    37,    38,    32,    33,    34,    35,    36,     0,
       0,     0,     0,     0,    14,    13,     0,    16,     0,     9,
      31,     0,    21,     0,    23,    18,    20,     0,    24,     0,
       0,     0,    44,     0,     0,    17,    22,    19,    15
  };

  const short
  parser::yypgoto_[] =
  {
     -21,   -21,   139,   127,   -21,    -4,   107,   -16
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     2,     8,     9,    10,    24,    25,    36
  };

  const signed char
  parser::yytable_[] =
  {
      37,    26,    97,    98,     1,    27,    44,    14,    15,   101,
     102,    42,    16,    49,    43,    17,    18,    19,    20,    51,
       3,    47,     4,    66,    11,    68,    70,    71,    21,    12,
      28,    22,    46,    38,    76,    23,    39,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    77,     5,
       6,     7,    29,    40,    41,    48,    30,    31,    32,    33,
      89,    29,    50,    34,    69,    30,    31,    32,    33,    65,
      14,    15,    34,    74,    67,    16,   107,    35,    17,    18,
      19,    20,   110,    73,    90,    53,    35,   112,    92,    52,
      94,    21,    53,   114,    22,    99,   104,   111,    23,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    53,
      64,   105,   106,   108,   117,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    53,    59,    60,    61,
      62,    63,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    95,   116,   109,    61,    62,    63,    13,
      45,    72,     0,    53,     0,     0,     0,     0,     0,     0,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
     115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,     0,     0,     0,     0,     0,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,   118,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,     0,     0,
       0,     0,     0,     0,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    75,     0,     0,     0,     0,     0,
       0,    53,     0,     0,     0,     0,     0,     0,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    91,     0,
       0,     0,     0,     0,     0,    53,     0,     0,     0,     0,
       0,     0,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    93,     0,     0,     0,     0,     0,     0,    53,
       0,     0,     0,     0,     0,     0,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,   113,     0,     0,     0,
       0,     0,     0,    53,     0,     0,     0,     0,     0,     0,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      96,     0,     0,     0,     0,    53,     0,     0,     0,     0,
       0,     0,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,   100,     0,     0,     0,     0,    53,     0,     0,
       0,     0,     0,     0,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    53,   103,     0,     0,     0,     0,
       0,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    53,     0,     0,     0,     0,     0,     0,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    53,     0,
       0,     0,     0,     0,     0,    53,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    57,    58,    59,    60,    61,
      62,    63
  };

  const signed char
  parser::yycheck_[] =
  {
      16,    21,    21,    22,     3,    25,    22,     9,    10,    12,
      13,    22,    14,    29,    25,    17,    18,    19,    20,    35,
      30,    25,     0,    39,     4,    41,    42,    43,    30,    30,
      21,    33,     5,    23,    50,    37,    23,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    52,     6,
       7,     8,    23,    23,    23,    27,    27,    28,    29,    30,
      64,    23,    25,    34,    35,    27,    28,    29,    30,    30,
       9,    10,    34,    26,    30,    14,    92,    48,    17,    18,
      19,    20,    98,    30,    24,    31,    48,   103,    36,    11,
      21,    30,    31,   109,    33,    21,    16,   101,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    31,
      15,    21,    21,    21,    21,    31,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    31,    43,    44,    45,
      46,    47,    31,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    21,    13,    22,    45,    46,    47,    10,
      23,    44,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      26,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    31,    32,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    41,    42,    43,    44,    45,
      46,    47
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
      24,    24,    36,    24,    21,    21,    26,    21,    22,    21,
      26,    12,    13,    32,    16,    21,    21,    56,    21,    22,
      56,    54,    56,    24,    56,    21,    13,    21,    21
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    49,    50,    51,    51,    52,    52,    52,    53,    53,
      54,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     6,     0,     2,     1,     1,     1,     3,     6,
       1,     2,     2,     4,     4,     7,     4,     6,     5,     7,
       5,     5,     7,     5,     5,     3,     1,     1,     1,     1,
       1,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     5
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
     149,   154,   161,   166,   200,   228,   263,   276,   299,   315,
     340,   368,   383,   402,   420,   438,   464,   469,   474,   479,
     485,   500,   522,   537,   551,   565,   580,   596,   611,   626,
     641,   655,   669,   680,   685
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
#line 1989 "while.tab.cc"

