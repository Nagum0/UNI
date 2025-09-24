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

      case symbol_kind::S_T_TIME: // T_TIME
      case symbol_kind::S_T_ID: // T_ID
      case symbol_kind::S_T_NUM: // T_NUM
      case symbol_kind::S_T_REAL_LITERAL: // T_REAL_LITERAL
      case symbol_kind::S_commands: // commands
      case symbol_kind::S_command: // command
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

      case symbol_kind::S_T_TIME: // T_TIME
      case symbol_kind::S_T_ID: // T_ID
      case symbol_kind::S_T_NUM: // T_NUM
      case symbol_kind::S_T_REAL_LITERAL: // T_REAL_LITERAL
      case symbol_kind::S_commands: // commands
      case symbol_kind::S_command: // command
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

      case symbol_kind::S_T_TIME: // T_TIME
      case symbol_kind::S_T_ID: // T_ID
      case symbol_kind::S_T_NUM: // T_NUM
      case symbol_kind::S_T_REAL_LITERAL: // T_REAL_LITERAL
      case symbol_kind::S_commands: // commands
      case symbol_kind::S_command: // command
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

      case symbol_kind::S_T_TIME: // T_TIME
      case symbol_kind::S_T_ID: // T_ID
      case symbol_kind::S_T_NUM: // T_NUM
      case symbol_kind::S_T_REAL_LITERAL: // T_REAL_LITERAL
      case symbol_kind::S_commands: // commands
      case symbol_kind::S_command: // command
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

      case symbol_kind::S_T_TIME: // T_TIME
      case symbol_kind::S_T_ID: // T_ID
      case symbol_kind::S_T_NUM: // T_NUM
      case symbol_kind::S_T_REAL_LITERAL: // T_REAL_LITERAL
      case symbol_kind::S_commands: // commands
      case symbol_kind::S_command: // command
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

      case symbol_kind::S_T_TIME: // T_TIME
      case symbol_kind::S_T_ID: // T_ID
      case symbol_kind::S_T_NUM: // T_NUM
      case symbol_kind::S_T_REAL_LITERAL: // T_REAL_LITERAL
      case symbol_kind::S_commands: // commands
      case symbol_kind::S_command: // command
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

      case symbol_kind::S_T_TIME: // T_TIME
      case symbol_kind::S_T_ID: // T_ID
      case symbol_kind::S_T_NUM: // T_NUM
      case symbol_kind::S_T_REAL_LITERAL: // T_REAL_LITERAL
      case symbol_kind::S_commands: // commands
      case symbol_kind::S_command: // command
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
  case 2: // start: T_PROGRAM T_ID declarations T_BEGIN commands T_END
#line 58 "while.y"
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
                << (it->second.typ == boolean || it->second.typ == natural ? 1 : 2)
                << std::endl;
        }
        std::cout << std::endl;
        std::cout << "section .text" << std::endl;
        std::cout << "main:" << std::endl;
        std::cout << yystack_[1].value.as < std::string > ();
        std::cout << "xor eax,eax" << std::endl;
        std::cout << "ret" << std::endl;
    }
#line 738 "while.tab.cc"
    break;

  case 5: // declaration: T_BOOLEAN T_ID
#line 92 "while.y"
    {
        if(symbol_table.find(yystack_[0].value.as < std::string > ()) != symbol_table.end()) {
            semantic_error(yystack_[1].location.begin.line, "Re-declared variable: '" + yystack_[0].value.as < std::string > () + "'.");
        }
        symbol_table[yystack_[0].value.as < std::string > ()] = boolean;
    }
#line 749 "while.tab.cc"
    break;

  case 6: // declaration: T_NATURAL T_ID
#line 100 "while.y"
    {
        if(symbol_table.find(yystack_[0].value.as < std::string > ()) != symbol_table.end()) {
            semantic_error(yystack_[1].location.begin.line, "Re-declared variable: '" + yystack_[0].value.as < std::string > () + "'.");
        }
        symbol_table[yystack_[0].value.as < std::string > ()] = natural;
    }
#line 760 "while.tab.cc"
    break;

  case 7: // declaration: T_TIME T_ID
#line 108 "while.y"
    {
        if(symbol_table.find(yystack_[0].value.as < std::string > ()) != symbol_table.end()) {
            semantic_error(yystack_[1].location.begin.line, "Re-declared variable: '" + yystack_[0].value.as < std::string > () + "'.");
        }
	symbol_table[yystack_[0].value.as < std::string > ()] = t_time;
    }
#line 771 "while.tab.cc"
    break;

  case 8: // declaration: T_REAL T_ID
#line 116 "while.y"
    {
        if(symbol_table.find(yystack_[0].value.as < std::string > ()) != symbol_table.end()) {
            semantic_error(yystack_[1].location.begin.line, "Re-declared variable: '" + yystack_[0].value.as < std::string > () + "'.");
        }
        symbol_table[yystack_[0].value.as < std::string > ()] = t_real;
    }
#line 782 "while.tab.cc"
    break;

  case 9: // commands: %empty
#line 126 "while.y"
    {
        yylhs.value.as < std::string > () = "";
    }
#line 790 "while.tab.cc"
    break;

  case 10: // commands: commands command
#line 131 "while.y"
    {
        yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + yystack_[0].value.as < std::string > ();
    }
#line 798 "while.tab.cc"
    break;

  case 11: // command: T_READ T_OPEN T_ID T_CLOSE
#line 138 "while.y"
    {
        if(symbol_table.find(yystack_[1].value.as < std::string > ()) == symbol_table.end()) {
            semantic_error(yystack_[1].location.begin.line, "Undeclared variable: '" + yystack_[1].value.as < std::string > () + "'.");
        }
        std::stringstream ss;
        type typ = symbol_table[yystack_[1].value.as < std::string > ()].typ;
        ss << "call " << (typ == boolean ? "read_boolean" : "read_natural") << std::endl;
        ss << "mov [" << symbol_table[yystack_[1].value.as < std::string > ()].label << "], " << (typ == boolean ? "al" : "eax") << std::endl;
        yylhs.value.as < std::string > () = ss.str();
    }
#line 813 "while.tab.cc"
    break;

  case 12: // command: T_WRITE T_OPEN expression T_CLOSE
#line 150 "while.y"
    {
        std::stringstream ss;
        ss << yystack_[1].value.as < expression > ().code;
        if(yystack_[1].value.as < expression > ().typ == boolean) {
            ss << "and eax,1" << std::endl;
        }
        ss << "push eax" << std::endl;
        ss << "call " << (yystack_[1].value.as < expression > ().typ == boolean ? "write_boolean" : "write_natural") << std::endl;
        ss << "add esp,4" << std::endl;
        yylhs.value.as < std::string > () = ss.str();
    }
#line 829 "while.tab.cc"
    break;

  case 13: // command: T_ID T_ASSIGN expression
#line 163 "while.y"
    {
        if(symbol_table.find(yystack_[2].value.as < std::string > ()) == symbol_table.end()) {
            semantic_error(yystack_[2].location.begin.line, "Undeclared variable: '" + yystack_[2].value.as < std::string > () + "'.");
        }
        if(symbol_table[yystack_[2].value.as < std::string > ()].typ != yystack_[0].value.as < expression > ().typ) {
            semantic_error(yystack_[2].location.begin.line, "Type error in assignment.");
        }

        std::stringstream ss;

        if (symbol_table[yystack_[2].value.as < std::string > ()].typ == t_real)
        {
            ss << yystack_[0].value.as < expression > ().code
               << "mov [" << symbol_table[yystack_[2].value.as < std::string > ()].label << "], eax\n" 
               << "mov [" << symbol_table[yystack_[2].value.as < std::string > ()].label << " + 1 * 4], ebx\n";
        }
        else {
            ss << yystack_[0].value.as < expression > ().code;
            ss << "mov [" << symbol_table[yystack_[2].value.as < std::string > ()].label << "], "
               << (yystack_[0].value.as < expression > ().typ == boolean ? "al" : "eax") << std::endl; 
        }

        yylhs.value.as < std::string > () = ss.str();
    }
#line 858 "while.tab.cc"
    break;

  case 14: // command: T_IF expression T_THEN commands T_ENDIF
#line 189 "while.y"
    {
        if(yystack_[3].value.as < expression > ().typ != boolean) {
            semantic_error(yystack_[3].location.begin.line, "Condition must be boolean.");
        }
        std::stringstream ss;
        std::string end_label = next_label();
        ss << yystack_[3].value.as < expression > ().code
           << "cmp al,1\n"
           << "jne near " << end_label << std::endl
           << yystack_[1].value.as < std::string > ()
           << end_label << ":\n";
        yylhs.value.as < std::string > () = ss.str();
    }
#line 876 "while.tab.cc"
    break;

  case 15: // command: T_IF expression T_THEN commands T_ELSE commands T_ENDIF
#line 204 "while.y"
    {
        if(yystack_[5].value.as < expression > ().typ != boolean) {
            semantic_error(yystack_[5].location.begin.line, "Condition must be boolean.");
        }
        std::stringstream ss;
        std::string else_label = next_label();
        std::string end_label = next_label();
        ss << yystack_[5].value.as < expression > ().code
           << "cmp al,1\n"
           << "jne near " << else_label << std::endl
           << yystack_[3].value.as < std::string > ()
           << "jmp " << end_label << std::endl
           << else_label << ":\n"
           << yystack_[1].value.as < std::string > ()
           << end_label << ":\n";
        yylhs.value.as < std::string > () = ss.str();
    }
#line 898 "while.tab.cc"
    break;

  case 16: // command: T_WHILE expression T_DO commands T_DONE
#line 223 "while.y"
    {
        if(yystack_[3].value.as < expression > ().typ != boolean) {
            semantic_error(yystack_[3].location.begin.line, "Condition must be boolean.");
        }
        std::stringstream ss;
        std::string start_label = next_label();
        std::string end_label = next_label();
        ss << start_label << ":\n"
           << yystack_[3].value.as < expression > ().code
           << "cmp al,1\n"
           << "jne near " << end_label << std::endl
           << yystack_[1].value.as < std::string > ()
           << "jmp " << start_label << std::endl
           << end_label << ":\n";
        yylhs.value.as < std::string > () = ss.str();
    }
#line 919 "while.tab.cc"
    break;

  case 17: // expression: T_NUM
#line 243 "while.y"
    {
        std::stringstream ss;
        ss << "mov eax," << yystack_[0].value.as < std::string > () << std::endl;
        yylhs.value.as < expression > () = expression(natural, ss.str());
    }
#line 929 "while.tab.cc"
    break;

  case 18: // expression: T_TRUE
#line 250 "while.y"
    {
        std::stringstream ss;
        ss << "mov al,1" << std::endl;
        yylhs.value.as < expression > () =  expression(boolean, ss.str());
    }
#line 939 "while.tab.cc"
    break;

  case 19: // expression: T_FALSE
#line 257 "while.y"
    {
        std::stringstream ss;
        ss << "mov al,0" << std::endl;
        yylhs.value.as < expression > () =  expression(boolean, ss.str());
    }
#line 949 "while.tab.cc"
    break;

  case 20: // expression: T_TIME
#line 264 "while.y"
    {
        std::stringstream ss;
        ss << "mov al,1" << std::endl;
        yylhs.value.as < expression > () =  expression(t_time, ss.str());
    }
#line 959 "while.tab.cc"
    break;

  case 21: // expression: T_REAL_LITERAL
#line 271 "while.y"
    {
        std::stringstream ss;
        size_t comma_pos = yystack_[0].value.as < std::string > ().find(",");
        std::string int_part = yystack_[0].value.as < std::string > ().substr(0, comma_pos);
        std::string frac_part = yystack_[0].value.as < std::string > ().substr(comma_pos + 1);
        ss << "mov eax, " << int_part << "\nmov ebx, " << frac_part << "\n";
        yylhs.value.as < expression > () = expression(t_real, ss.str());
    }
#line 972 "while.tab.cc"
    break;

  case 22: // expression: T_INT T_OPEN T_ID T_CLOSE
#line 281 "while.y"
    {
        if(symbol_table.find(yystack_[1].value.as < std::string > ()) == symbol_table.end()) {
	        semantic_error(yystack_[1].location.begin.line, "Undeclared variable: '" + yystack_[1].value.as < std::string > () + "'.");
        }

        if (symbol_table[yystack_[1].value.as < std::string > ()].typ != t_real) {
        	semantic_error(yystack_[1].location.begin.line, "Type error.");
        }
        
        std::stringstream ss;
        ss << "mov eax, [" << symbol_table[yystack_[1].value.as < std::string > ()].label << "]\n";
        yylhs.value.as < expression > () = expression(natural, ss.str());

    }
#line 991 "while.tab.cc"
    break;

  case 23: // expression: T_FRAC T_OPEN T_ID T_CLOSE
#line 297 "while.y"
    {
        if(symbol_table.find(yystack_[1].value.as < std::string > ()) == symbol_table.end()) {
	        semantic_error(yystack_[1].location.begin.line, "Undeclared variable: '" + yystack_[1].value.as < std::string > () + "'.");
        }

        if (symbol_table[yystack_[1].value.as < std::string > ()].typ != t_real) {
        	semantic_error(yystack_[1].location.begin.line, "Type error.");
        }
        
        std::stringstream ss;
        ss << "mov eax, [" << symbol_table[yystack_[1].value.as < std::string > ()].label << " + 1 * 4]\n";
        yylhs.value.as < expression > () = expression(natural, ss.str());

    }
#line 1010 "while.tab.cc"
    break;

  case 24: // expression: T_MINUTE "(" T_ID ")"
#line 313 "while.y"
    {
        if(symbol_table.find(yystack_[1].value.as < std::string > ()) == symbol_table.end()) {
	        semantic_error(yystack_[1].location.begin.line, "Undeclared variable: '" + yystack_[1].value.as < std::string > () + "'.");
        }
	if(symbol_table[yystack_[1].value.as < std::string > ()].typ != t_time) {
		semantic_error(yystack_[1].location.begin.line, "Must be t_time:" + yystack_[1].value.as < std::string > () + "'.");
	}
        std::stringstream ss;
        ss << "mov al,1" << std::endl;
        yylhs.value.as < expression > () =  expression(natural, ss.str());
    }
#line 1026 "while.tab.cc"
    break;

  case 25: // expression: T_HOUR "(" T_ID ")"
#line 326 "while.y"
    {
        if(symbol_table.find(yystack_[1].value.as < std::string > ()) == symbol_table.end()) {
            semantic_error(yystack_[1].location.begin.line, "Undeclared variable: '" + yystack_[1].value.as < std::string > () + "'.");
        }
	if(symbol_table[yystack_[1].value.as < std::string > ()].typ != t_time) {
		semantic_error(yystack_[1].location.begin.line, "Must be t_time:" + yystack_[1].value.as < std::string > () + "'.");
	}
        std::stringstream ss;
        ss << "mov al,1" << std::endl;
        yylhs.value.as < expression > () =  expression(natural, ss.str());
    }
#line 1042 "while.tab.cc"
    break;

  case 26: // expression: T_ID
#line 339 "while.y"
    {
        if(symbol_table.find(yystack_[0].value.as < std::string > ()) == symbol_table.end()) {
            semantic_error(yystack_[0].location.begin.line, "Undeclared variable: '" + yystack_[0].value.as < std::string > () + "'.");
        }

        std::stringstream ss;
        type typ = symbol_table[yystack_[0].value.as < std::string > ()].typ;
        
        if (typ == t_real) {
            ss << "mov eax, [" << symbol_table[yystack_[0].value.as < std::string > ()].label << "]\n"
               << "mov ebx, [" << symbol_table[yystack_[0].value.as < std::string > ()].label << " + 1 * 4]\n";
        }
        else {
            ss << "mov " << (typ == boolean ? "al" : "eax") << ",[" << symbol_table[yystack_[0].value.as < std::string > ()].label << "]\n";
        }

        yylhs.value.as < expression > () =  expression(typ, ss.str());
    }
#line 1065 "while.tab.cc"
    break;

  case 27: // expression: expression T_ADD expression
#line 359 "while.y"
    {
        if (yystack_[2].value.as < expression > ().typ != yystack_[0].value.as < expression > ().typ && (yystack_[2].value.as < expression > ().typ != natural || yystack_[2].value.as < expression > ().typ != t_real)) {
            semantic_error(yystack_[2].location.begin.line, "Type error in left argument of '+'.");
        }
        
        std::stringstream ss;

        if (yystack_[2].value.as < expression > ().typ == t_real) {
            ss << yystack_[0].value.as < expression > ().code
               << "push eax\n push ebx\n"
               << yystack_[2].value.as < expression > ().code
               << "pop edx\n pop ecx\n"
               << "add eax, ecx\n"
               << "add ebx, edx\n";
        }
        else {
            ss << yystack_[2].value.as < expression > ().code;
            ss << "push eax" << std::endl;
            ss << yystack_[0].value.as < expression > ().code;
            ss << "mov ecx,eax" << std::endl;
            ss << "pop eax" << std::endl;
            ss << "add eax,ecx" << std::endl;
        }

        yylhs.value.as < expression > () =  expression(yystack_[2].value.as < expression > ().typ, ss.str());
    }
#line 1096 "while.tab.cc"
    break;

  case 28: // expression: expression T_SUB expression
#line 387 "while.y"
    {
        if(yystack_[2].value.as < expression > ().typ != natural) {
            semantic_error(yystack_[2].location.begin.line, "Type error in left argument of '-'.");
        }
        if(yystack_[0].value.as < expression > ().typ != natural) {
            semantic_error(yystack_[0].location.begin.line, "Type error in right argument of '-'.");
        }
        std::stringstream ss;
        ss << yystack_[2].value.as < expression > ().code;
        ss << "push eax" << std::endl;
        ss << yystack_[0].value.as < expression > ().code;
        ss << "mov ecx,eax" << std::endl;
        ss << "pop eax" << std::endl;
        ss << "sub eax,ecx" << std::endl;
        yylhs.value.as < expression > () =  expression(natural, ss.str());
    }
#line 1117 "while.tab.cc"
    break;

  case 29: // expression: expression T_MUL expression
#line 405 "while.y"
    {
        if(yystack_[2].value.as < expression > ().typ != natural) {
            semantic_error(yystack_[2].location.begin.line, "Type error in left argument of '*'.");
        }
        if(yystack_[0].value.as < expression > ().typ != natural) {
            semantic_error(yystack_[0].location.begin.line, "Type error in right argument of '*'.");
        }
        std::stringstream ss;
        ss << yystack_[2].value.as < expression > ().code;
        ss << "push eax" << std::endl;
        ss << yystack_[0].value.as < expression > ().code;
        ss << "mov ecx,eax" << std::endl;
        ss << "pop eax" << std::endl;
        ss << "xor edx,edx" << std::endl;
        ss << "mul ecx" << std::endl;
        yylhs.value.as < expression > () =  expression(natural, ss.str());
    }
#line 1139 "while.tab.cc"
    break;

  case 30: // expression: expression T_DIV expression
#line 424 "while.y"
    {
        if(yystack_[2].value.as < expression > ().typ != natural) {
            semantic_error(yystack_[2].location.begin.line, "Type error in left argument of '/'.");
        }
        if(yystack_[0].value.as < expression > ().typ != natural) {
            semantic_error(yystack_[0].location.begin.line, "Type error in right argument of '/'.");
        }
        std::stringstream ss;
        ss << yystack_[2].value.as < expression > ().code;
        ss << "push eax" << std::endl;
        ss << yystack_[0].value.as < expression > ().code;
        ss << "mov ecx,eax" << std::endl;
        ss << "pop eax" << std::endl;
        ss << "xor edx,edx" << std::endl;
        ss << "div ecx" << std::endl;
        yylhs.value.as < expression > () =  expression(natural, ss.str());
    }
#line 1161 "while.tab.cc"
    break;

  case 31: // expression: expression T_MOD expression
#line 443 "while.y"
    {
        if(yystack_[2].value.as < expression > ().typ != natural) {
            semantic_error(yystack_[2].location.begin.line, "Type error in left argument of '%'.");
        }
        if(yystack_[0].value.as < expression > ().typ != natural) {
            semantic_error(yystack_[0].location.begin.line, "Type error in right argument of '%'.");
        }
        std::stringstream ss;
        ss << yystack_[2].value.as < expression > ().code;
        ss << "push eax" << std::endl;
        ss << yystack_[0].value.as < expression > ().code;
        ss << "mov ecx,eax" << std::endl;
        ss << "pop eax" << std::endl;
        ss << "xor edx,edx" << std::endl;
        ss << "div ecx" << std::endl;
        ss << "mov eax,edx" << std::endl;
        yylhs.value.as < expression > () =  expression(natural, ss.str());
    }
#line 1184 "while.tab.cc"
    break;

  case 32: // expression: expression T_LESS expression
#line 463 "while.y"
    {
        if(yystack_[2].value.as < expression > ().typ != natural) {
            semantic_error(yystack_[2].location.begin.line, "Type error in left argument of '<'.");
        }
        if(yystack_[0].value.as < expression > ().typ != natural) {
            semantic_error(yystack_[0].location.begin.line, "Type error in right argument of '<'.");
        }
        std::stringstream ss;
        ss << yystack_[2].value.as < expression > ().code;
        ss << "push eax" << std::endl;
        ss << yystack_[0].value.as < expression > ().code;
        ss << "mov ecx,eax" << std::endl;
        ss << "pop eax" << std::endl;
        ss << "cmp eax,ecx" << std::endl;
        ss << "mov al,0" << std::endl;
        ss << "mov cx,1" << std::endl;
        ss << "cmovb ax,cx" << std::endl;
        yylhs.value.as < expression > () =  expression(boolean, ss.str());
    }
#line 1208 "while.tab.cc"
    break;

  case 33: // expression: expression T_GREATER expression
#line 484 "while.y"
    {
        if(yystack_[2].value.as < expression > ().typ != natural) {
            semantic_error(yystack_[2].location.begin.line, "Type error in left argument of '>'.");
        }
        if(yystack_[0].value.as < expression > ().typ != natural) {
            semantic_error(yystack_[0].location.begin.line, "Type error in right argument of '>'.");
        }
        std::stringstream ss;
        ss << yystack_[2].value.as < expression > ().code;
        ss << "push eax" << std::endl;
        ss << yystack_[0].value.as < expression > ().code;
        ss << "mov ecx,eax" << std::endl;
        ss << "pop eax" << std::endl;
        ss << "cmp eax,ecx" << std::endl;
        ss << "mov al,0" << std::endl;
        ss << "mov cx,1" << std::endl;
        ss << "cmova ax,cx" << std::endl;
        yylhs.value.as < expression > () =  expression(boolean, ss.str());
    }
#line 1232 "while.tab.cc"
    break;

  case 34: // expression: expression T_LESSEQ expression
#line 505 "while.y"
    {
        if(yystack_[2].value.as < expression > ().typ != natural) {
            semantic_error(yystack_[2].location.begin.line, "Type error in left argument of '<='.");
        }
        if(yystack_[0].value.as < expression > ().typ != natural) {
            semantic_error(yystack_[0].location.begin.line, "Type error in right argument of '<='.");
        }
        std::stringstream ss;
        ss << yystack_[2].value.as < expression > ().code;
        ss << "push eax" << std::endl;
        ss << yystack_[0].value.as < expression > ().code;
        ss << "mov ecx,eax" << std::endl;
        ss << "pop eax" << std::endl;
        ss << "cmp eax,ecx" << std::endl;
        ss << "mov al,0" << std::endl;
        ss << "mov cx,1" << std::endl;
        ss << "cmovbe ax,cx" << std::endl;
        yylhs.value.as < expression > () =  expression(boolean, ss.str());
    }
#line 1256 "while.tab.cc"
    break;

  case 35: // expression: expression T_GREATEREQ expression
#line 526 "while.y"
    {
        if(yystack_[2].value.as < expression > ().typ != natural) {
            semantic_error(yystack_[2].location.begin.line, "Type error in left argument of '>='.");
        }
        if(yystack_[0].value.as < expression > ().typ != natural) {
            semantic_error(yystack_[0].location.begin.line, "Type error in right argument of '>='.");
        }
        std::stringstream ss;
        ss << yystack_[2].value.as < expression > ().code;
        ss << "push eax" << std::endl;
        ss << yystack_[0].value.as < expression > ().code;
        ss << "mov ecx,eax" << std::endl;
        ss << "pop eax" << std::endl;
        ss << "cmp eax,ecx" << std::endl;
        ss << "mov al,0" << std::endl;
        ss << "mov cx,1" << std::endl;
        ss << "cmovae ax,cx" << std::endl;
        yylhs.value.as < expression > () =  expression(boolean, ss.str());
    }
#line 1280 "while.tab.cc"
    break;

  case 36: // expression: expression T_AND expression
#line 547 "while.y"
    {
        if(yystack_[2].value.as < expression > ().typ != boolean) {
            semantic_error(yystack_[2].location.begin.line, "Type error in left argument of 'and'.");
        }
        if(yystack_[0].value.as < expression > ().typ != boolean) {
            semantic_error(yystack_[0].location.begin.line, "Type error in right argument of 'and'.");
        }
        std::stringstream ss;
        ss << yystack_[2].value.as < expression > ().code;
        ss << "push ax" << std::endl;
        ss << yystack_[0].value.as < expression > ().code;
        ss << "mov cx,ax" << std::endl;
        ss << "pop ax" << std::endl;
        ss << "cmp al,1" << std::endl;
        ss << "cmove ax,cx" << std::endl;
        yylhs.value.as < expression > () =  expression(boolean, ss.str());
    }
#line 1302 "while.tab.cc"
    break;

  case 37: // expression: expression T_OR expression
#line 566 "while.y"
    {
        if(yystack_[2].value.as < expression > ().typ != boolean) {
            semantic_error(yystack_[2].location.begin.line, "Type error in left argument of 'or'.");
        }
        if(yystack_[0].value.as < expression > ().typ != boolean) {
            semantic_error(yystack_[0].location.begin.line, "Type error in right argument of 'or'.");
        }
        std::stringstream ss;
        ss << yystack_[2].value.as < expression > ().code;
        ss << "push ax" << std::endl;
        ss << yystack_[0].value.as < expression > ().code;
        ss << "mov cx,ax" << std::endl;
        ss << "pop ax" << std::endl;
        ss << "cmp al,0" << std::endl;
        ss << "cmove ax,cx" << std::endl;
        yylhs.value.as < expression > () =  expression(boolean, ss.str());
    }
#line 1324 "while.tab.cc"
    break;

  case 38: // expression: expression T_EQ expression
#line 585 "while.y"
    {
        if(yystack_[2].value.as < expression > ().typ != yystack_[0].value.as < expression > ().typ) {
            semantic_error(yystack_[2].location.begin.line, "Type error in arguments of '='.");
        }
        std::stringstream ss;
        if(yystack_[2].value.as < expression > ().typ == boolean) {
            ss << yystack_[2].value.as < expression > ().code;
            ss << "push ax" << std::endl;
            ss << yystack_[0].value.as < expression > ().code;
            ss << "mov cx,ax" << std::endl;
            ss << "pop ax" << std::endl;
            ss << "cmp ax,cx" << std::endl;
            ss << "mov al,0" << std::endl;
            ss << "mov cx,1" << std::endl;
            ss << "cmove ax,cx" << std::endl;
        } else {
            ss << yystack_[2].value.as < expression > ().code;
            ss << "push eax" << std::endl;
            ss << yystack_[0].value.as < expression > ().code;
            ss << "mov ecx,eax" << std::endl;
            ss << "pop eax" << std::endl;
            ss << "cmp eax,ecx" << std::endl;
            ss << "mov al,0" << std::endl;
            ss << "mov cx,1" << std::endl;
            ss << "cmove ax,cx" << std::endl;
        }
        yylhs.value.as < expression > () =  expression(boolean, ss.str());
    }
#line 1357 "while.tab.cc"
    break;

  case 39: // expression: T_NOT expression
#line 615 "while.y"
    {
        if(yystack_[0].value.as < expression > ().typ != boolean) {
            semantic_error(yystack_[1].location.begin.line, "Type error in argument of 'not'.");
        }
        std::stringstream ss;
        ss << yystack_[0].value.as < expression > ().code;
        ss << "xor al,1" << std::endl;
        yylhs.value.as < expression > () =  expression(boolean, ss.str());
    }
#line 1371 "while.tab.cc"
    break;

  case 40: // expression: T_OPEN expression T_CLOSE
#line 626 "while.y"
    {
        yylhs.value.as < expression > () = yystack_[1].value.as < expression > ();
    }
#line 1379 "while.tab.cc"
    break;


#line 1383 "while.tab.cc"

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









  const signed char parser::yypact_ninf_ = -49;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
       6,   -23,    10,   -49,   -49,    -1,   -49,   -10,    -7,    -5,
       2,   -49,     3,   -49,   -49,   -49,   -49,   -49,    47,    48,
      65,    65,    50,   -49,    59,    65,   -49,   -49,    65,   -49,
      42,    52,   -49,   -49,   -49,    72,    77,    65,    11,    39,
      65,    84,    78,   100,    73,    81,    82,   121,   -49,   -49,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,   -49,    24,   -49,   -49,   -49,   108,   109,   134,
     136,   135,   149,   137,    88,    62,    62,    62,    62,   -17,
     -17,   -49,   -49,   -49,   142,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   155,   -49
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     3,     1,     0,     9,     0,     0,     0,
       0,     4,     0,     5,     6,     7,     8,     2,     0,     0,
       0,     0,     0,    10,     0,     0,    18,    19,     0,    20,
       0,     0,    26,    17,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    39,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,    13,    11,    12,    40,     0,     0,     0,
       0,     0,    37,    36,    38,    32,    33,    34,    35,    27,
      28,    29,    30,    31,     0,    25,    24,    22,    23,     9,
      14,    16,     0,    15
  };

  const signed char
  parser::yypgoto_[] =
  {
     -49,   -49,   -49,   -49,   -48,   -49,   -21
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     2,     5,    11,    12,    23,    38
  };

  const signed char
  parser::yytable_[] =
  {
      39,    71,     3,     6,    42,     7,     8,    43,    17,     1,
       4,    18,    19,    20,    84,    13,    48,    21,    14,    63,
      15,     9,    49,    59,    60,    61,    10,    16,    22,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    92,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    24,    25,    40,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    26,    27,    41,    28,    44,    29,    30,    31,
      32,    33,    46,    34,    35,    36,    45,    47,    67,    65,
      57,    58,    59,    60,    61,    64,    68,    69,    37,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    66,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    18,    19,    20,    70,    89,    90,    21,
      18,    19,    20,    85,    86,    87,    21,    88,    91,     0,
      22,     0,     0,    18,    19,    20,     0,    22,    93,    21,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      22,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61
  };

  const signed char
  parser::yycheck_[] =
  {
      21,    49,    25,     4,    25,     6,     7,    28,     5,     3,
       0,     8,     9,    10,    62,    25,    37,    14,    25,    40,
      25,    22,    11,    40,    41,    42,    27,    25,    25,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    89,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    15,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    20,    20,    19,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    17,    18,    25,    20,    44,    22,    23,    24,
      25,    26,    20,    28,    29,    30,    44,    20,    25,    21,
      38,    39,    40,    41,    42,    21,    25,    25,    43,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    21,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     8,     9,    10,    25,    12,    13,    14,
       8,     9,    10,    45,    45,    21,    14,    21,    16,    -1,
      25,    -1,    -1,     8,     9,    10,    -1,    25,    13,    14,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      25,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,    47,    25,     0,    48,     4,     6,     7,    22,
      27,    49,    50,    25,    25,    25,    25,     5,     8,     9,
      10,    14,    25,    51,    20,    20,    17,    18,    20,    22,
      23,    24,    25,    26,    28,    29,    30,    43,    52,    52,
      19,    25,    52,    52,    44,    44,    20,    20,    52,    11,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    15,    52,    21,    21,    21,    25,    25,    25,
      25,    50,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    50,    45,    45,    21,    21,    12,
      13,    16,    50,    13
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    46,    47,    48,    48,    49,    49,    49,    49,    50,
      50,    51,    51,    51,    51,    51,    51,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     6,     0,     2,     2,     2,     2,     2,     0,
       2,     4,     4,     3,     5,     7,     5,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "T_PROGRAM", "T_BEGIN",
  "T_END", "T_BOOLEAN", "T_NATURAL", "T_READ", "T_WRITE", "T_IF", "T_THEN",
  "T_ELSE", "T_ENDIF", "T_WHILE", "T_DO", "T_DONE", "T_TRUE", "T_FALSE",
  "T_ASSIGN", "T_OPEN", "T_CLOSE", "T_TIME", "T_HOUR", "T_MINUTE", "T_ID",
  "T_NUM", "T_REAL", "T_REAL_LITERAL", "T_INT", "T_FRAC", "T_OR", "T_AND",
  "T_EQ", "T_LESS", "T_GREATER", "T_LESSEQ", "T_GREATEREQ", "T_ADD",
  "T_SUB", "T_MUL", "T_DIV", "T_MOD", "T_NOT", "\"(\"", "\")\"", "$accept",
  "start", "declarations", "declaration", "commands", "command",
  "expression", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    57,    57,    84,    87,    91,    99,   107,   115,   126,
     130,   137,   149,   162,   188,   203,   222,   242,   249,   256,
     263,   270,   280,   296,   312,   325,   338,   358,   386,   404,
     423,   442,   462,   483,   504,   525,   546,   565,   584,   614,
     625
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
      45
    };
    // Last valid token kind.
    const int code_max = 300;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1818 "while.tab.cc"

#line 631 "while.y"

