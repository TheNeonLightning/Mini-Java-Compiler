//
// Created by theneonlightning on 20.05.2020.
//

#include "Interpreter.h"
#include <iostream>
#include <string>
#include "elements.h"

const std::string deferred_execution =
    "Program contains section that needs deferred execution: --> ";

Interpreter::Interpreter(): variable_identifiers(std::set<std::string>()),
      variables(std::map<std::string, int>()),
      array_variables(std::map<std::string, std::vector<int>>()) {}

///program//////////////////////////////////////////////////////////////////////

void Interpreter::Visit(Program *program) {
  program->main_class->Accept(this);
}

///main_class///////////////////////////////////////////////////////////////////

void Interpreter::Visit(MainClass* main_class) {
  for (auto statement : main_class->statements) {
    statement->Accept(this);
  }
}

///declarations/////////////////////////////////////////////////////////////////

void Interpreter::Visit(VarDeclaration* declaration) {
  variable_identifiers.emplace(declaration->identifier);
}

///lvalue///////////////////////////////////////////////////////////////////////

void Interpreter::Visit(ArrayIdentifier* identifier) {

  identifier->expr->Accept(this);

  active_variable_identifier = identifier->identifier;
  active_variable_index = expr_result;
  expr_result = 0;
}

void Interpreter::Visit(SimpleTypeIdentifier* identifier) {
  active_variable_identifier = identifier->identifier;
  active_variable_index = -1;
  expr_result = 0;
}

///statements///////////////////////////////////////////////////////////////////

void Interpreter::Visit(AssertStatement* statement) {

  statement->expr->Accept(this);

  if (!expr_result) {
    std::cout << "Assertion Failed" << std::endl;
    exit(1);
  }

  expr_result = 0;
}

void Interpreter::Visit(BracesStatement* statement) {
  for (size_t i = 0; i < statement->statements.size(); ++i) {
    statement->statements[i]->Accept(this);
  }
}

void Interpreter::Visit(IfElseStatement* statement) {
  statement->expr->Accept(this);
  if (expr_result) {
    statement->statement_true->Accept(this);
  } else {
    statement->statement_false->Accept(this);
  }
}

void Interpreter::Visit(IfStatement* statement) {
  statement->expr->Accept(this);
  if (expr_result) {
    statement->statement->Accept(this);
  }
}

void Interpreter::Visit(LocVarDecStatement* statement) {
  variable_identifiers.emplace(statement->identifier);
}

void Interpreter::Visit(LValueAssignStatement* statement) {

  statement->lvalue->Accept(this);
  std::string lvalue_identifier = active_variable_identifier;
  int lvalue_index = active_variable_index;

  statement->expr->Accept(this);

  if (lvalue_index != -1) {
    array_variables[lvalue_identifier][lvalue_index] = expr_result;
  }

  if (expr_with_new) {
    array_variables[lvalue_identifier] = std::vector<int>(expr_result);
  } else {
    variables[lvalue_identifier] = expr_result;
  }

  expr_with_new = false;
}

void Interpreter::Visit(ReturnStatement* statement) {

  statement->expr->Accept(this);

  std::cout << expr_result << std::endl;
  exit(0);
}

void Interpreter::Visit(SOPrintlnStatement* statement) {

  statement->expr->Accept(this);

  std::cout << expr_result << std::endl;
}

void Interpreter::Visit(WhileStatement* statement) {

  while (expr_result) {
    statement->statement->Accept(this);
    statement->expr->Accept(this);
  }
}

///expressions//////////////////////////////////////////////////////////////////

void Interpreter::Visit(AccessExpression* expression) {

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);

  if (array_variables.find(active_variable_identifier) ==
      array_variables.end()) {

    std::cout << "Undeclared variable" << std::endl;
    exit(1);
  }

  expr_result = (array_variables[active_variable_identifier][expr_result]);
}

void Interpreter::Visit(AndExpression* expression) {
  expression->lhv->Accept(this);
  int left_expr = expr_result;

  expression->rhv->Accept(this);
  int right_expr = expr_result;

  expr_result = (left_expr && right_expr);
}

void Interpreter::Visit(GreaterExpression* expression) {
  expression->lhv->Accept(this);
  int left_expr = expr_result;

  expression->rhv->Accept(this);
  int right_expr = expr_result;

  expr_result = (left_expr > right_expr);
}

void Interpreter::Visit(IdentifierExpression* expression) {
  active_variable_identifier = expression->ident_name;
  expr_result = (variables[expression->ident_name]);
}

void Interpreter::Visit(IntegerExpression* expression) {
  expr_result = (expression->value);
}

void Interpreter::Visit(IsEqualExpression* expression) {
  expression->lhv->Accept(this);
  int left_expr = expr_result;

  expression->rhv->Accept(this);
  int right_expr = expr_result;

  expr_result = (left_expr == right_expr);
}

void Interpreter::Visit(AddExpression* expression) {
  expression->lhv->Accept(this);
  int left_expr = expr_result;

  expression->rhv->Accept(this);
  int right_expr = expr_result;

  expr_result = (left_expr + right_expr);
}

void Interpreter::Visit(SubExpression* expression) {
  expression->lhv->Accept(this);
  int left_expr = expr_result;

  expression->rhv->Accept(this);
  int right_expr = expr_result;

  expr_result = (left_expr - right_expr);
}

void Interpreter::Visit(MulExpression* expression) {
  expression->lhv->Accept(this);
  int left_expr = expr_result;

  expression->rhv->Accept(this);
  int right_expr = expr_result;

  expr_result = (left_expr * right_expr);
}

void Interpreter::Visit(DivExpression* expression) {
  expression->lhv->Accept(this);
  int left_expr = expr_result;

  expression->rhv->Accept(this);
  int right_expr = expr_result;

  expr_result = (left_expr / right_expr);
}

void Interpreter::Visit(ResidueExpression* expression) {
  expression->lhv->Accept(this);
  int left_expr = expr_result;

  expression->rhv->Accept(this);
  int right_expr = expr_result;

  expr_result = (left_expr % right_expr);
}

void Interpreter::Visit(LengthExpression* expression) {
  expression->expr->Accept(this);
  if (array_variables.find(active_variable_identifier) == array_variables.end()) {
    std::cout << "Undeclared variable: -->" << active_variable_identifier
              << std::endl;
    exit(1);
  }
  expr_result = (array_variables[active_variable_identifier].size());
}

void Interpreter::Visit(LessExpression* expression) {
  expression->lhv->Accept(this);
  int left_expr = expr_result;

  expression->rhv->Accept(this);
  int right_expr = expr_result;

  expr_result = (left_expr < right_expr);
}

void Interpreter::Visit(LogicExpression* expression) {
  expr_result = (expression->value);
}

void Interpreter::Visit(NegativeExpression* expression) {

  expression->expr->Accept(this);
  expr_result = (!expr_result);
}

void Interpreter::Visit(NewArrayExpression* expression) {
  expression->expr->Accept(this);
  expr_with_new = true;
}

void Interpreter::Visit(NewExpression* expression) {
  expr_with_new = true;
  expr_result = 0;
}

void Interpreter::Visit(OrExpression* expression) {

  expression->lhv->Accept(this);
  int left_expr = expr_result;

  expression->rhv->Accept(this);
  int right_expr = expr_result;

  expr_result = (left_expr || right_expr);
}

void Interpreter::Visit(ParensExpression* expression) {
  expression->expr->Accept(this);
  expr_result = (expr_result);
}

///non-interpretable////////////////////////////////////////////////////////////

void Interpreter::Visit(ClassDeclaration* declaration) {
  std::cout << deferred_execution << "class declaration." << std::endl;
}

void Interpreter::Visit(MethodDeclaration* declaration) {
  std::cout << deferred_execution << "method declaration." << std::endl;
}

void Interpreter::Visit(ThisExpression* expression) {
  std::cout << deferred_execution << "\"this\" expression." << std::endl;
}

void Interpreter::Visit(MethodInvExpression* expression) {
  std::cout << deferred_execution << "method invocation." << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
