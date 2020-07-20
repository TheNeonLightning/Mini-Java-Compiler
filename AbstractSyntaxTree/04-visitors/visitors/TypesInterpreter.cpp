//
// Created by theneonlightning on 19.07.2020.
//

#include <iostream>

#include "TypesInterpreter.h"
#include "elements.h"
#include "objects/Boolean.h"
#include "objects/Class.h"
#include "objects/Integer.h"


TypesInterpreter::TypesInterpreter(ScopeLayer* layer): tree(layer) {
  current_layer = tree.root;
}

///program//////////////////////////////////////////////////////////////////////

void TypesInterpreter::Visit(Program* program) {

  offsets.push(0);
  current_layer = current_layer->GetChild(offsets.top());
  program->main_class->Accept(this);
  current_layer = current_layer->GetParent();
  offsets.pop();

  for (size_t index = 0; index < program->class_declarations.size(); ++index) {

    offsets.push(index + 1);
    current_layer = current_layer->GetChild(offsets.top());
    program->class_declarations[index]->Accept(this);
    current_layer = current_layer->GetParent();
    offsets.pop();

  }

}

///main_class///////////////////////////////////////////////////////////////////

void TypesInterpreter::Visit(MainClass* main_class) {
  offsets.push(0);
  current_layer = current_layer->GetChild(offsets.top());

  for (auto declaration : main_class->statements) {
    declaration->Accept(this);
  }

  offsets.pop();
  current_layer = current_layer->GetParent();
}

///declaration//////////////////////////////////////////////////////////////////

void TypesInterpreter::Visit(ClassDeclaration* declaration) {
  for (auto declaration : declaration->declarations) {
    declaration->Accept(this);
  }
}

void TypesInterpreter::Visit(MethodDeclaration* declaration) {
  offsets.push(0);
  current_layer = current_layer->GetChild(offsets.top());

  for (auto statement : declaration->statements) {
    statement->Accept(this);
  }

  size_t index = offsets.top() + 1;
  offsets.pop();
  offsets.push(index);
  current_layer = current_layer->GetParent();
}

void TypesInterpreter::Visit(VarDeclaration* declaration) {}

///identifier///////////////////////////////////////////////////////////////////

void TypesInterpreter::Visit(ArrayIdentifier* identifier) {
  current_identifier = identifier->identifier;
  identifier->expr->Accept(this);
  array_size = return_value->ToInt();
}

void TypesInterpreter::Visit(SimpleTypeIdentifier* identifier) {
  current_identifier = identifier->identifier;
  array_size = 0;
}

///statement////////////////////////////////////////////////////////////////////

void TypesInterpreter::Visit(AssertStatement* statement) {

  statement->expr->Accept(this);

  if (!return_value->ToBoolean()) {
    throw std::runtime_error("Assertion failed!");
  }
}

void TypesInterpreter::Visit(IfElseStatement* statement) {

  statement->expr->Accept(this);

  if (return_value->ToBoolean()) {
    statement->statement_true->Accept(this);
  } else {
    statement->statement_false->Accept(this);
  }
}

void TypesInterpreter::Visit(IfStatement* statement) {

  statement->expr->Accept(this);

  if (return_value->ToBoolean()) {
    statement->statement->Accept(this);
  }
}

void TypesInterpreter::Visit(BracesStatement* statement) {

  offsets.push(0);
  current_layer = current_layer->GetChild(offsets.top());

  for (auto statement: statement->statements) {
    statement->Accept(this);
  }

  size_t index = offsets.top() + 1;
  offsets.pop();
  offsets.push(index);
  current_layer = current_layer->GetParent();
}

void TypesInterpreter::Visit(LValueAssignStatement* statement) {

  statement->lvalue->Accept(this);

  std::string name = current_identifier;

  statement->expr->Accept(this);

  current_layer->Put(name, return_value);
}

void TypesInterpreter::Visit(LocVarDecStatement* statement) {}

void TypesInterpreter::Visit(ReturnStatement* statement) {}

void TypesInterpreter::Visit(SOPrintlnStatement* statement) {
  statement->expr->Accept(this);
  std::cout << return_value->ToInt() << std::endl;
}

void TypesInterpreter::Visit(WhileStatement* statement) {
  statement->statement->Accept(this);
}

///expression///////////////////////////////////////////////////////////////////

void TypesInterpreter::Visit(OrExpression* expression) {}

void TypesInterpreter::Visit(AndExpression* expression) {}

void TypesInterpreter::Visit(LessExpression* expression) {}

void TypesInterpreter::Visit(GreaterExpression* expression) {}

void TypesInterpreter::Visit(IsEqualExpression* expression) {

  expression->lhv->Accept(this);

  auto left = return_value;

  expression->rhv->Accept(this);

  if (return_value->GetType().first == "int") {

    return_value =
        std::make_shared<Boolean>(left->ToInt() == return_value->ToInt(), false);

  } else {
    return_value = std::make_shared<Boolean>(left == return_value, false);
  }
}

void TypesInterpreter::Visit(AddExpression* expression) {

  expression->lhv->Accept(this);

  auto left = return_value;

  expression->rhv->Accept(this);

  return_value =
      std::make_shared<Integer>(left->ToInt() + return_value->ToInt(), false);
}

void TypesInterpreter::Visit(SubExpression* expression) {

  expression->lhv->Accept(this);

  auto left = return_value;

  expression->rhv->Accept(this);

  return_value =
      std::make_shared<Integer>(left->ToInt() - return_value->ToInt(), false);
}

void TypesInterpreter::Visit(MulExpression* expression) {

  expression->lhv->Accept(this);

  auto left = return_value;

  expression->rhv->Accept(this);

  return_value =
      std::make_shared<Integer>(left->ToInt() * return_value->ToInt(), false);
}

void TypesInterpreter::Visit(DivExpression* expression) {

  expression->lhv->Accept(this);

  auto left = return_value;

  expression->rhv->Accept(this);

  return_value =
      std::make_shared<Integer>(left->ToInt() / return_value->ToInt(), false);
}

void TypesInterpreter::Visit(ResidueExpression* expression) {

  expression->lhv->Accept(this);

  auto left = return_value;

  expression->rhv->Accept(this);

  return_value =
      std::make_shared<Integer>(left->ToInt() % return_value->ToInt(), false);
}

void TypesInterpreter::Visit(AccessExpression* expression) {}

void TypesInterpreter::Visit(LengthExpression* expression) {}

void TypesInterpreter::Visit(NewArrayExpression* expression) {}

void TypesInterpreter::Visit(NewExpression* expression) {

  if (expression->type == "boolean") {

    return_value = std::make_shared<Boolean>(false, false);

  } else if (expression->type == "int") {

    return_value = std::make_shared<Integer>(0, false);

  } else {

    return_value = std::make_shared<ClassType>(expression->type, false);

  }
}

void TypesInterpreter::Visit(NegativeExpression* expression) {}

void TypesInterpreter::Visit(ParensExpression* expression) {
  expression->expr->Accept(this);
}

void TypesInterpreter::Visit(IdentifierExpression* expression) {
  current_identifier = expression->ident_name;
  return_value = current_layer->Get(expression->ident_name);
}

void TypesInterpreter::Visit(IntegerExpression* expression) {
  return_value = std::make_shared<Integer>(expression->value, false);
}

void TypesInterpreter::Visit(ThisExpression* expression) {}

void TypesInterpreter::Visit(LogicExpression* expression) {
  return_value = std::make_shared<Boolean>(expression->value, false);
}

void TypesInterpreter::Visit(MethodInvExpression* expression) {}

////////////////////////////////////////////////////////////////////////////////
