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
#line 57 "while.y"
    {
        std::cout << "global main" << std::endl;
        std::cout << "extern read_unsigned, write_unsigned" << std::endl;
        std::cout << "extern read_boolean, write_boolean" << std::endl;
        std::cout << "segment .bss" << std::endl;
        std::map<std::string,symbol_data>::iterator it; 
        for(it = symbol_table.begin(); it != symbol_table.end(); ++it) {
            std::string label = it->second.label;
            std::cout
                << it->second.label << ": "
                << (it->second.typ == boolean ? "resb " : "resd ")
                << 1 << std::endl;
        } 
        std::cout << std::endl;
        std::cout << "segment .text" << std::endl;
        std::cout << "main:" << std::endl;
        std::cout << yystack_[1].value.as < std::string > () << std::endl;
        std::cout << "mov eax, 0" << std::endl;
        std::cout << "ret" << std::endl;
    }
#line 720 "while.tab.cc"
    break;

  case 3: // declarations: %empty
#line 81 "while.y"
    {
    }
#line 727 "while.tab.cc"
    break;

  case 4: // declarations: declaration declarations
#line 85 "while.y"
    {
    }
#line 734 "while.tab.cc"
    break;

  case 5: // declaration: T_INTEGER T_ID T_SEMICOLON
#line 91 "while.y"
    {
		if( symbol_table.count(yystack_[1].value.as < std::string > ()) > 0 )
		{
			semantic_error(yystack_[2].location.begin.line, "Re-declared variable: " + yystack_[1].value.as < std::string > ());
		}
		symbol_table[yystack_[1].value.as < std::string > ()] = symbol_data(integer);
    }
#line 746 "while.tab.cc"
    break;

  case 6: // declaration: T_BOOLEAN T_ID T_SEMICOLON
#line 100 "while.y"
    {
		if( symbol_table.count(yystack_[1].value.as < std::string > ()) > 0 )
		{
			semantic_error(yystack_[2].location.begin.line, "Re-declared variable: " + yystack_[1].value.as < std::string > ());
		}
		symbol_table[yystack_[1].value.as < std::string > ()] = symbol_data(boolean);
    }
#line 758 "while.tab.cc"
    break;

  case 7: // statements: statement
#line 111 "while.y"
    {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
    }
#line 766 "while.tab.cc"
    break;

  case 8: // statements: statement statements
#line 116 "while.y"
    {
        yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + yystack_[0].value.as < std::string > ();
    }
#line 774 "while.tab.cc"
    break;

  case 9: // statement: T_SKIP T_SEMICOLON
#line 123 "while.y"
    {
        yylhs.value.as < std::string > () = "nop";
    }
#line 782 "while.tab.cc"
    break;

  case 10: // statement: T_ID T_ASSIGN expression T_SEMICOLON
#line 128 "while.y"
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
#line 805 "while.tab.cc"
    break;

  case 11: // statement: T_READ T_OPEN T_ID T_CLOSE T_SEMICOLON
#line 148 "while.y"
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
#line 824 "while.tab.cc"
    break;

  case 12: // statement: T_WRITE T_OPEN expression T_CLOSE T_SEMICOLON
#line 164 "while.y"
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
#line 847 "while.tab.cc"
    break;

  case 13: // statement: T_IF expression T_THEN statements T_ENDIF
#line 184 "while.y"
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
#line 865 "while.tab.cc"
    break;

  case 14: // statement: T_IF expression T_THEN statements T_ELSE statements T_ENDIF
#line 199 "while.y"
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
#line 887 "while.tab.cc"
    break;

  case 15: // statement: T_WHILE expression T_DO statements T_DONE
#line 218 "while.y"
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
#line 908 "while.tab.cc"
    break;

  case 16: // statement: T_ASSERT expression T_SEMICOLON
#line 236 "while.y"
    {
        if (yystack_[1].value.as < expression > ().typ != boolean)
            semantic_error(yystack_[1].location.begin.line, "Type error.");
        
        std::string end_label = next_label();

        yylhs.value.as < std::string > () = yystack_[1].value.as < expression > ().code +
             "cmp al, 1\n" +
             "je " + end_label + "\n" +
             "mov eax, 1\n" +
             "ret\n" +
             end_label + ":\n";
    }
#line 926 "while.tab.cc"
    break;

  case 17: // statement: T_MULTI expression statement
#line 251 "while.y"
    {
        if (yystack_[1].value.as < expression > ().typ != integer)
            semantic_error(yystack_[1].location.begin.line, "Type error.");
    
        std::string loop_label = next_label();
        std::string end_label = next_label();

        yylhs.value.as < std::string > () = yystack_[1].value.as < expression > ().code +
             loop_label + ":\n" +
             "cmp eax, 0\n" +
             "je " + end_label + "\n" +
             "dec eax\n" +
             "push eax\n" +
             yystack_[0].value.as < std::string > () +
             "pop eax\n" +
             "jmp " + loop_label + "\n" +
             end_label + ":\n";
    }
#line 949 "while.tab.cc"
    break;

  case 18: // expression: T_NUM
#line 273 "while.y"
    {
		yylhs.value.as < expression > () = expression(integer, "mov eax, " + yystack_[0].value.as < std::string > () + "\n");
    }
#line 957 "while.tab.cc"
    break;

  case 19: // expression: T_TRUE
#line 278 "while.y"
    {
		yylhs.value.as < expression > () = expression(boolean, "mov al, 1\n");
    }
#line 965 "while.tab.cc"
    break;

  case 20: // expression: T_FALSE
#line 283 "while.y"
    {
		yylhs.value.as < expression > () = expression(boolean, "mov al, 0\n");
    }
#line 973 "while.tab.cc"
    break;

  case 21: // expression: T_ID
#line 288 "while.y"
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
#line 994 "while.tab.cc"
    break;

  case 22: // expression: expression T_ADD expression
#line 306 "while.y"
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
#line 1012 "while.tab.cc"
    break;

  case 23: // expression: expression T_SUB expression
#line 321 "while.y"
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
#line 1029 "while.tab.cc"
    break;

  case 24: // expression: expression T_MUL expression
#line 335 "while.y"
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
#line 1046 "while.tab.cc"
    break;

  case 25: // expression: expression T_DIV expression
#line 349 "while.y"
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
#line 1064 "while.tab.cc"
    break;

  case 26: // expression: expression T_MOD expression
#line 364 "while.y"
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
#line 1083 "while.tab.cc"
    break;

  case 27: // expression: expression T_LESS expression
#line 380 "while.y"
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
#line 1101 "while.tab.cc"
    break;

  case 28: // expression: expression T_GR expression
#line 395 "while.y"
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
#line 1119 "while.tab.cc"
    break;

  case 29: // expression: expression T_EQ expression
#line 410 "while.y"
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
#line 1138 "while.tab.cc"
    break;

  case 30: // expression: expression T_AND expression
#line 426 "while.y"
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
#line 1155 "while.tab.cc"
    break;

  case 31: // expression: expression T_OR expression
#line 440 "while.y"
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
#line 1172 "while.tab.cc"
    break;

  case 32: // expression: T_NOT expression
#line 454 "while.y"
    {
		if(yystack_[0].value.as < expression > ().typ != boolean)
		{
		   semantic_error(yystack_[1].location.begin.line, "Type error.");
		}
		yylhs.value.as < expression > () = expression(boolean, "" +
                yystack_[0].value.as < expression > ().code +
                "xor al, 1\n");
    }
#line 1186 "while.tab.cc"
    break;

  case 33: // expression: T_OPEN expression T_CLOSE
#line 465 "while.y"
    {
		yylhs.value.as < expression > () = expression(yystack_[1].value.as < expression > ().typ, "" + yystack_[1].value.as < expression > ().code);
    }
#line 1194 "while.tab.cc"
    break;

  case 34: // expression: expression T_QMARK expression T_COLON expression
#line 470 "while.y"
    {
        if (yystack_[2].value.as < expression > ().typ != boolean)
            semantic_error(yystack_[2].location.begin.line, "Type error.");

        if (yystack_[4].value.as < expression > ().typ != yystack_[0].value.as < expression > ().typ)
            semantic_error(yystack_[4].location.begin.line, "Type error.");
        
        std::string false_label = next_label();
        std::string end_label = next_label();

        yylhs.value.as < expression > () = expression(yystack_[4].value.as < expression > ().typ,
            yystack_[2].value.as < expression > ().code +
            "cmp al, 1\n" +
            "jne " + false_label + "\n" +
            yystack_[4].value.as < expression > ().code +
            "jmp " + end_label + "\n" +
            false_label + ":\n" +
            yystack_[0].value.as < expression > ().code +
            end_label + ":\n"
        );
    }
#line 1220 "while.tab.cc"
    break;

  case 35: // expression: expression T_SHIFT expression
#line 493 "while.y"
    {
        if (yystack_[2].value.as < expression > ().typ != integer || yystack_[0].value.as < expression > ().typ != integer)
            semantic_error(yystack_[2].location.begin.line, "Type error.");

        yylhs.value.as < expression > () = expression(integer,
            yystack_[0].value.as < expression > ().code +
            "push eax\n" +
            yystack_[2].value.as < expression > ().code +
            "pop ebx\n" +
            "mov cl, bl\n" +
            "sar eax, cl\n"
        );
    }
#line 1238 "while.tab.cc"
    break;

  case 36: // expression: expression T_POWER expression
#line 508 "while.y"
    {
        if (yystack_[2].value.as < expression > ().typ != integer || yystack_[0].value.as < expression > ().typ != integer)
            semantic_error(yystack_[2].location.begin.line, "Type error.");
        
        std::string loop_label = next_label();
        std::string end_label = next_label();

        yylhs.value.as < expression > () = expression(integer, 
            yystack_[0].value.as < expression > ().code +
            "push eax\n" +
            yystack_[2].value.as < expression > ().code +
            "pop ebx\n" +
            "mov ecx, eax\n" +
            loop_label + ":\n" +
            "cmp ebx, 1\n" +
            "je " + end_label + "\n" +
            "dec ebx\n" +
            "mul ecx\n" +
            "jmp " + loop_label + "\n" +
            end_label + ":\n"
        );
    }
#line 1265 "while.tab.cc"
    break;


#line 1269 "while.tab.cc"

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









  const signed char parser::yypact_ninf_ = -26;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      -1,   -14,     8,     0,   -26,    -8,    -5,    18,     0,    25,
      26,    33,   -26,   -26,   -26,    27,   170,   170,     6,    28,
      32,   170,   170,    42,    33,   -26,   170,   -26,   -26,   -26,
     -26,   170,    84,   100,    30,   170,   170,   124,    52,   -26,
     -26,   181,   -25,    33,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,    33,    31,   202,
     148,   -26,   -26,   -26,     4,   218,   234,   -25,   250,   250,
     266,   271,   271,   -16,   -16,   -25,   -25,   -25,    38,    39,
      41,   -26,    33,   -26,   170,   -26,   -26,   -26,    44,   234,
     -26
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     3,     1,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     9,     0,    18,    19,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       8,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    17,    33,     0,     0,    35,    36,    31,    30,
      29,    27,    28,    22,    23,    24,    25,    26,     0,     0,
       0,    10,     0,    13,     0,    15,    11,    12,     0,    34,
      14
  };

  const signed char
  parser::yypgoto_[] =
  {
     -26,   -26,    54,   -26,    -3,    34,   -17
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     2,     7,     8,    23,    24,    32
  };

  const signed char
  parser::yytable_[] =
  {
      33,    44,     1,    45,    37,    38,     5,     6,     4,    41,
      44,     3,    45,    46,    42,    82,    83,     9,    59,    60,
      10,    40,    11,    54,    55,    56,    34,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      64,    15,    16,    13,    14,    25,    17,    39,    35,    18,
      19,    36,    79,    85,    78,    58,    90,    86,    20,    87,
      15,    16,    12,    21,    22,    17,     0,    89,    18,    19,
       0,     0,    62,     0,     0,     0,     0,    20,    44,    88,
      45,    46,    21,    22,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,     0,    45,    46,    57,     0,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    44,     0,    45,    46,
       0,     0,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    61,     0,     0,     0,     0,     0,     0,     0,
      44,     0,    45,    46,     0,     0,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    81,     0,     0,     0,
       0,     0,     0,     0,    44,     0,    45,    46,     0,     0,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      26,     0,    27,    28,    29,    30,     0,     0,     0,     0,
       0,     0,    63,     0,     0,     0,     0,    44,     0,    45,
      46,     0,    31,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    80,     0,     0,     0,     0,    44,     0,
      45,    46,     0,     0,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    44,    84,    45,    46,     0,     0,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      44,     0,    45,    46,     0,     0,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    44,     0,    45,    46,
       0,     0,     0,     0,    49,    50,    51,    52,    53,    54,
      55,    56,    44,     0,    45,    46,     0,    44,     0,    45,
      46,    50,    51,    52,    53,    54,    55,    56,    52,    53,
      54,    55,    56
  };

  const signed char
  parser::yycheck_[] =
  {
      17,    26,     3,    28,    21,    22,     6,     7,     0,    26,
      26,    25,    28,    29,    31,    11,    12,    25,    35,    36,
      25,    24,     4,    39,    40,    41,    20,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      43,     8,     9,    18,    18,    18,    13,     5,    20,    16,
      17,    19,    21,    15,    57,    25,    12,    18,    25,    18,
       8,     9,     8,    30,    31,    13,    -1,    84,    16,    17,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    25,    26,    82,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    28,    29,    14,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    26,    -1,    28,    29,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    28,    29,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    28,    29,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      20,    -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    26,    -1,    28,
      29,    -1,    42,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    21,    -1,    -1,    -1,    -1,    26,    -1,
      28,    29,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    26,    27,    28,    29,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      26,    -1,    28,    29,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    26,    -1,    28,    29,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    26,    -1,    28,    29,    -1,    26,    -1,    28,
      29,    35,    36,    37,    38,    39,    40,    41,    37,    38,
      39,    40,    41
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,    44,    25,     0,     6,     7,    45,    46,    25,
      25,     4,    45,    18,    18,     8,     9,    13,    16,    17,
      25,    30,    31,    47,    48,    18,    20,    22,    23,    24,
      25,    42,    49,    49,    20,    20,    19,    49,    49,     5,
      47,    49,    49,    10,    26,    28,    29,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    14,    25,    49,
      49,    18,    48,    21,    47,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    47,    21,
      21,    18,    11,    12,    27,    15,    18,    18,    47,    49,
      12
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    43,    44,    45,    45,    46,    46,    47,    47,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     6,     0,     2,     3,     3,     1,     2,     2,
       4,     5,     5,     5,     7,     5,     3,     3,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     5,     3,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "T_PROGRAM", "T_BEGIN",
  "T_END", "T_INTEGER", "T_BOOLEAN", "T_SKIP", "T_IF", "T_THEN", "T_ELSE",
  "T_ENDIF", "T_WHILE", "T_DO", "T_DONE", "T_READ", "T_WRITE",
  "T_SEMICOLON", "T_ASSIGN", "T_OPEN", "T_CLOSE", "T_NUM", "T_TRUE",
  "T_FALSE", "T_ID", "T_QMARK", "T_COLON", "T_SHIFT", "T_POWER",
  "T_ASSERT", "T_MULTI", "T_OR", "T_AND", "T_EQ", "T_LESS", "T_GR",
  "T_ADD", "T_SUB", "T_MUL", "T_DIV", "T_MOD", "T_NOT", "$accept", "start",
  "declarations", "declaration", "statements", "statement", "expression", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    56,    56,    81,    84,    90,    99,   110,   115,   122,
     127,   147,   163,   183,   198,   217,   235,   250,   272,   277,
     282,   287,   305,   320,   334,   348,   363,   379,   394,   409,
     425,   439,   453,   464,   469,   492,   507
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
#line 1723 "while.tab.cc"

