%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    class Scanner;
    class Driver;
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0 "end of file"

    AND "&&"
    OR "||"
    LESS "<"
    GREATER ">"
    ASSIGN "="
    ISEQUAL "=="
    PLUS "+"
    MINUS "-"
    STAR "*"
    SLASH "/"
    RESIDUE "%"

    LPAREN "("
    RPAREN ")"
    LBRACE "{"
    RBRACE "}"
    LBRACKET "["
    RBRACKET "]"

    SEMICOLON ";"
    DOT "."
    EXCLAMATION "!"

    THIS "this"
    TRUE "true"
    FALSE "false"
    LENGTH "length"
    SOPRINTLN "System.out.println"
    CLASS "class"
    PUBLIC "public"
    STATIC "static"
    VOID "void"
    MAIN "main"
    NEW "new"
    ASSERT "assert"
    INT "int"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"


%printer { yyo << $$; } <*>;

%type<int> exp
%type<int> program


%%

%start unit;
unit: program { driver.result = $1; }

program:
    main_class

main_class:
    "class" "identifier" "{"
        "public" "static" "void" "main" "(" ")" "{"
            statements
        "}"
    "}"

statements:
      %empty {}
    | statement statements {}

statement:
      "assert" "(" exp ")" ";" { assert($3); }
    | variable_declaration ";" {}
    | "{" statements "}" {}
    | "System.out.println" "(" exp ")" ";" { std::cout << $3 << std::endl; }
    | "identifier" "=" exp ";" { driver.variables[$1] = $3; }
    | "identifier" "[" exp "]" "=" exp ";" { driver.array_variables[$1][$3] = $6; }
    | "identifier" "=" "new" "int" "[" exp "]" ";" { driver.array_variables[$1] = std::vector<int>($6); }

variable_declaration:
      simple_type
    | array_type

simple_type:
    "int" "identifier" { driver.variables[$2] = 0; }

array_type:
    "int" "[" "]" "identifier" { driver.array_variables[$4] = std::vector<int>(1); }

exp:
      exp "&&" exp { $$ = $1 && $3; }
    | exp "||" exp { $$ = $1 || $3; }
    | exp "<" exp { $$ = $1 < $3; }
    | exp ">" exp { $$ = $1 > $3; }
    | exp "==" exp { $$ = $1 == $3; }
    | exp "+" exp { $$ = $1 + $3; }
    | exp "-" exp { $$ = $1 - $3; }
    | exp "*" exp { $$ = $1 * $3; }
    | exp "/" exp { $$ = $1 / $3; }
    | exp "%" exp { $$ = $1 % $3; }
    | "identifier" "[" exp "]" { $$ = driver.array_variables[$1][$3]; }
    | "identifier" "." "length" { $$ = driver.array_variables[$1].size(); }
    | "!" exp { $$ = !$2; }
    | "(" exp ")" { $$ = $2; }
    | "number"
    | "identifier" { $$ = driver.variables[$1]; }

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}


