//
// Created by theneonlightning on 18.07.2020.
//

#include <iostream>

#include "TypesChecker.h"
#include "elements.h"


TypesChecker::TypesChecker(ScopeLayer* layer): tree(layer) {
  current_layer = tree.root;
}

///program//////////////////////////////////////////////////////////////////////

void TypesChecker::Visit(Program* program) {

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

void TypesChecker::Visit(MainClass* main_class) {
  offsets.push(0);

  current_layer = current_layer->GetChild(offsets.top());

  for (auto declaration : main_class->statements) {
    declaration->Accept(this);
  }

  offsets.pop();
  current_layer = current_layer->GetParent();
}

///declarations/////////////////////////////////////////////////////////////////

void TypesChecker::Visit(ClassDeclaration* declaration) {
  for (auto declaration : declaration->declarations) {
    declaration->Accept(this);
  }
}

void TypesChecker::Visit(MethodDeclaration* declaration) {
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

void TypesChecker::Visit(VarDeclaration* declaration) {}

///identifiers//////////////////////////////////////////////////////////////////

void TypesChecker::Visit(ArrayIdentifier* identifier) {
  return_type = current_layer->GetType(identifier->identifier);
}

void TypesChecker::Visit(SimpleTypeIdentifier* identifier) {
  return_type = current_layer->GetType(identifier->identifier);
}


///statements///////////////////////////////////////////////////////////////////

void TypesChecker::Visit(AssertStatement* statement) {

  statement->expr->Accept(this);

  if (return_type.first != "boolean" || return_type.second) {
    throw std::runtime_error("Assert statement wrong type");
  }
}

void TypesChecker::Visit(IfElseStatement* statement) {
  statement->statement_true->Accept(this);
  statement->statement_false->Accept(this);
}

void TypesChecker::Visit(IfStatement* statement) {
  statement->statement->Accept(this);
}

void TypesChecker::Visit(BracesStatement* statement) {
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

void TypesChecker::Visit(LValueAssignStatement* statement) {

  statement->lvalue->Accept(this);

  std::pair<std::string, bool> left = return_type;

  statement->expr->Accept(this);

  if (left != return_type) {
    throw std::runtime_error("Assign statement wrong type");
  }
}

void TypesChecker::Visit(LocVarDecStatement* statement) {}

void TypesChecker::Visit(ReturnStatement* statement) {}

void TypesChecker::Visit(SOPrintlnStatement* statement) {
  return_type = {"void", false};
}

void TypesChecker::Visit(WhileStatement* statement) {
  statement->statement->Accept(this);
}

///expressions//////////////////////////////////////////////////////////////////

void TypesChecker::Visit(OrExpression* expression) {

  expression->lhv->Accept(this);

  std::pair<std::string, bool> left = return_type;

  expression->rhv->Accept(this);

  if (left != return_type) {
    throw std::runtime_error("Different types in OrExpression");
  }
}

void TypesChecker::Visit(AndExpression* expression) {

  expression->lhv->Accept(this);

  auto left = return_type;

  expression->rhv->Accept(this);

  if (left != return_type) {
    throw std::runtime_error("Different types in AndExpression");
  }
}

void TypesChecker::Visit(LessExpression* expression) {

  expression->lhv->Accept(this);

  auto left = return_type;

  expression->rhv->Accept(this);

  if (left != return_type) {
    throw std::runtime_error("Different types in LessExpression");
  }
}

void TypesChecker::Visit(GreaterExpression* expression) {

  expression->lhv->Accept(this);

  auto left = return_type;

  expression->rhv->Accept(this);

  if (left != return_type) {
    throw std::runtime_error("Different types in GreaterExpression");
  }
}

void TypesChecker::Visit(IsEqualExpression* expression) {

  expression->lhv->Accept(this);

  auto left = return_type;

  expression->rhv->Accept(this);

  if (left != return_type) {
    throw std::runtime_error("Different types in IsEqualExpression");
  }

  return_type = {"boolean", false};
}

void TypesChecker::Visit(AddExpression* expression) {

  expression->lhv->Accept(this);

  auto left = return_type;

  expression->rhv->Accept(this);

  if (left != return_type) {
    throw std::runtime_error("Different types in AddExpression");
  }
}

void TypesChecker::Visit(SubExpression* expression) {

  expression->lhv->Accept(this);

  auto left = return_type;

  expression->rhv->Accept(this);

  if (left != return_type) {
    throw std::runtime_error("Different types in SubExpression");
  }
}

void TypesChecker::Visit(MulExpression* expression) {

  expression->lhv->Accept(this);

  auto left = return_type;

  expression->rhv->Accept(this);

  if (left != return_type) {
    throw std::runtime_error("Different types in MulExpression");
  }
}

void TypesChecker::Visit(DivExpression* expression) {

  expression->lhv->Accept(this);

  auto left = return_type;

  expression->rhv->Accept(this);

  if (left != return_type) {
    throw std::runtime_error("Different types in DivExpression");
  }
}

void TypesChecker::Visit(ResidueExpression* expression) {

  expression->lhv->Accept(this);

  auto left = return_type;

  expression->rhv->Accept(this);

  if (left != return_type) {
    throw std::runtime_error("Different types in ResidueExpression");
  }
}

void TypesChecker::Visit(AccessExpression* expression) {

  expression->lhv->Accept(this);

  auto res_type = return_type;

  expression->rhv->Accept(this);

  if (return_type.first != "int" || return_type.second != false) {
    throw std::runtime_error("Bad index in *.[] expression");
  }

  return_type = {res_type.first, false};
}

void TypesChecker::Visit(LengthExpression* expression) {
  return_type = {"int", false};
}

void TypesChecker::Visit(NewArrayExpression* expression) {

  expression->expr->Accept(this);

  if (return_type.first != "int" || return_type.second) {
    throw std::runtime_error("Wrong size type in NewArrayExpression");
  }
  return_type = {expression->type, true};
}

void TypesChecker::Visit(NewExpression* expression) {
  return_type = {expression->type, false};
}

void TypesChecker::Visit(NegativeExpression* expression) {
  return_type = {"boolean", false};
}

void TypesChecker::Visit(ParensExpression* expression) {
  expression->expr->Accept(this);
}

void TypesChecker::Visit(IdentifierExpression* expression) {
  std::shared_ptr<Object> id = current_layer->Get(expression->ident_name);
  return_type = id->GetType();
}

void TypesChecker::Visit(IntegerExpression* expression) {
  return_type = {"int", false};
}

void TypesChecker::Visit(ThisExpression* expression) {}

void TypesChecker::Visit(LogicExpression* expression) {
  return_type = {"boolean", false};
}

void TypesChecker::Visit(MethodInvExpression* expression) {

  expression->expr->Accept(this);
  std::pair<std::string, bool> left = return_type;

  ScopeLayer* ascending_layer = current_layer;

  while (ascending_layer->defined_classes.find(left.first) ==
             ascending_layer->defined_classes.end() &&
         ascending_layer->parent != nullptr) {

    ascending_layer = ascending_layer->parent;

  }

  if (ascending_layer->defined_classes.find(left.first)
      != ascending_layer->defined_classes.end()) {

    auto iterator = ascending_layer->defined_classes.find(left.first);

    for (auto method: iterator->second.methods) {

      if (method.name == expression->identifier) {
        return_type = {method.type, false};
      }

    }

  } else {
    throw std::runtime_error("Could not find needed class while method "
                             "invocation");
  }
}

////////////////////////////////////////////////////////////////////////////////
