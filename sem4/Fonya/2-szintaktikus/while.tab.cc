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
#line 53 "while.y"
    {
        std::cout << "start -> T_PROGRAM T_ID declarations T_BEGIN statements T_END" << std::endl;
    }
#line 626 "while.tab.cc"
    break;

  case 3: // declarations: %empty
#line 60 "while.y"
    {
        std::cout << "declarations -> epsilon" << std::endl;
    }
#line 634 "while.tab.cc"
    break;

  case 4: // declarations: declaration declarations
#line 65 "while.y"
    {
        std::cout << "declarations -> declaration declarations" << std::endl;
    }
#line 642 "while.tab.cc"
    break;

  case 5: // declaration: T_INTEGER T_ID T_SEMICOLON
#line 72 "while.y"
    {
        std::cout << "declaration -> T_INTEGER T_ID T_SEMICOLON" << std::endl;
    }
#line 650 "while.tab.cc"
    break;

  case 6: // declaration: T_BOOLEAN T_ID T_SEMICOLON
#line 77 "while.y"
    {
        std::cout << "declaration -> T_BOOLEAN T_ID T_SEMICOLON" << std::endl;
    }
#line 658 "while.tab.cc"
    break;

  case 7: // label: T_ID T_COLON
#line 84 "while.y"
    {
        std::cout << "label -> T_ID T_COLON" << std::endl;
    }
#line 666 "while.tab.cc"
    break;

  case 8: // statements: statement
#line 91 "while.y"
    {
        std::cout << "statements -> statement" << std::endl;
    }
#line 674 "while.tab.cc"
    break;

  case 9: // statements: statement statements
#line 96 "while.y"
    {
        std::cout << "statements -> statement statements" << std::endl;
    }
#line 682 "while.tab.cc"
    break;

  case 10: // statements: label statement
#line 101 "while.y"
    {
        std::cout << "statements -> label statement" << std::endl;
    }
#line 690 "while.tab.cc"
    break;

  case 11: // statements: label statement statements
#line 106 "while.y"
    {
        std::cout << "statements -> label statement statements" << std::endl;
    }
#line 698 "while.tab.cc"
    break;

  case 12: // statement: T_SKIP T_SEMICOLON
#line 113 "while.y"
    {
        std::cout << "statement -> T_SKIP T_SEMICOLON" << std::endl;
    }
#line 706 "while.tab.cc"
    break;

  case 13: // statement: T_ID T_ASSIGN expression T_SEMICOLON
#line 118 "while.y"
    {
        std::cout << "assignment -> T_ID T_ASSIGN expression T_SEMICOLON" << std::endl;
    }
#line 714 "while.tab.cc"
    break;

  case 14: // statement: T_READ T_OPEN T_ID T_CLOSE T_SEMICOLON
#line 123 "while.y"
    {
        std::cout << "read -> T_READ T_OPEN T_ID T_CLOSE T_SEMICOLON" << std::endl;
    }
#line 722 "while.tab.cc"
    break;

  case 15: // statement: T_WRITE T_OPEN expression T_CLOSE T_SEMICOLON
#line 128 "while.y"
    {
        std::cout << "write -> T_WRITE T_OPEN expression T_CLOSE T_SEMICOLON" << std::endl;
    }
#line 730 "while.tab.cc"
    break;

  case 16: // statement: T_IF expression T_THEN statements T_ENDIF
#line 133 "while.y"
    {
        std::cout << "branch -> T_IF expression T_THEN statements T_ENDIF" << std::endl;
    }
#line 738 "while.tab.cc"
    break;

  case 17: // statement: T_IF expression T_THEN statements T_ELSE statements T_ENDIF
#line 138 "while.y"
    {
        std::cout << "branch -> T_IF expression T_THEN statements T_ELSE statements T_ENDIF" << std::endl;
    }
#line 746 "while.tab.cc"
    break;

  case 18: // statement: T_WHILE expression T_DO statements T_DONE
#line 143 "while.y"
    {
        std::cout << "loop -> T_WHILE expression T_DO statements T_DONE" << std::endl;
    }
#line 754 "while.tab.cc"
    break;

  case 19: // statement: T_REPEAT statements T_UNTIL expression
#line 148 "while.y"
    {
        std::cout << "repeat -> T_REPEAT statements T_UNTIL expression" << std::endl;
    }
#line 762 "while.tab.cc"
    break;

  case 20: // statement: T_FOR T_ID T_FROM expression directions expression T_DO statements T_DONE
#line 153 "while.y"
    {
        std::cout << "T_FOR T_ID expression directions expression T_DO statements T_DONE" << std::endl;
    }
#line 770 "while.tab.cc"
    break;

  case 21: // statement: T_GOTO T_ID
#line 158 "while.y"
    {
        std::cout << "T_GOTO T_ID" << std::endl;
    }
#line 778 "while.tab.cc"
    break;

  case 22: // directions: T_UPTO
#line 165 "while.y"
    {
        std::cout << "T_UPTO" << std::endl;
    }
#line 786 "while.tab.cc"
    break;

  case 23: // directions: T_DOWNTO
#line 170 "while.y"
    {
        std::cout << "T_DOWNTO" << std::endl;
    }
#line 794 "while.tab.cc"
    break;

  case 24: // expression: T_NUM
#line 177 "while.y"
    {
        std::cout << "expression -> T_NUM" << std::endl;
    }
#line 802 "while.tab.cc"
    break;

  case 25: // expression: T_TRUE
#line 182 "while.y"
    {
        std::cout << "expression -> T_TRUE" << std::endl;
    }
#line 810 "while.tab.cc"
    break;

  case 26: // expression: T_FALSE
#line 187 "while.y"
    {
        std::cout << "expression -> T_FALSE" << std::endl;
    }
#line 818 "while.tab.cc"
    break;

  case 27: // expression: T_ID
#line 192 "while.y"
    {
        std::cout << "expression -> T_ID" << std::endl;
    }
#line 826 "while.tab.cc"
    break;

  case 28: // expression: expression T_ADD expression
#line 197 "while.y"
    {
        std::cout << "expression -> expression T_ADD expression" << std::endl;
    }
#line 834 "while.tab.cc"
    break;

  case 29: // expression: expression T_SUB expression
#line 202 "while.y"
    {
        std::cout << "expression -> expression T_SUB expression" << std::endl;
    }
#line 842 "while.tab.cc"
    break;

  case 30: // expression: expression T_MUL expression
#line 207 "while.y"
    {
        std::cout << "expression -> expression T_MUL expression" << std::endl;
    }
#line 850 "while.tab.cc"
    break;

  case 31: // expression: expression T_DIV expression
#line 212 "while.y"
    {
        std::cout << "expression -> expression T_DIV expression" << std::endl;
    }
#line 858 "while.tab.cc"
    break;

  case 32: // expression: expression T_MOD expression
#line 217 "while.y"
    {
        std::cout << "expression -> expression T_MOD expression" << std::endl;
    }
#line 866 "while.tab.cc"
    break;

  case 33: // expression: expression T_LESS expression
#line 222 "while.y"
    {
        std::cout << "expression -> expression T_LESS expression" << std::endl;
    }
#line 874 "while.tab.cc"
    break;

  case 34: // expression: expression T_GR expression
#line 227 "while.y"
    {
        std::cout << "expression -> expression T_GR expression" << std::endl;
    }
#line 882 "while.tab.cc"
    break;

  case 35: // expression: expression T_EQ expression
#line 232 "while.y"
    {
        std::cout << "expression -> expression T_EQ expression" << std::endl;
    }
#line 890 "while.tab.cc"
    break;

  case 36: // expression: expression T_AND expression
#line 237 "while.y"
    {
        std::cout << "expression -> expression T_AND expression" << std::endl;
    }
#line 898 "while.tab.cc"
    break;

  case 37: // expression: expression T_OR expression
#line 242 "while.y"
    {
        std::cout << "expression -> expression T_OR expression" << std::endl;
    }
#line 906 "while.tab.cc"
    break;

  case 38: // expression: T_NOT expression
#line 247 "while.y"
    {
        std::cout << "expression -> T_NOT expression" << std::endl;
    }
#line 914 "while.tab.cc"
    break;

  case 39: // expression: T_OPEN expression T_CLOSE
#line 252 "while.y"
    {
        std::cout << "expression -> T_OPEN expression T_CLOSE" << std::endl;
    }
#line 922 "while.tab.cc"
    break;

  case 40: // expression: expression T_QMARK expression T_COLON expression
#line 257 "while.y"
    {
        std::cout << "expression T_QMARK expression T_COLON expression" << std::endl;
    }
#line 930 "while.tab.cc"
    break;


#line 934 "while.tab.cc"

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









  const signed char parser::yypact_ninf_ = -27;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
       1,   -11,     7,    -4,   -27,    -1,     2,    15,    -4,    13,
      14,   135,   -27,   -27,   -27,    21,   -12,   -12,    34,    35,
     -18,   135,    16,    31,   149,    54,   135,   -27,   -12,   -27,
     -27,   -27,   -27,   -12,    53,    66,    36,   -12,   -12,   -27,
      33,    48,   -27,    43,   135,   -27,   -27,    32,    46,   135,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   135,    44,   150,    98,   -12,   -12,   -27,   -27,    10,
     178,   204,   204,   217,    -6,    -6,   -26,   -26,    46,    46,
      46,    67,    65,    68,   -27,   191,   165,   135,   -27,   -12,
     -27,   -27,   -27,   -27,   -27,   -12,    72,   191,    85,   -27,
     135,    96,   -27
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     3,     1,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,    12,     0,    24,
      25,    26,    27,     0,     0,     0,     0,     0,     0,     7,
       0,     0,    21,     0,    10,     2,     9,     0,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    39,     0,
       0,    37,    36,    35,    33,    34,    28,    29,    30,    31,
      32,     0,     0,     0,    13,    19,     0,     0,    16,     0,
      18,    14,    15,    22,    23,     0,     0,    40,     0,    17,
       0,     0,    20
  };

  const signed char
  parser::yypgoto_[] =
  {
     -27,   -27,    92,   -27,   -27,   -21,    88,   -27,    -8
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     2,     7,     8,    24,    25,    26,    95,    34
  };

  const signed char
  parser::yytable_[] =
  {
      40,    38,     5,     6,     1,    46,    50,     4,    28,    35,
      29,    30,    31,    32,     3,    39,    58,    59,    60,    11,
      47,    87,    88,    67,     9,    48,    50,    10,    69,    63,
      64,    13,    14,    33,    56,    57,    58,    59,    60,    27,
      81,    41,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    68,    36,    37,    42,    85,    86,    45,
      65,    62,    38,    49,    50,    82,    96,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    66,    50,   101,
      61,    97,    90,    91,    99,    50,    92,    98,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    50,   100,
      12,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,   102,    44,     0,     0,     0,    84,    50,     0,     0,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      50,     0,     0,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    15,    16,     0,     0,     0,    17,     0,
       0,    18,    19,     0,     0,     0,     0,    15,    16,     0,
      20,    21,    17,    22,     0,    18,    19,     0,     0,    23,
       0,    83,     0,     0,    43,    21,     0,    22,     0,     0,
       0,     0,    50,    23,     0,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    93,    94,    50,     0,     0,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      50,    89,     0,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    50,     0,     0,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    50,     0,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    50,
       0,     0,     0,     0,     0,    54,    55,    56,    57,    58,
      59,    60
  };

  const signed char
  parser::yycheck_[] =
  {
      21,    19,     6,     7,     3,    26,    32,     0,    20,    17,
      22,    23,    24,    25,    25,    33,    42,    43,    44,     4,
      28,    11,    12,    44,    25,    33,    32,    25,    49,    37,
      38,    18,    18,    45,    40,    41,    42,    43,    44,    18,
      61,    25,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    21,    20,    20,    25,    65,    66,     5,
      27,    25,    19,    10,    32,    21,    87,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    29,    32,   100,
      14,    89,    15,    18,    12,    32,    18,    95,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    32,    14,
       8,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    15,    24,    -1,    -1,    -1,    18,    32,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      32,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     8,     9,    -1,    -1,    -1,    13,    -1,
      -1,    16,    17,    -1,    -1,    -1,    -1,     8,     9,    -1,
      25,    26,    13,    28,    -1,    16,    17,    -1,    -1,    34,
      -1,    21,    -1,    -1,    25,    26,    -1,    28,    -1,    -1,
      -1,    -1,    32,    34,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    30,    31,    32,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    32,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    32,    -1,    -1,    -1,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    32,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,    47,    25,     0,     6,     7,    48,    49,    25,
      25,     4,    48,    18,    18,     8,     9,    13,    16,    17,
      25,    26,    28,    34,    50,    51,    52,    18,    20,    22,
      23,    24,    25,    45,    54,    54,    20,    20,    19,    33,
      51,    25,    25,    25,    52,     5,    51,    54,    54,    10,
      32,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    14,    25,    54,    54,    27,    29,    51,    21,    51,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    51,    21,    21,    18,    54,    54,    11,    12,    33,
      15,    18,    18,    30,    31,    53,    51,    54,    54,    12,
      14,    51,    15
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    46,    47,    48,    48,    49,    49,    50,    51,    51,
      51,    51,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    53,    53,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     6,     0,     2,     3,     3,     2,     1,     2,
       2,     3,     2,     4,     5,     5,     5,     7,     5,     4,
       9,     2,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       5
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
  "T_FALSE", "T_ID", "T_REPEAT", "T_UNTIL", "T_FOR", "T_FROM", "T_UPTO",
  "T_DOWNTO", "T_QMARK", "T_COLON", "T_GOTO", "T_OR", "T_AND", "T_EQ",
  "T_LESS", "T_GR", "T_ADD", "T_SUB", "T_MUL", "T_DIV", "T_MOD", "T_NOT",
  "$accept", "start", "declarations", "declaration", "label", "statements",
  "statement", "directions", "expression", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    52,    52,    60,    64,    71,    76,    83,    90,    95,
     100,   105,   112,   117,   122,   127,   132,   137,   142,   147,
     152,   157,   164,   169,   176,   181,   186,   191,   196,   201,
     206,   211,   216,   221,   226,   231,   236,   241,   246,   251,
     256
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
#line 1386 "while.tab.cc"

