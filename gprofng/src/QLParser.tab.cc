// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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
// //                    "%code top" blocks.
#line 28 "QLParser.yy" // lalr1.cc:397

#include <stdio.h>
#include <string.h>
#include <string>

#line 40 "QLParser.tab.cc" // lalr1.cc:397


// First part of user declarations.

#line 45 "QLParser.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "QLParser.tab.hh"

// User implementation prologue.

#line 59 "QLParser.tab.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 42 "QLParser.yy" // lalr1.cc:413

namespace QL
{
  static QL::Parser::symbol_type yylex (QL::Result &result);

  static Expression *
  processName (std::string str)
  {
    const char *name = str.c_str();
    int propID = dbeSession->getPropIdByName (name);
    if (propID != PROP_NONE)
      return new Expression (Expression::OP_NAME,
		      new Expression (Expression::OP_NUM, (uint64_t) propID));

    // If a name is not statically known try user defined objects
    Expression *expr = dbeSession->findObjDefByName (name);
    if (expr != NULL)
      return expr->copy();

    throw Parser::syntax_error ("Name not found");
  }
}

#line 85 "QLParser.tab.cc" // lalr1.cc:413


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



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

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
      *yycdebug_ << std::endl;                  \
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
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 67 "QLParser.yy" // lalr1.cc:479
namespace QL {
#line 152 "QLParser.tab.cc" // lalr1.cc:479

  /// Build a parser object.
  Parser::Parser (QL::Result &result_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      result (result_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
      switch (that.type_get ())
    {
      case 65: // exp
      case 66: // term
        value.move< Expression * > (that.value);
        break;

      case 12: // NAME
        value.move< std::string > (that.value);
        break;

      case 7: // NUM
      case 8: // FNAME
      case 9: // JGROUP
      case 10: // JPARENT
      case 11: // QSTR
        value.move< uint64_t > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 65: // exp
      case 66: // term
        value.copy< Expression * > (that.value);
        break;

      case 12: // NAME
        value.copy< std::string > (that.value);
        break;

      case 7: // NUM
      case 8: // FNAME
      case 9: // JGROUP
      case 10: // JPARENT
      case 11: // QSTR
        value.copy< uint64_t > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex (result));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

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
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 65: // exp
      case 66: // term
        yylhs.value.build< Expression * > ();
        break;

      case 12: // NAME
        yylhs.value.build< std::string > ();
        break;

      case 7: // NUM
      case 8: // FNAME
      case 9: // JGROUP
      case 10: // JPARENT
      case 11: // QSTR
        yylhs.value.build< uint64_t > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 120 "QLParser.yy" // lalr1.cc:859
    { result.out = new Expression (Expression::OP_NUM, (uint64_t) 1); }
#line 530 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 121 "QLParser.yy" // lalr1.cc:859
    { result.out = yystack_[0].value.as< Expression * > (); }
#line 536 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 123 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_DEG, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 542 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 124 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_MUL, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 548 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 125 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_DIV, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 554 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 126 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_REM, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 560 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 127 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_ADD, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 566 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 128 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_MINUS, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 572 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 129 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_LS, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 578 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 130 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_RS, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 584 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 131 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_LT, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 590 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 132 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_LE, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 596 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 133 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_GT, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 602 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 134 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_GE, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 608 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 135 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_EQ, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 614 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 136 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_NE, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 620 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 137 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_BITAND, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 626 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 138 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_BITXOR, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 632 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 139 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_BITOR, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 638 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 140 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_AND, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 644 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 141 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_OR, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 650 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 142 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_NEQV, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 656 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 143 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_EQV, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 662 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 145 "QLParser.yy" // lalr1.cc:859
    {
	     yylhs.value.as< Expression * > () = new Expression (Expression::OP_QWE, yystack_[4].value.as< Expression * > (),
				  new Expression (Expression::OP_COLON, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()));
	  }
#line 671 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 149 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_COMMA, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 677 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 150 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_IN, yystack_[2].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 683 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 151 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_SOMEIN, yystack_[3].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 689 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 152 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_ORDRIN, yystack_[3].value.as< Expression * > (), yystack_[0].value.as< Expression * > ()); }
#line 695 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 153 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = yystack_[0].value.as< Expression * > (); }
#line 701 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 156 "QLParser.yy" // lalr1.cc:859
    {
	     yylhs.value.as< Expression * > () = new Expression (Expression::OP_MINUS,
				  new Expression (Expression::OP_NUM, (uint64_t) 0), yystack_[0].value.as< Expression * > ());
	  }
#line 710 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 160 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_NOT, yystack_[0].value.as< Expression * > ()); }
#line 716 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 161 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_BITNOT, yystack_[0].value.as< Expression * > ()); }
#line 722 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 162 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = yystack_[1].value.as< Expression * > (); }
#line 728 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 164 "QLParser.yy" // lalr1.cc:859
    {
	    yylhs.value.as< Expression * > () = new Expression (Expression::OP_FUNC,
				 new Expression (Expression::OP_NUM, yystack_[3].value.as< uint64_t > ()),
				 new Expression (Expression::OP_NUM, yystack_[1].value.as< uint64_t > ()));
	  }
#line 738 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 170 "QLParser.yy" // lalr1.cc:859
    {
	    yylhs.value.as< Expression * > () = new Expression (Expression::OP_HASPROP,
				 new Expression (Expression::OP_NUM, processName(yystack_[1].value.as< std::string > ())));
	  }
#line 747 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 175 "QLParser.yy" // lalr1.cc:859
    {
	    yylhs.value.as< Expression * > () = new Expression (Expression::OP_JAVA,
				 new Expression (Expression::OP_NUM, yystack_[3].value.as< uint64_t > ()),
				 new Expression (Expression::OP_NUM, yystack_[1].value.as< uint64_t > ()));
	  }
#line 757 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 181 "QLParser.yy" // lalr1.cc:859
    {
	     yylhs.value.as< Expression * > () = new Expression (Expression::OP_JAVA,
				  new Expression (Expression::OP_NUM, yystack_[3].value.as< uint64_t > ()),
				  new Expression (Expression::OP_NUM, yystack_[1].value.as< uint64_t > ()));
	  }
#line 767 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 187 "QLParser.yy" // lalr1.cc:859
    {
	    yylhs.value.as< Expression * > () = new Expression (Expression::OP_FILE,
				 new Expression (Expression::OP_NUM, (uint64_t) 0),
				 new Expression (Expression::OP_NUM, yystack_[1].value.as< uint64_t > ()));
	  }
#line 777 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 192 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = new Expression (Expression::OP_NUM, yystack_[0].value.as< uint64_t > ()); }
#line 783 "QLParser.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 193 "QLParser.yy" // lalr1.cc:859
    { yylhs.value.as< Expression * > () = processName(yystack_[0].value.as< std::string > ()); }
#line 789 "QLParser.tab.cc" // lalr1.cc:859
    break;


#line 793 "QLParser.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
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
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
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

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char Parser::yypact_ninf_ = -3;

  const signed char Parser::yytable_ninf_ = -1;

  const short int
  Parser::yypact_[] =
  {
       0,     0,    -2,     1,    -3,     8,    13,    14,    -3,     0,
       0,     0,     2,   142,    -3,    50,     6,     9,    10,    11,
      12,    -3,    -3,    -3,    -3,     0,    38,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    -3,    15,    21,    22,    49,    51,   188,     0,     0,
     221,    96,    95,    95,    95,    95,    95,    95,    95,   141,
     141,   141,   141,   141,   141,    17,    17,    17,    17,    17,
      17,    17,    17,    -3,    -3,    -3,    -3,    -3,   188,   188,
       0,   221
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       2,     0,     0,     0,    40,     0,     0,     0,    41,     0,
       0,     0,     0,     3,    30,     0,     0,     0,     0,     0,
       0,    31,    32,    33,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     0,     0,    27,     0,     0,
      26,     0,    21,    22,    24,    23,    18,    20,    19,    16,
      17,    12,    14,    13,    15,    10,    11,     8,     9,     5,
       6,     7,     4,    36,    39,    35,    37,    38,    28,    29,
       0,    25
  };

  const signed char
  Parser::yypgoto_[] =
  {
      -3,    -3,    -1,     4
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    12,    13,    14
  };

  const signed char
  Parser::yytable_[] =
  {
      15,    16,    24,     1,    17,     2,     3,     4,     5,     6,
       7,    18,     8,    21,    22,    23,    19,    20,    52,    83,
      53,    54,    55,    56,    57,    84,    85,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
       9,    58,    59,    86,    51,    87,     0,    88,    89,    10,
       0,    11,     0,    25,    26,    27,    28,     0,    29,     0,
       0,     0,    30,     0,    31,    50,    32,    33,    34,    35,
      36,     0,    37,     0,    38,     0,    39,     0,    40,    91,
      41,     0,    42,     0,    43,     0,    44,     0,    45,     0,
      46,     0,    47,     0,    48,     0,    49,     0,    50,    25,
      26,    27,    28,     0,    29,     0,    90,     0,    30,     0,
      31,     0,    32,    33,    34,    35,    36,    37,    37,    38,
      38,    39,    39,    40,    40,    41,    41,    42,    42,    43,
      43,    44,    44,    45,    45,    46,    46,    47,    47,    48,
      48,    49,    49,    50,    50,    25,    26,    27,    28,     0,
      29,     0,     0,     0,    30,     0,    31,     0,    32,    33,
      34,    35,    36,    -1,    37,    -1,    38,    -1,    39,    -1,
      40,    -1,    41,    -1,    42,    43,    43,    44,    44,    45,
      45,    46,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    -1,    -1,    -1,    28,     0,    29,     0,     0,     0,
      30,     0,    31,     0,    32,    33,    34,    35,    36,     0,
      37,     0,    38,     0,    39,     0,    40,     0,    41,     0,
      42,     0,    43,     0,    44,     0,    45,     0,    46,    29,
      47,     0,    48,    30,    49,    31,    50,    32,    33,    34,
      35,    36,     0,    37,     0,    38,     0,    39,     0,    40,
       0,    41,     0,    42,     0,    43,     0,    44,     0,    45,
       0,    46,     0,    47,     0,    48,     0,    49,     0,    50
  };

  const signed char
  Parser::yycheck_[] =
  {
       1,     3,     0,     3,     3,     5,     6,     7,     8,     9,
      10,     3,    12,     9,    10,    11,     3,     3,    12,     4,
      11,    11,    11,    11,    25,     4,     4,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      50,    13,    13,     4,     4,     4,    -1,    58,    59,    59,
      -1,    61,    -1,    13,    14,    15,    16,    -1,    18,    -1,
      -1,    -1,    22,    -1,    24,    58,    26,    27,    28,    29,
      30,    -1,    32,    -1,    34,    -1,    36,    -1,    38,    90,
      40,    -1,    42,    -1,    44,    -1,    46,    -1,    48,    -1,
      50,    -1,    52,    -1,    54,    -1,    56,    -1,    58,    13,
      14,    15,    16,    -1,    18,    -1,    20,    -1,    22,    -1,
      24,    -1,    26,    27,    28,    29,    30,    32,    32,    34,
      34,    36,    36,    38,    38,    40,    40,    42,    42,    44,
      44,    46,    46,    48,    48,    50,    50,    52,    52,    54,
      54,    56,    56,    58,    58,    13,    14,    15,    16,    -1,
      18,    -1,    -1,    -1,    22,    -1,    24,    -1,    26,    27,
      28,    29,    30,    32,    32,    34,    34,    36,    36,    38,
      38,    40,    40,    42,    42,    44,    44,    46,    46,    48,
      48,    50,    50,    52,    52,    54,    54,    56,    56,    58,
      58,    13,    14,    15,    16,    -1,    18,    -1,    -1,    -1,
      22,    -1,    24,    -1,    26,    27,    28,    29,    30,    -1,
      32,    -1,    34,    -1,    36,    -1,    38,    -1,    40,    -1,
      42,    -1,    44,    -1,    46,    -1,    48,    -1,    50,    18,
      52,    -1,    54,    22,    56,    24,    58,    26,    27,    28,
      29,    30,    -1,    32,    -1,    34,    -1,    36,    -1,    38,
      -1,    40,    -1,    42,    -1,    44,    -1,    46,    -1,    48,
      -1,    50,    -1,    52,    -1,    54,    -1,    56,    -1,    58
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     3,     5,     6,     7,     8,     9,    10,    12,    50,
      59,    61,    64,    65,    66,    65,     3,     3,     3,     3,
       3,    66,    66,    66,     0,    13,    14,    15,    16,    18,
      22,    24,    26,    27,    28,    29,    30,    32,    34,    36,
      38,    40,    42,    44,    46,    48,    50,    52,    54,    56,
      58,     4,    12,    11,    11,    11,    11,    65,    13,    13,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,     4,     4,     4,     4,     4,    65,    65,
      20,    65
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    63,    64,    64,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     0,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     3,     3,     4,     4,
       1,     2,     2,     2,     3,     4,     4,     4,     4,     4,
       1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "YYEOF", "error", "$undefined", "\"(\"", "\")\"", "HASPROP",
  "FILEIOVFD", "NUM", "FNAME", "JGROUP", "JPARENT", "QSTR", "NAME", "IN",
  "SOME", "ORDR", "COMMA", "\",\"", "QWE", "\"?\"", "COLON", "\":\"",
  "AND", "\"&&\"", "OR", "\"|\"", "EQV", "NEQV", "BITAND", "BITOR",
  "BITXOR", "\"^\"", "EQ", "\"=\"", "NE", "\"!=\"", "LT", "\"<\"", "GT",
  "\">\"", "LE", "\"<=\"", "GE", "\">=\"", "LS", "\"<<\"", "RS", "\">>\"",
  "ADD", "\"+\"", "MINUS", "\"-\"", "MUL", "\"*\"", "DIV", "\"/\"", "REM",
  "\"%\"", "DEG", "NOT", "\"!\"", "BITNOT", "\"~\"", "$accept", "S", "exp",
  "term", YY_NULLPTR
  };


  const unsigned char
  Parser::yyrline_[] =
  {
       0,   120,   120,   121,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   149,   150,   151,   152,
     153,   155,   160,   161,   162,   163,   169,   174,   180,   186,
     192,   193
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 67 "QLParser.yy" // lalr1.cc:1167
} // QL
#line 1162 "QLParser.tab.cc" // lalr1.cc:1167
#line 195 "QLParser.yy" // lalr1.cc:1168


namespace QL
{
  static Parser::symbol_type
  unget_ret (std::istream &in, char c, Parser::symbol_type tok)
  {
    in.putback (c);
    return tok;
  }

  static Parser::symbol_type
  yylex (QL::Result &result)
  {
    int base = 0;
    int c;

    do
      c = result.in.get ();
    while (result.in && (c == ' ' || c == '\t'));
    if (!result.in)
      return Parser::make_YYEOF ();

    switch (c)
      {
      case '\0':
      case '\n': return Parser::make_YYEOF ();
      case '(': return Parser::make_LPAR () ;
      case ')': return Parser::make_RPAR ();
      case ',': return Parser::make_COMMA ();
      case '%': return Parser::make_REM ();
      case '/': return Parser::make_DIV ();
      case '*': return Parser::make_MUL ();
      case '-': return Parser::make_MINUS ();
      case '+': return Parser::make_ADD ();
      case '~': return Parser::make_BITNOT ();
      case '^': return Parser::make_BITXOR ();
      case '?': return Parser::make_QWE ();
      case ':': return Parser::make_COLON ();
      case '|':
	c = result.in.get ();
	if (c == '|')
	  return Parser::make_OR ();
	else
	  return unget_ret (result.in, c, Parser::make_BITOR ());
      case '&':
	c = result.in.get ();
	if (c == '&')
	  return Parser::make_AND ();
	else
	  return unget_ret (result.in, c, Parser::make_BITAND ());
      case '!':
	c = result.in.get ();
	if (c == '=')
	  return Parser::make_NE ();
	else
	  return unget_ret (result.in, c, Parser::make_NOT ());
      case '=':
	c = result.in.get ();
	if (c == '=')
	  return Parser::make_EQ ();
	else
	  throw Parser::syntax_error ("Syntax error after =");
      case '<':
	c = result.in.get ();
	if (c == '=')
	  return Parser::make_LE ();
	else if (c == '<')
	  return Parser::make_LS ();
	else
	  return unget_ret (result.in, c, Parser::make_LT ());
      case '>':
	c = result.in.get ();
	if (c == '=')
	  return Parser::make_GE ();
	else if (c == '>')
	  return Parser::make_RS ();
	else
	  return unget_ret (result.in, c, Parser::make_GT ());
      case '"':
	{
	  int  maxsz = 16;
	  char *str = (char *) malloc (maxsz);
	  char *ptr = str;

	  for (;;)
	    {
	      c = result.in.get ();
	      if (!result.in)
		{
		  free (str);
		  throw Parser::syntax_error ("Unclosed \"");
		}

	      switch (c)
		{
		case '"':
		  *ptr = (char)0;
		  // XXX omazur: need new string type
		  return Parser::make_QSTR ((uint64_t) str);
		case 0:
		case '\n':
		  free (str);
		  throw Parser::syntax_error ("Multiline strings are not supported");
		default:
		  if (ptr - str >= maxsz)
		    {
		      size_t len = ptr - str;
		      maxsz = maxsz > 8192 ? maxsz + 8192 : maxsz * 2;
		      char *new_s = (char *) realloc (str, maxsz);
		      str = new_s;
		      ptr = str + len;
		    }
		  *ptr++ = c;
		}
	    }
	}
      default:
	if (c == '0')
	  {
	    base = 8;
	    c = result.in.get ();
	    if ( c == 'x' )
	      {
		base = 16;
		c = result.in.get ();
	      }
	  }
	else if (c >= '1' && c <='9')
	  base = 10;

	if (base)
	  {
	    uint64_t lval = 0;
	    for (;;)
	      {
		int digit = -1;
		switch (c)
		  {
		  case '0': case '1': case '2': case '3':
		  case '4': case '5': case '6': case '7':
		    digit = c - '0';
		    break;
		  case '8': case '9':
		    if (base > 8)
		      digit = c - '0';
		    break;
		  case 'a': case 'b': case 'c':
		  case 'd': case 'e': case 'f':
		    if (base == 16)
		      digit = c - 'a' + 10;
		    break;
		  case 'A': case 'B': case 'C':
		  case 'D': case 'E': case 'F':
		    if (base == 16)
		      digit = c - 'A' + 10;
		    break;
		  }
		if  (digit == -1)
		  {
		    result.in.putback (c);
		    break;
		  }
		lval = lval * base + digit;
		c = result.in.get ();
	      }
	    return Parser::make_NUM (lval);
	  }

	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	  {
	    char name[32];	// omazur XXX: accept any length
	    name[0] = (char)c;
	    for (size_t i = 1; i < sizeof (name); i++)
	      {
		c = result.in.get ();
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
		    (c >= '0' && c <= '9') || (c == '_'))
		  name[i] = c;
		else
		  {
		    name[i] = (char)0;
		    result.in.putback (c);
		    break;
		  }
	      }

	    if (strcasecmp (name, NTXT ("IN")) == 0)
	      return Parser::make_IN ();
	    else if (strcasecmp (name, NTXT ("SOME")) == 0)
	      return Parser::make_SOME ();
	    else if (strcasecmp (name, NTXT ("ORDERED")) == 0)
	      return Parser::make_ORDR ();
	    else if (strcasecmp (name, NTXT ("TRUE")) == 0)
	      return Parser::make_NUM ((uint64_t) 1);
	    else if (strcasecmp (name, NTXT ("FALSE")) == 0)
	      return Parser::make_NUM ((uint64_t) 0);
	    else if (strcasecmp (name, NTXT ("FNAME")) == 0)
	      return Parser::make_FNAME (Expression::FUNC_FNAME);
	    else if (strcasecmp (name, NTXT ("HAS_PROP")) == 0)
	      return Parser::make_HASPROP ();
	    else if (strcasecmp (name, NTXT ("JGROUP")) == 0)
	      return Parser::make_JGROUP (Expression::JAVA_JGROUP);
	    else if (strcasecmp (name, NTXT ("JPARENT")) == 0 )
	      return Parser::make_JPARENT (Expression::JAVA_JPARENT);
	    else if (strcasecmp (name, NTXT ("DNAME")) == 0)
	      return Parser::make_FNAME (Expression::FUNC_DNAME);
	    else if (strcasecmp (name, NTXT ("FILEIOVFD")) == 0 )
	      return Parser::make_FILEIOVFD ();

	    std::string nm = std::string (name);
	    return Parser::make_NAME (nm);
	  }

	throw Parser::syntax_error ("Syntax error");
      }
  }
  void
  Parser::error (const std::string &)
  {
    // do nothing for now
  }
}

