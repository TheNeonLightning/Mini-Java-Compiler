%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    #include <memory>
    #include <vector>

    class Scanner;
    class Driver;

    class Program;

    class MainClass;

    class Declaration;
        class ClassDeclaration;
        class MethodDeclaration;
        class VarDeclaration;

    class SimpleType;

    class ArrayType;

    class TypeIdentifier;


    class Statement;
        class AssertStatement;
        class LocVarDeclStatement;
        class BracesStatement;
        class IfStatement;
        class IfElseStatement;
        class WhileStatement;
        class SOPrintlnStatement;
        class LValueAssignStatement;
        class ReturnStatement;
        class MethodInvStatement;

    class Expression;
        class AndExpression;
        class OrExpression;
        class LessExpression;
        class GreaterExpression;
        class IsEqualExpression;
        class AddExpression;
        class SubExpression;
        class MulExpression;
        class DivExpression;
        class ResidueExpression;
        class AccessExpression;
        class LengthExpression;
        class NewArrayExpression;
        class NewExpression;
        class NegativeExpression;
        class ParensExpression;
        class IdentifierExpression;
        class IntegerExpression;
        class ThisExpression;
        class LogicExpression;
        class MethodInvExpression;

    class LValue;
        class SimpleTypeIdentifier;
        class ArrayIdentifier;

}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
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

    COLON ","
    IF "if"
    ELSE "else"
    WHILE "while"
    RETURN "return"
    EXTENDS "extends"
    BOOLEAN "boolean"

;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"

%nterm <std::shared_ptr<Program>> unit
%nterm <std::shared_ptr<Program>> program
%nterm <std::shared_ptr<MainClass>> main_class
%nterm <std::vector<std::shared_ptr<ClassDeclaration>>> class_declarations
%nterm <std::shared_ptr<ClassDeclaration>> class_declaration
%nterm <std::vector<std::shared_ptr<Declaration>>> declarations
%nterm <std::shared_ptr<Declaration>> declaration
%nterm <std::shared_ptr<Declaration>> method_declaration
%nterm <std::shared_ptr<Declaration>> variable_declaration
%nterm <std::vector<std::shared_ptr<VarDeclaration>>> formals
%nterm <std::vector<std::shared_ptr<VarDeclaration>>> arguments
%nterm <std::shared_ptr<VarDeclaration>> argument
%nterm <std::string> type
%nterm <std::string> simple_type
%nterm <std::string> array_type
%nterm <std::string> type_identifier
%nterm <std::vector<std::shared_ptr<Statement>>> statements
%nterm <std::shared_ptr<Statement>> statement
%nterm <std::shared_ptr<Statement>> local_variable_declaration
%nterm <std::shared_ptr<MethodInvExpression>> method_invocation
%nterm <std::shared_ptr<LValue>> lvalue
%nterm <std::vector<std::shared_ptr<Expression>>> expressions
%nterm <std::shared_ptr<Expression>> expr
%nterm <int> integer
%nterm <std::string> logic

// %printer { yyo << $$; } <*>;

%left "+" "-";
%left "*" "/";
%precedence ".";
%precedence ")";
%precedence "else";

%%

%start unit;

unit: program { $$ = $1; driver.program = $1; }

program:
    main_class class_declarations { $$ = std::make_shared<Program>($1, $2); }

main_class:
    "class" "identifier" "{"
        "public" "static" "void" "main" "(" ")" "{"
            statements
        "}"
    "}" { $$ = std::make_shared<MainClass>($2, $11); }

class_declarations:
      %empty { $$ = std::vector<std::shared_ptr<ClassDeclaration>>(); }
    | class_declarations class_declaration { $1.push_back($2); $$ = $1; }

class_declaration:
      "class" "identifier" "{"
          declarations
      "}" { $$ = std::make_shared<ClassDeclaration>($2, "", $4); }
    | "class" "identifier" "extends" "identifier" "{"
          declarations
      "}" { $$ = std::make_shared<ClassDeclaration>($2, $4, $6); }

declarations:
      %empty { $$ = std::vector<std::shared_ptr<Declaration>>(); }
    | declarations declaration { $1.push_back($2); $$ = $1; }

declaration:
      variable_declaration { $$ = $1; }
    | method_declaration { $$ = $1; }

method_declaration:
      "public" type "identifier" "(" ")" "{"
           statements
      "}"

      { $$ = std::make_shared<MethodDeclaration>
       ($2, $3, std::vector<std::shared_ptr<VarDeclaration>>(), $7); }

    | "public" type "identifier" "(" formals ")" "{"
          statements
      "}"
      { $$ = std::make_shared<MethodDeclaration>($2, $3, $5, $8); }

variable_declaration:
      type "identifier" ";" { $$ = std::make_shared<VarDeclaration>($1, $2); }

formals:
      type "identifier" arguments
      { $3.insert($3.begin(), std::make_shared<VarDeclaration>($1, $2));
        $$ = $3; }

arguments:
      %empty { $$ = std::vector<std::shared_ptr<VarDeclaration>>(); }
    | argument { $$.push_back($1); }
    | arguments "," argument { $1.push_back($3); $$ = $1; }

argument:
      type "identifier" { $$ = std::make_shared<VarDeclaration>($1, $2); }

type:
      simple_type { $$ = $1; }
    | array_type { $$ = $1; }

simple_type:
      "int" { $$ = "int"; }
    | "boolean" { $$ = "boolean"; }
    | "void" { $$ = "void"; }
    | type_identifier { $$ = $1; }

array_type:
      simple_type "[" "]" { $$ = $1; }

type_identifier:
      "identifier" { $$ = $1; }

statements:
      %empty { $$ = std::vector<std::shared_ptr<Statement>>(); }
    | statements statement { $1.push_back($2); $$ = $1; }

statement:
      "assert" "(" expr ")" ";" { $$ =  std::make_shared<AssertStatement>($3); }
    | local_variable_declaration { $$ = $1; }
    | "{" statements "}"  { $$ = std::make_shared<BracesStatement>($2); }
    | "if" "(" expr ")" statement { $$ = std::make_shared<IfStatement>($3, $5); }
    | "if" "(" expr ")" statement "else" statement { $$ = std::make_shared<IfElseStatement>($3, $5, $7); }
    | "while" "(" expr ")" statement { $$ = std::make_shared<WhileStatement>($3, $5); }
    | "System.out.println" "(" expr ")" ";" { $$ = std::make_shared<SOPrintlnStatement>($3); }
    | lvalue "=" expr ";" { $$ = std::make_shared<LValueAssignStatement>($1, $3); }
    | "return" expr ";" { $$ = std::make_shared<ReturnStatement>($2); }
    | method_invocation ";" { $$ = $1; }

local_variable_declaration:
    variable_declaration {
        auto vd = static_cast<VarDeclaration*>($1.get());
        $$ = std::make_shared<LocVarDecStatement>(vd->type, vd->identifier);
    }

method_invocation:
      expr "." "identifier" "(" ")" { $$ = std::make_shared<MethodInvExpression>
          ($1, $3, std::vector<std::shared_ptr<Expression>>()); }
    | expr "." "identifier" "(" expressions ")" {
          $$ = std::make_shared<MethodInvExpression>($1, $3, $5); }

lvalue:
      "identifier" { $$ = std::make_shared<SimpleTypeIdentifier>($1); }
    | "identifier" "[" expr "]"
      { $$ = std::make_shared<ArrayIdentifier>($1, $3); }

expressions:
      %empty { $$ = std::vector<std::shared_ptr<Expression>>(); }
    | expr { $$.push_back($1); }
    | expressions "," expr { $1.push_back($3); $$ = $1; }

expr:
      expr "&&" expr { $$ = std::make_shared<AndExpression>($1, $3); }
    | expr "||" expr { $$ = std::make_shared<OrExpression>($1, $3); }
    | expr "<" expr { $$ = std::make_shared<LessExpression>($1, $3); }
    | expr ">" expr { $$ = std::make_shared<GreaterExpression>($1, $3); }
    | expr "==" expr { $$ = std::make_shared<IsEqualExpression>($1, $3); }
    | expr "+" expr { $$ = std::make_shared<AddExpression>($1, $3); }
    | expr "-" expr { $$ = std::make_shared<SubExpression>($1, $3); }
    | expr "*" expr { $$ = std::make_shared<MulExpression>($1, $3); }
    | expr "/" expr { $$ = std::make_shared<DivExpression>($1, $3); }
    | expr "%" expr { $$ = std::make_shared<ResidueExpression>($1, $3); }
    | expr "[" expr "]"  { $$ = std::make_shared<AccessExpression>($1, $3); }
    | expr "." "length"  { $$ = std::make_shared<LengthExpression>($1); }
    | "new" simple_type "[" expr "]" { $$ = std::make_shared<NewArrayExpression>($2, $4); }
    | "new" type_identifier "(" ")" { $$ = std::make_shared<NewExpression>($2); }
    | "!" expr { $$ = std::make_shared<NegativeExpression>($2); }
    | "(" expr ")"  { $$ = std::make_shared<ParensExpression>($2); }
    | "identifier" { $$ = std::make_shared<IdentifierExpression>($1); }
    | integer { $$ = std::make_shared<IntegerExpression>($1); }
    | "this" { $$ = std::make_shared<ThisExpression>(); }
    | logic { $$ = std::make_shared<LogicExpression>($1); }
    | method_invocation { $$ = $1; }

logic:
      "true" { $$ = "true"; }
    | "false" { $$ = "false"; }

integer:
      "number" { $$ = $1; }
    | "-" "number" { $$ = -$2; }

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
