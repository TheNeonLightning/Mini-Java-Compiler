// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

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

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.hh"


// Unqualified %code blocks.
#line 79 "parser.y"

    #include "driver.hh"
    #include "location.hh"

    #include "program/Program.h"

    #include "main_class/MainClass.h"

    #include "declarations/Declaration.h"
    #include "declarations/ClassDeclaration.h"
    #include "declarations/MethodDeclaration.h"
    #include "declarations/VarDeclaration.h"

    #include "statements/Statement.h"
    #include "statements/AssertStatement.h"
    #include "statements/LocVarDecStatement.h"
    #include "statements/BracesStatement.h"
    #include "statements/IfStatement.h"
    #include "statements/IfElseStatement.h"
    #include "statements/WhileStatement.h"
    #include "statements/SOPrintlnStatement.h"
    #include "statements/LValueAssignStatement.h"
    #include "statements/ReturnStatement.h"
    #include "statements/MethodInvStatement.h"

    #include "expressions/Expression.h"
    #include "expressions/AndExpression.h"
    #include "expressions/OrExpression.h"
    #include "expressions/LessExpression.h"
    #include "expressions/GreaterExpression.h"
    #include "expressions/IsEqualExpression.h"
    #include "expressions/AddExpression.h"
    #include "expressions/SubExpression.h"
    #include "expressions/MulExpression.h"
    #include "expressions/DivExpression.h"
    #include "expressions/ResidueExpression.h"
    #include "expressions/AccessExpression.h"
    #include "expressions/LengthExpression.h"
    #include "expressions/NewArrayExpression.h"
    #include "expressions/NewExpression.h"
    #include "expressions/NegativeExpression.h"
    #include "expressions/ParensExpression.h"
    #include "expressions/IdentifierExpression.h"
    #include "expressions/IntegerExpression.h"
    #include "expressions/ThisExpression.h"
    #include "expressions/LogicExpression.h"
    #include "expressions/MethodInvExpression.h"

    #include "lvalue/LValue.h"
    #include "lvalue/SimpleTypeIdentifier.h"
    #include "lvalue/ArrayIdentifier.h"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }

#line 102 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"


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
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
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
#line 193 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (Scanner &scanner_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



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

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 44: // "number"
      case 69: // integer
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 50: // class_declaration
        value.YY_MOVE_OR_COPY< std::shared_ptr<ClassDeclaration> > (YY_MOVE (that.value));
        break;

      case 52: // declaration
      case 53: // method_declaration
      case 54: // variable_declaration
        value.YY_MOVE_OR_COPY< std::shared_ptr<Declaration> > (YY_MOVE (that.value));
        break;

      case 68: // expr
        value.YY_MOVE_OR_COPY< std::shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case 66: // lvalue
        value.YY_MOVE_OR_COPY< std::shared_ptr<LValue> > (YY_MOVE (that.value));
        break;

      case 48: // main_class
        value.YY_MOVE_OR_COPY< std::shared_ptr<MainClass> > (YY_MOVE (that.value));
        break;

      case 65: // method_invocation
        value.YY_MOVE_OR_COPY< std::shared_ptr<MethodInvExpression> > (YY_MOVE (that.value));
        break;

      case 46: // unit
      case 47: // program
        value.YY_MOVE_OR_COPY< std::shared_ptr<Program> > (YY_MOVE (that.value));
        break;

      case 63: // statement
      case 64: // local_variable_declaration
        value.YY_MOVE_OR_COPY< std::shared_ptr<Statement> > (YY_MOVE (that.value));
        break;

      case 57: // argument
        value.YY_MOVE_OR_COPY< std::shared_ptr<VarDeclaration> > (YY_MOVE (that.value));
        break;

      case 43: // "identifier"
      case 58: // type
      case 59: // simple_type
      case 60: // array_type
      case 61: // type_identifier
      case 70: // logic
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 49: // class_declarations
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<ClassDeclaration>> > (YY_MOVE (that.value));
        break;

      case 51: // declarations
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<Declaration>> > (YY_MOVE (that.value));
        break;

      case 67: // expressions
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<Expression>> > (YY_MOVE (that.value));
        break;

      case 62: // statements
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<Statement>> > (YY_MOVE (that.value));
        break;

      case 55: // formals
      case 56: // arguments
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<VarDeclaration>> > (YY_MOVE (that.value));
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
    switch (that.type_get ())
    {
      case 44: // "number"
      case 69: // integer
        value.move< int > (YY_MOVE (that.value));
        break;

      case 50: // class_declaration
        value.move< std::shared_ptr<ClassDeclaration> > (YY_MOVE (that.value));
        break;

      case 52: // declaration
      case 53: // method_declaration
      case 54: // variable_declaration
        value.move< std::shared_ptr<Declaration> > (YY_MOVE (that.value));
        break;

      case 68: // expr
        value.move< std::shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case 66: // lvalue
        value.move< std::shared_ptr<LValue> > (YY_MOVE (that.value));
        break;

      case 48: // main_class
        value.move< std::shared_ptr<MainClass> > (YY_MOVE (that.value));
        break;

      case 65: // method_invocation
        value.move< std::shared_ptr<MethodInvExpression> > (YY_MOVE (that.value));
        break;

      case 46: // unit
      case 47: // program
        value.move< std::shared_ptr<Program> > (YY_MOVE (that.value));
        break;

      case 63: // statement
      case 64: // local_variable_declaration
        value.move< std::shared_ptr<Statement> > (YY_MOVE (that.value));
        break;

      case 57: // argument
        value.move< std::shared_ptr<VarDeclaration> > (YY_MOVE (that.value));
        break;

      case 43: // "identifier"
      case 58: // type
      case 59: // simple_type
      case 60: // array_type
      case 61: // type_identifier
      case 70: // logic
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 49: // class_declarations
        value.move< std::vector<std::shared_ptr<ClassDeclaration>> > (YY_MOVE (that.value));
        break;

      case 51: // declarations
        value.move< std::vector<std::shared_ptr<Declaration>> > (YY_MOVE (that.value));
        break;

      case 67: // expressions
        value.move< std::vector<std::shared_ptr<Expression>> > (YY_MOVE (that.value));
        break;

      case 62: // statements
        value.move< std::vector<std::shared_ptr<Statement>> > (YY_MOVE (that.value));
        break;

      case 55: // formals
      case 56: // arguments
        value.move< std::vector<std::shared_ptr<VarDeclaration>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 44: // "number"
      case 69: // integer
        value.copy< int > (that.value);
        break;

      case 50: // class_declaration
        value.copy< std::shared_ptr<ClassDeclaration> > (that.value);
        break;

      case 52: // declaration
      case 53: // method_declaration
      case 54: // variable_declaration
        value.copy< std::shared_ptr<Declaration> > (that.value);
        break;

      case 68: // expr
        value.copy< std::shared_ptr<Expression> > (that.value);
        break;

      case 66: // lvalue
        value.copy< std::shared_ptr<LValue> > (that.value);
        break;

      case 48: // main_class
        value.copy< std::shared_ptr<MainClass> > (that.value);
        break;

      case 65: // method_invocation
        value.copy< std::shared_ptr<MethodInvExpression> > (that.value);
        break;

      case 46: // unit
      case 47: // program
        value.copy< std::shared_ptr<Program> > (that.value);
        break;

      case 63: // statement
      case 64: // local_variable_declaration
        value.copy< std::shared_ptr<Statement> > (that.value);
        break;

      case 57: // argument
        value.copy< std::shared_ptr<VarDeclaration> > (that.value);
        break;

      case 43: // "identifier"
      case 58: // type
      case 59: // simple_type
      case 60: // array_type
      case 61: // type_identifier
      case 70: // logic
        value.copy< std::string > (that.value);
        break;

      case 49: // class_declarations
        value.copy< std::vector<std::shared_ptr<ClassDeclaration>> > (that.value);
        break;

      case 51: // declarations
        value.copy< std::vector<std::shared_ptr<Declaration>> > (that.value);
        break;

      case 67: // expressions
        value.copy< std::vector<std::shared_ptr<Expression>> > (that.value);
        break;

      case 62: // statements
        value.copy< std::vector<std::shared_ptr<Statement>> > (that.value);
        break;

      case 55: // formals
      case 56: // arguments
        value.copy< std::vector<std::shared_ptr<VarDeclaration>> > (that.value);
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
    switch (that.type_get ())
    {
      case 44: // "number"
      case 69: // integer
        value.move< int > (that.value);
        break;

      case 50: // class_declaration
        value.move< std::shared_ptr<ClassDeclaration> > (that.value);
        break;

      case 52: // declaration
      case 53: // method_declaration
      case 54: // variable_declaration
        value.move< std::shared_ptr<Declaration> > (that.value);
        break;

      case 68: // expr
        value.move< std::shared_ptr<Expression> > (that.value);
        break;

      case 66: // lvalue
        value.move< std::shared_ptr<LValue> > (that.value);
        break;

      case 48: // main_class
        value.move< std::shared_ptr<MainClass> > (that.value);
        break;

      case 65: // method_invocation
        value.move< std::shared_ptr<MethodInvExpression> > (that.value);
        break;

      case 46: // unit
      case 47: // program
        value.move< std::shared_ptr<Program> > (that.value);
        break;

      case 63: // statement
      case 64: // local_variable_declaration
        value.move< std::shared_ptr<Statement> > (that.value);
        break;

      case 57: // argument
        value.move< std::shared_ptr<VarDeclaration> > (that.value);
        break;

      case 43: // "identifier"
      case 58: // type
      case 59: // simple_type
      case 60: // array_type
      case 61: // type_identifier
      case 70: // logic
        value.move< std::string > (that.value);
        break;

      case 49: // class_declarations
        value.move< std::vector<std::shared_ptr<ClassDeclaration>> > (that.value);
        break;

      case 51: // declarations
        value.move< std::vector<std::shared_ptr<Declaration>> > (that.value);
        break;

      case 67: // expressions
        value.move< std::vector<std::shared_ptr<Expression>> > (that.value);
        break;

      case 62: // statements
        value.move< std::vector<std::shared_ptr<Statement>> > (that.value);
        break;

      case 55: // formals
      case 56: // arguments
        value.move< std::vector<std::shared_ptr<VarDeclaration>> > (that.value);
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
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
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
  parser::yypop_ (int n)
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
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
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
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner, driver));
            yyla.move (yylookahead);
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

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
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
      case 44: // "number"
      case 69: // integer
        yylhs.value.emplace< int > ();
        break;

      case 50: // class_declaration
        yylhs.value.emplace< std::shared_ptr<ClassDeclaration> > ();
        break;

      case 52: // declaration
      case 53: // method_declaration
      case 54: // variable_declaration
        yylhs.value.emplace< std::shared_ptr<Declaration> > ();
        break;

      case 68: // expr
        yylhs.value.emplace< std::shared_ptr<Expression> > ();
        break;

      case 66: // lvalue
        yylhs.value.emplace< std::shared_ptr<LValue> > ();
        break;

      case 48: // main_class
        yylhs.value.emplace< std::shared_ptr<MainClass> > ();
        break;

      case 65: // method_invocation
        yylhs.value.emplace< std::shared_ptr<MethodInvExpression> > ();
        break;

      case 46: // unit
      case 47: // program
        yylhs.value.emplace< std::shared_ptr<Program> > ();
        break;

      case 63: // statement
      case 64: // local_variable_declaration
        yylhs.value.emplace< std::shared_ptr<Statement> > ();
        break;

      case 57: // argument
        yylhs.value.emplace< std::shared_ptr<VarDeclaration> > ();
        break;

      case 43: // "identifier"
      case 58: // type
      case 59: // simple_type
      case 60: // array_type
      case 61: // type_identifier
      case 70: // logic
        yylhs.value.emplace< std::string > ();
        break;

      case 49: // class_declarations
        yylhs.value.emplace< std::vector<std::shared_ptr<ClassDeclaration>> > ();
        break;

      case 51: // declarations
        yylhs.value.emplace< std::vector<std::shared_ptr<Declaration>> > ();
        break;

      case 67: // expressions
        yylhs.value.emplace< std::vector<std::shared_ptr<Expression>> > ();
        break;

      case 62: // statements
        yylhs.value.emplace< std::vector<std::shared_ptr<Statement>> > ();
        break;

      case 55: // formals
      case 56: // arguments
        yylhs.value.emplace< std::vector<std::shared_ptr<VarDeclaration>> > ();
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
  case 2:
#line 236 "parser.y"
              { yylhs.value.as < std::shared_ptr<Program> > () = yystack_[0].value.as < std::shared_ptr<Program> > (); driver.program = yystack_[0].value.as < std::shared_ptr<Program> > (); }
#line 996 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 3:
#line 239 "parser.y"
                                  { yylhs.value.as < std::shared_ptr<Program> > () = std::make_shared<Program>(yystack_[1].value.as < std::shared_ptr<MainClass> > (), yystack_[0].value.as < std::vector<std::shared_ptr<ClassDeclaration>> > ()); }
#line 1002 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 4:
#line 246 "parser.y"
        { yylhs.value.as < std::shared_ptr<MainClass> > () = std::make_shared<MainClass>(yystack_[11].value.as < std::string > (), yystack_[2].value.as < std::vector<std::shared_ptr<Statement>> > ()); }
#line 1008 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 5:
#line 249 "parser.y"
             { yylhs.value.as < std::vector<std::shared_ptr<ClassDeclaration>> > () = std::vector<std::shared_ptr<ClassDeclaration>>(); }
#line 1014 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 6:
#line 250 "parser.y"
                                           { yystack_[1].value.as < std::vector<std::shared_ptr<ClassDeclaration>> > ().push_back(yystack_[0].value.as < std::shared_ptr<ClassDeclaration> > ()); yylhs.value.as < std::vector<std::shared_ptr<ClassDeclaration>> > () = yystack_[1].value.as < std::vector<std::shared_ptr<ClassDeclaration>> > (); }
#line 1020 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 7:
#line 255 "parser.y"
          { yylhs.value.as < std::shared_ptr<ClassDeclaration> > () = std::make_shared<ClassDeclaration>(yystack_[3].value.as < std::string > (), "", yystack_[1].value.as < std::vector<std::shared_ptr<Declaration>> > ()); }
#line 1026 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 8:
#line 258 "parser.y"
          { yylhs.value.as < std::shared_ptr<ClassDeclaration> > () = std::make_shared<ClassDeclaration>(yystack_[5].value.as < std::string > (), yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<std::shared_ptr<Declaration>> > ()); }
#line 1032 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 9:
#line 261 "parser.y"
             { yylhs.value.as < std::vector<std::shared_ptr<Declaration>> > () = std::vector<std::shared_ptr<Declaration>>(); }
#line 1038 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 10:
#line 262 "parser.y"
                               { yystack_[1].value.as < std::vector<std::shared_ptr<Declaration>> > ().push_back(yystack_[0].value.as < std::shared_ptr<Declaration> > ()); yylhs.value.as < std::vector<std::shared_ptr<Declaration>> > () = yystack_[1].value.as < std::vector<std::shared_ptr<Declaration>> > (); }
#line 1044 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 11:
#line 265 "parser.y"
                           { yylhs.value.as < std::shared_ptr<Declaration> > () = yystack_[0].value.as < std::shared_ptr<Declaration> > (); }
#line 1050 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 12:
#line 266 "parser.y"
                         { yylhs.value.as < std::shared_ptr<Declaration> > () = yystack_[0].value.as < std::shared_ptr<Declaration> > (); }
#line 1056 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 13:
#line 273 "parser.y"
      { yylhs.value.as < std::shared_ptr<Declaration> > () = std::make_shared<MethodDeclaration>
       (yystack_[6].value.as < std::string > (), yystack_[5].value.as < std::string > (), std::vector<std::shared_ptr<VarDeclaration>>(), yystack_[1].value.as < std::vector<std::shared_ptr<Statement>> > ()); }
#line 1063 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 14:
#line 279 "parser.y"
      { yylhs.value.as < std::shared_ptr<Declaration> > () = std::make_shared<MethodDeclaration>(yystack_[7].value.as < std::string > (), yystack_[6].value.as < std::string > (), yystack_[4].value.as < std::vector<std::shared_ptr<VarDeclaration>> > (), yystack_[1].value.as < std::vector<std::shared_ptr<Statement>> > ()); }
#line 1069 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 15:
#line 282 "parser.y"
                            { yylhs.value.as < std::shared_ptr<Declaration> > () = std::make_shared<VarDeclaration>(yystack_[2].value.as < std::string > (), yystack_[1].value.as < std::string > ()); }
#line 1075 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 16:
#line 286 "parser.y"
      { yystack_[0].value.as < std::vector<std::shared_ptr<VarDeclaration>> > ().insert(yystack_[0].value.as < std::vector<std::shared_ptr<VarDeclaration>> > ().begin(), std::make_shared<VarDeclaration>(yystack_[2].value.as < std::string > (), yystack_[1].value.as < std::string > ()));
        yylhs.value.as < std::vector<std::shared_ptr<VarDeclaration>> > () = yystack_[0].value.as < std::vector<std::shared_ptr<VarDeclaration>> > (); }
#line 1082 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 17:
#line 290 "parser.y"
             { yylhs.value.as < std::vector<std::shared_ptr<VarDeclaration>> > () = std::vector<std::shared_ptr<VarDeclaration>>(); }
#line 1088 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 18:
#line 291 "parser.y"
               { yylhs.value.as < std::vector<std::shared_ptr<VarDeclaration>> > ().push_back(yystack_[0].value.as < std::shared_ptr<VarDeclaration> > ()); }
#line 1094 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 19:
#line 292 "parser.y"
                             { yystack_[2].value.as < std::vector<std::shared_ptr<VarDeclaration>> > ().push_back(yystack_[0].value.as < std::shared_ptr<VarDeclaration> > ()); yylhs.value.as < std::vector<std::shared_ptr<VarDeclaration>> > () = yystack_[2].value.as < std::vector<std::shared_ptr<VarDeclaration>> > (); }
#line 1100 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 20:
#line 295 "parser.y"
                        { yylhs.value.as < std::shared_ptr<VarDeclaration> > () = std::make_shared<VarDeclaration>(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1106 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 21:
#line 298 "parser.y"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1112 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 22:
#line 299 "parser.y"
                 { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1118 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 23:
#line 302 "parser.y"
            { yylhs.value.as < std::string > () = "int"; }
#line 1124 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 24:
#line 303 "parser.y"
                { yylhs.value.as < std::string > () = "boolean"; }
#line 1130 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 25:
#line 304 "parser.y"
             { yylhs.value.as < std::string > () = "void"; }
#line 1136 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 26:
#line 305 "parser.y"
                      { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1142 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 27:
#line 308 "parser.y"
                          { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > (); }
#line 1148 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 28:
#line 311 "parser.y"
                   { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1154 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 29:
#line 314 "parser.y"
             { yylhs.value.as < std::vector<std::shared_ptr<Statement>> > () = std::vector<std::shared_ptr<Statement>>(); }
#line 1160 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 30:
#line 315 "parser.y"
                           { yystack_[1].value.as < std::vector<std::shared_ptr<Statement>> > ().push_back(yystack_[0].value.as < std::shared_ptr<Statement> > ()); yylhs.value.as < std::vector<std::shared_ptr<Statement>> > () = yystack_[1].value.as < std::vector<std::shared_ptr<Statement>> > (); }
#line 1166 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 31:
#line 318 "parser.y"
                                { yylhs.value.as < std::shared_ptr<Statement> > () =  std::make_shared<AssertStatement>(yystack_[2].value.as < std::shared_ptr<Expression> > ()); }
#line 1172 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 32:
#line 319 "parser.y"
                                 { yylhs.value.as < std::shared_ptr<Statement> > () = yystack_[0].value.as < std::shared_ptr<Statement> > (); }
#line 1178 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 33:
#line 320 "parser.y"
                          { yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<BracesStatement>(yystack_[1].value.as < std::vector<std::shared_ptr<Statement>> > ()); }
#line 1184 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 34:
#line 321 "parser.y"
                                  { yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<IfStatement>(yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Statement> > ()); }
#line 1190 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 35:
#line 322 "parser.y"
                                                   { yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<IfElseStatement>(yystack_[4].value.as < std::shared_ptr<Expression> > (), yystack_[2].value.as < std::shared_ptr<Statement> > (), yystack_[0].value.as < std::shared_ptr<Statement> > ()); }
#line 1196 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 36:
#line 323 "parser.y"
                                     { yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<WhileStatement>(yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Statement> > ()); }
#line 1202 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 37:
#line 324 "parser.y"
                                            { yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<SOPrintlnStatement>(yystack_[2].value.as < std::shared_ptr<Expression> > ()); }
#line 1208 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 38:
#line 325 "parser.y"
                          { yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<LValueAssignStatement>(yystack_[3].value.as < std::shared_ptr<LValue> > (), yystack_[1].value.as < std::shared_ptr<Expression> > ()); }
#line 1214 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 39:
#line 326 "parser.y"
                        { yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<ReturnStatement>(yystack_[1].value.as < std::shared_ptr<Expression> > ()); }
#line 1220 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 40:
#line 327 "parser.y"
                            { yylhs.value.as < std::shared_ptr<Statement> > () = yystack_[1].value.as < std::shared_ptr<MethodInvExpression> > (); }
#line 1226 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 41:
#line 330 "parser.y"
                         {
        auto vd = static_cast<VarDeclaration*>(yystack_[0].value.as < std::shared_ptr<Declaration> > ().get());
        yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<LocVarDecStatement>(vd->type, vd->identifier);
    }
#line 1235 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 42:
#line 336 "parser.y"
                                    { yylhs.value.as < std::shared_ptr<MethodInvExpression> > () = std::make_shared<MethodInvExpression>
          (yystack_[4].value.as < std::shared_ptr<Expression> > (), yystack_[2].value.as < std::string > (), std::vector<std::shared_ptr<Expression>>()); }
#line 1242 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 43:
#line 338 "parser.y"
                                                {
          yylhs.value.as < std::shared_ptr<MethodInvExpression> > () = std::make_shared<MethodInvExpression>(yystack_[5].value.as < std::shared_ptr<Expression> > (), yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<std::shared_ptr<Expression>> > ()); }
#line 1249 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 44:
#line 342 "parser.y"
                   { yylhs.value.as < std::shared_ptr<LValue> > () = std::make_shared<SimpleTypeIdentifier>(yystack_[0].value.as < std::string > ()); }
#line 1255 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 45:
#line 344 "parser.y"
      { yylhs.value.as < std::shared_ptr<LValue> > () = std::make_shared<ArrayIdentifier>(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::shared_ptr<Expression> > ()); }
#line 1261 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 46:
#line 347 "parser.y"
             { yylhs.value.as < std::vector<std::shared_ptr<Expression>> > () = std::vector<std::shared_ptr<Expression>>(); }
#line 1267 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 47:
#line 348 "parser.y"
           { yylhs.value.as < std::vector<std::shared_ptr<Expression>> > ().push_back(yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1273 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 48:
#line 349 "parser.y"
                           { yystack_[2].value.as < std::vector<std::shared_ptr<Expression>> > ().push_back(yystack_[0].value.as < std::shared_ptr<Expression> > ()); yylhs.value.as < std::vector<std::shared_ptr<Expression>> > () = yystack_[2].value.as < std::vector<std::shared_ptr<Expression>> > (); }
#line 1279 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 49:
#line 352 "parser.y"
                     { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<AndExpression>(yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1285 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 50:
#line 353 "parser.y"
                     { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<OrExpression>(yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1291 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 51:
#line 354 "parser.y"
                    { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<LessExpression>(yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1297 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 52:
#line 355 "parser.y"
                    { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<GreaterExpression>(yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1303 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 53:
#line 356 "parser.y"
                     { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<IsEqualExpression>(yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1309 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 54:
#line 357 "parser.y"
                    { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<AddExpression>(yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1315 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 55:
#line 358 "parser.y"
                    { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<SubExpression>(yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1321 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 56:
#line 359 "parser.y"
                    { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<MulExpression>(yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1327 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 57:
#line 360 "parser.y"
                    { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<DivExpression>(yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1333 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 58:
#line 361 "parser.y"
                    { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<ResidueExpression>(yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1339 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 59:
#line 362 "parser.y"
                         { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<AccessExpression>(yystack_[3].value.as < std::shared_ptr<Expression> > (), yystack_[1].value.as < std::shared_ptr<Expression> > ()); }
#line 1345 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 60:
#line 363 "parser.y"
                         { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<LengthExpression>(yystack_[2].value.as < std::shared_ptr<Expression> > ()); }
#line 1351 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 61:
#line 364 "parser.y"
                                     { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<NewArrayExpression>(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::shared_ptr<Expression> > ()); }
#line 1357 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 62:
#line 365 "parser.y"
                                    { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<NewExpression>(yystack_[2].value.as < std::string > ()); }
#line 1363 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 63:
#line 366 "parser.y"
               { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<NegativeExpression>(yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1369 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 64:
#line 367 "parser.y"
                    { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<ParensExpression>(yystack_[1].value.as < std::shared_ptr<Expression> > ()); }
#line 1375 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 65:
#line 368 "parser.y"
                   { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<IdentifierExpression>(yystack_[0].value.as < std::string > ()); }
#line 1381 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 66:
#line 369 "parser.y"
              { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<IntegerExpression>(yystack_[0].value.as < int > ()); }
#line 1387 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 67:
#line 370 "parser.y"
             { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<ThisExpression>(); }
#line 1393 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 68:
#line 371 "parser.y"
            { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<LogicExpression>(yystack_[0].value.as < std::string > ()); }
#line 1399 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 69:
#line 372 "parser.y"
                        { yylhs.value.as < std::shared_ptr<Expression> > () = yystack_[0].value.as < std::shared_ptr<MethodInvExpression> > (); }
#line 1405 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 70:
#line 375 "parser.y"
             { yylhs.value.as < std::string > () = "true"; }
#line 1411 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 71:
#line 376 "parser.y"
              { yylhs.value.as < std::string > () = "false"; }
#line 1417 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 72:
#line 379 "parser.y"
               { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 1423 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;

  case 73:
#line 380 "parser.y"
                   { yylhs.value.as < int > () = -yystack_[0].value.as < int > (); }
#line 1429 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"
    break;


#line 1433 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"

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
      YY_STACK_PRINT ();

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
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
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
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

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
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
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

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -68;

  const signed char parser::yytable_ninf_ = -45;

  const short
  parser::yypact_[] =
  {
     -23,   -36,     9,   -68,   -68,    -4,   -68,   -17,   -13,    -3,
     -68,    -8,    -6,    12,   -68,     3,    15,   -14,    32,    35,
     -68,    78,   -68,   -68,   -68,   -68,   -68,   -68,   -68,     7,
      33,   -68,   -68,   -68,    37,    11,    55,    61,     2,    65,
      68,   -68,   -68,   -68,   -68,    -1,   109,    69,    75,    41,
      49,   264,   -68,    77,   264,   -68,   -68,   -68,    81,    78,
      82,    90,    92,   264,    -5,   -68,   -68,   -68,   -68,    91,
     105,   496,   -68,   -68,   -68,   106,    78,   -68,   -68,   -68,
     306,   140,   -68,   496,   264,   110,   113,   264,   264,   264,
     325,   264,   -68,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   -18,   171,   -68,    88,   -68,
      86,   -68,   -68,   344,   264,   120,   363,   382,   401,   -68,
     420,   439,   496,   496,   496,   496,   496,   507,   507,    97,
      97,   496,   458,   -68,   123,   -68,   202,    78,   -68,   118,
     477,   -68,   119,   233,   233,   -68,   -68,   -68,    64,   -68,
     -68,   -68,   -68,   -68,   103,   -68,   -68,    -9,   496,   233,
     -68,   264,   -68,   496
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     5,     0,     1,     3,     0,     0,
       6,     0,     0,     0,     9,     0,     0,     0,     0,     0,
       7,     0,    25,    23,    24,    28,    10,    12,    11,     0,
      21,    22,    26,     9,     0,     0,     0,     0,     0,     0,
       0,    15,    27,     8,    29,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,    67,    70,    71,     0,     0,
       0,     0,     0,     0,    65,    72,    41,    30,    32,    69,
       0,     0,    66,    68,    29,     0,    17,    73,    65,    69,
       0,     0,     4,    63,     0,     0,    26,     0,     0,     0,
       0,     0,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    16,    18,
       0,    64,    33,     0,     0,     0,     0,     0,     0,    39,
       0,     0,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,     0,    60,     0,    13,     0,     0,    20,     0,
       0,    62,     0,     0,     0,    45,    38,    59,    46,    14,
      19,    37,    61,    31,    34,    36,    42,     0,    47,     0,
      43,     0,    35,    48
  };

  const signed char
  parser::yypgoto_[] =
  {
     -68,   -68,   -68,   -68,   -68,   -68,   112,   -68,   -68,     1,
     -68,   -68,    10,   -21,    96,   -68,    99,   -48,   -67,   -68,
     -45,   -68,   -68,   -31,   -68,   -68
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,     7,    10,    17,    26,    27,    66,
      48,   108,   109,    29,    30,    31,    32,    46,    67,    68,
      79,    70,   157,    71,    72,    73
  };

  const short
  parser::yytable_[] =
  {
      35,    69,   -44,    20,    81,     1,   160,     5,   133,     6,
      14,     9,     8,    91,    47,    21,    11,    22,    28,    43,
      80,    23,    13,    83,    49,   134,   106,   161,    24,    25,
      22,    21,    90,    22,    23,    15,    69,    23,   -28,    28,
      12,    24,    25,    16,    24,    25,    18,    19,    33,    34,
      36,    37,    39,   113,    40,   110,   116,   117,   118,   136,
     120,    69,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    50,    41,   154,   155,    51,   156,
      42,    44,    45,   140,    76,    74,    54,    55,    56,    57,
      75,    69,   162,    77,    82,    84,    87,    59,    69,    69,
      94,    95,    96,    97,    88,    98,    89,    78,    65,    22,
     103,    92,    93,    23,    69,   104,   110,   158,   105,    50,
      24,    25,   107,    51,   137,    52,    53,   115,   114,   138,
     163,    54,    55,    56,    57,   141,    58,   148,   151,   153,
      22,   159,    59,    60,    23,    38,    61,   150,    62,    63,
      50,    24,    64,    65,    51,    85,    52,   112,    86,     0,
       0,     0,    54,    55,    56,    57,     0,    58,     0,     0,
       0,    22,     0,    59,    60,    23,     0,    61,     0,    62,
      63,    50,    24,    64,    65,    51,     0,    52,   135,     0,
       0,     0,     0,    54,    55,    56,    57,     0,    58,     0,
       0,     0,    22,     0,    59,    60,    23,     0,    61,     0,
      62,    63,    50,    24,    64,    65,    51,     0,    52,   149,
       0,     0,     0,     0,    54,    55,    56,    57,     0,    58,
       0,     0,     0,    22,     0,    59,    60,    23,     0,    61,
       0,    62,    63,    50,    24,    64,    65,    51,     0,    52,
       0,     0,     0,     0,     0,    54,    55,    56,    57,     0,
      58,     0,     0,     0,    22,     0,    59,    60,    23,     0,
      61,     0,    62,    63,    50,    24,    64,    65,    51,     0,
       0,     0,     0,     0,     0,     0,    54,    55,    56,    57,
       0,     0,     0,     0,     0,     0,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,    65,    94,
      95,    96,    97,     0,    98,    99,   100,   101,   102,   103,
       0,   111,     0,     0,   104,     0,     0,   105,    94,    95,
      96,    97,     0,    98,    99,   100,   101,   102,   103,     0,
       0,     0,     0,   104,     0,   119,   105,    94,    95,    96,
      97,     0,    98,    99,   100,   101,   102,   103,     0,   139,
       0,     0,   104,     0,     0,   105,    94,    95,    96,    97,
       0,    98,    99,   100,   101,   102,   103,     0,   142,     0,
       0,   104,     0,     0,   105,    94,    95,    96,    97,     0,
      98,    99,   100,   101,   102,   103,     0,   143,     0,     0,
     104,     0,     0,   105,    94,    95,    96,    97,     0,    98,
      99,   100,   101,   102,   103,     0,   144,     0,     0,   104,
       0,     0,   105,    94,    95,    96,    97,     0,    98,    99,
     100,   101,   102,   103,     0,     0,     0,     0,   104,   145,
       0,   105,    94,    95,    96,    97,     0,    98,    99,   100,
     101,   102,   103,     0,     0,     0,     0,   104,     0,   146,
     105,    94,    95,    96,    97,     0,    98,    99,   100,   101,
     102,   103,     0,     0,     0,     0,   104,   147,     0,   105,
      94,    95,    96,    97,     0,    98,    99,   100,   101,   102,
     103,     0,     0,     0,     0,   104,   152,     0,   105,    94,
      95,    96,    97,     0,    98,    99,   100,   101,   102,   103,
      94,    95,    96,    97,   104,    98,     0,   105,   101,   102,
     103,     0,     0,     0,     0,   104,     0,     0,   105
  };

  const short
  parser::yycheck_[] =
  {
      21,    46,     7,    17,    52,    28,    15,    43,    26,     0,
      16,    28,    16,    18,    15,    29,    29,    31,    17,    17,
      51,    35,    30,    54,    45,    43,    74,    36,    42,    43,
      31,    29,    63,    31,    35,    41,    81,    35,    43,    38,
      43,    42,    43,    31,    42,    43,    43,    32,    16,    14,
      43,    18,    15,    84,    43,    76,    87,    88,    89,   107,
      91,   106,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    10,    20,   143,   144,    14,    15,
      19,    16,    14,   114,    43,    16,    22,    23,    24,    25,
      15,   136,   159,    44,    17,    14,    14,    33,   143,   144,
       3,     4,     5,     6,    14,     8,    14,    43,    44,    31,
      13,    20,     7,    35,   159,    18,   137,   148,    21,    10,
      42,    43,    16,    14,    36,    16,    17,    14,    18,    43,
     161,    22,    23,    24,    25,    15,    27,    14,    20,    20,
      31,    38,    33,    34,    35,    33,    37,   137,    39,    40,
      10,    42,    43,    44,    14,    59,    16,    17,    59,    -1,
      -1,    -1,    22,    23,    24,    25,    -1,    27,    -1,    -1,
      -1,    31,    -1,    33,    34,    35,    -1,    37,    -1,    39,
      40,    10,    42,    43,    44,    14,    -1,    16,    17,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    -1,    27,    -1,
      -1,    -1,    31,    -1,    33,    34,    35,    -1,    37,    -1,
      39,    40,    10,    42,    43,    44,    14,    -1,    16,    17,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    -1,    27,
      -1,    -1,    -1,    31,    -1,    33,    34,    35,    -1,    37,
      -1,    39,    40,    10,    42,    43,    44,    14,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    -1,
      27,    -1,    -1,    -1,    31,    -1,    33,    34,    35,    -1,
      37,    -1,    39,    40,    10,    42,    43,    44,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    12,    13,
      -1,    15,    -1,    -1,    18,    -1,    -1,    21,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    18,    -1,    20,    21,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    12,    13,    -1,    15,
      -1,    -1,    18,    -1,    -1,    21,     3,     4,     5,     6,
      -1,     8,     9,    10,    11,    12,    13,    -1,    15,    -1,
      -1,    18,    -1,    -1,    21,     3,     4,     5,     6,    -1,
       8,     9,    10,    11,    12,    13,    -1,    15,    -1,    -1,
      18,    -1,    -1,    21,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    12,    13,    -1,    15,    -1,    -1,    18,
      -1,    -1,    21,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,    19,
      -1,    21,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    18,    -1,    20,
      21,     3,     4,     5,     6,    -1,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    18,    19,    -1,    21,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    -1,    18,    19,    -1,    21,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    12,    13,
       3,     4,     5,     6,    18,     8,    -1,    21,    11,    12,
      13,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21
  };

  const signed char
  parser::yystos_[] =
  {
       0,    28,    46,    47,    48,    43,     0,    49,    16,    28,
      50,    29,    43,    30,    16,    41,    31,    51,    43,    32,
      17,    29,    31,    35,    42,    43,    52,    53,    54,    58,
      59,    60,    61,    16,    14,    58,    43,    18,    51,    15,
      43,    20,    19,    17,    16,    14,    62,    15,    55,    58,
      10,    14,    16,    17,    22,    23,    24,    25,    27,    33,
      34,    37,    39,    40,    43,    44,    54,    63,    64,    65,
      66,    68,    69,    70,    16,    15,    43,    44,    43,    65,
      68,    62,    17,    68,    14,    59,    61,    14,    14,    14,
      68,    18,    20,     7,     3,     4,     5,     6,     8,     9,
      10,    11,    12,    13,    18,    21,    62,    16,    56,    57,
      58,    15,    17,    68,    18,    14,    68,    68,    68,    20,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    26,    43,    17,    62,    36,    43,    15,
      68,    15,    15,    15,    15,    19,    20,    19,    14,    17,
      57,    20,    19,    20,    63,    63,    15,    67,    68,    38,
      15,    36,    63,    68
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    45,    46,    47,    48,    49,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    54,    55,    56,    56,    56,
      57,    58,    58,    59,    59,    59,    59,    60,    61,    62,
      62,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    64,    65,    65,    66,    66,    67,    67,    67,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      70,    70,    69,    69
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,    13,     0,     2,     5,     7,     0,
       2,     1,     1,     8,     9,     3,     3,     0,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     3,     1,     0,
       2,     5,     1,     3,     5,     7,     5,     5,     4,     3,
       2,     1,     5,     6,     1,     4,     0,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     5,     4,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"&&\"", "\"||\"", "\"<\"",
  "\">\"", "\"=\"", "\"==\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"%\"",
  "\"(\"", "\")\"", "\"{\"", "\"}\"", "\"[\"", "\"]\"", "\";\"", "\".\"",
  "\"!\"", "\"this\"", "\"true\"", "\"false\"", "\"length\"",
  "\"System.out.println\"", "\"class\"", "\"public\"", "\"static\"",
  "\"void\"", "\"main\"", "\"new\"", "\"assert\"", "\"int\"", "\",\"",
  "\"if\"", "\"else\"", "\"while\"", "\"return\"", "\"extends\"",
  "\"boolean\"", "\"identifier\"", "\"number\"", "$accept", "unit",
  "program", "main_class", "class_declarations", "class_declaration",
  "declarations", "declaration", "method_declaration",
  "variable_declaration", "formals", "arguments", "argument", "type",
  "simple_type", "array_type", "type_identifier", "statements",
  "statement", "local_variable_declaration", "method_invocation", "lvalue",
  "expressions", "expr", "integer", "logic", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   236,   236,   239,   242,   249,   250,   253,   256,   261,
     262,   265,   266,   269,   276,   282,   285,   290,   291,   292,
     295,   298,   299,   302,   303,   304,   305,   308,   311,   314,
     315,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   330,   336,   338,   342,   343,   347,   348,   349,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     375,   376,   379,   380
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
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


} // yy
#line 2000 "/home/theneonlightning/compilers/Mini-Java-Compiler/AbstractSyntaxTree/04-visitors/parser.cpp"

#line 382 "parser.y"


void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
