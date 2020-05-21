//
// Created by theneonlightning on 20.05.2020.
//

/**
 * \file
 * \author theneonlightning
 *
 * This file contains functions for printing the AST with graphviz. Using
 * pointers as node names as they are all different and allow not to create
 * additional variable.
 */

#include "PrintVisitor.h"

#include "elements.h"

#include <iostream>


PrintVisitor::PrintVisitor(const std::string& filename) {

  file.open(filename);

  file << "digraph ASTree {" << std::endl;
  file << "node [shape = rectangle]" << std::endl;
}

PrintVisitor::~PrintVisitor() {

  file << "}" << std::endl;
  file.close();

}

///program//////////////////////////////////////////////////////////////////////

void PrintVisitor::Visit(Program* program) {
  file << "node" << program << "[label = \"Program\"]" << std::endl;

  program->main_class->Accept(this);

  file << "node" << program << "-> node" << program->main_class.get()
       << std::endl;

  for (auto decl : program->class_declarations) {
    file << "node" << program << "-> node" << decl.get() << std::endl;
    decl->Accept(this);
  }
}

///main_class///////////////////////////////////////////////////////////////////

void PrintVisitor::Visit(MainClass* main_class) {

  file << "node" << main_class << "[label = \"Main Class\n" << "Identifier: "
       << main_class->identifier << "\"]" << std::endl;

  for (auto statement : main_class->statements) {
    file << "node" << main_class << "->" << "node" << statement.get()
         << std::endl;
    statement->Accept(this);
  }
}

///declarations/////////////////////////////////////////////////////////////////

void PrintVisitor::Visit(ClassDeclaration* declaration) {

  file << "node" << declaration << " [label =  \"class "
       << declaration->identifier;

  if (!declaration->extends_ident.empty()) {
    file << " extends " << declaration->extends_ident;
  }

  file << "\"]" << std::endl;

  for (auto decl : declaration->declarations) {
    file << "node" << declaration << "-> node" << decl.get() << std::endl;
    decl->Accept(this);
  }
}

void PrintVisitor::Visit(MethodDeclaration* declaration) {

  file << "node" << declaration << " [label =  \"public " << declaration->type
       << " " << declaration->identifier << "(...) {...}\"]" << std::endl;

  for (auto form : declaration->var_declarations) {
    file << "node" << declaration << "-> node" << form.get() << std::endl;
    form->Accept(this);
  }

  for (auto st : declaration->statements) {
    file << "node" << declaration << "-> node" << st.get() << std::endl;
    st->Accept(this);
  }
}

void PrintVisitor::Visit(VarDeclaration* declaration) {

  file << "node" << declaration << " [label =  \"" << declaration->type
       << " " << declaration->identifier << "\"]" << std::endl;

}

///lvalue///////////////////////////////////////////////////////////////////////

void PrintVisitor::Visit(ArrayIdentifier* identifier) {

  file << "node" << identifier << " [label =  \"" << identifier->identifier
       <<  "[...]\"]" << std::endl;

  file << "node" << identifier << "-> node" << identifier->expr.get()
       << std::endl;
  identifier->expr->Accept(this);

}

void PrintVisitor::Visit(SimpleTypeIdentifier* identifier) {

  file << "node" << identifier << " [label =  \"" << identifier->identifier
       << "\"]"
       << std::endl;

}

///statements///////////////////////////////////////////////////////////////////

void PrintVisitor::Visit(AssertStatement* statement) {

  file << "node" << statement << " [label = \"assert(...) \"]" << std::endl;
  file << "node" << statement << "-> node" << statement->expr.get()
       << std::endl;

  statement->expr->Accept(this);
}

void PrintVisitor::Visit(BracesStatement* statement) {

  file << "node" << statement << " [label = \"{...}\"]" << std::endl;

  for (auto stat : statement->statements) {
    file << "node" << statement << "-> node" << stat.get() << std::endl;
    stat->Accept(this);
  }
}

void PrintVisitor::Visit(IfElseStatement* statement) {

  file << "node" << statement << " [label = \"if (...) {...} else {...} \"]"
       << std::endl;

  file << "node" << statement << "-> node" << statement->expr.get()
       << std::endl;
  file << "node" << statement << "-> node" << statement->statement_true.get()
       << std::endl;
  file << "node" << statement << "-> node" << statement->statement_false.get()
       << std::endl;

  statement->expr->Accept(this);
  statement->statement_true->Accept(this);
  statement->statement_false->Accept(this);
}

void PrintVisitor::Visit(IfStatement* statement) {

  file << "node" << statement << " [label = \"if (...) {...}\"]" << std::endl;

  file << "node" << statement << "-> node" << statement->expr.get()
       << std::endl;
  file << "node" << statement << "-> node" << statement->statement.get()
       << std::endl;

  statement->expr->Accept(this);
  statement->statement->Accept(this);
}

void PrintVisitor::Visit(LocVarDecStatement* statement) {

  file << "node" << statement << " [label = \"local variable declaration\"]"
       << std::endl;

  file << "node" << &statement->type << " [label = \"" << statement->type
       << "\"]" << std::endl;
  file << "node" << &statement->identifier << " [label = \""
       << statement->identifier << "\"]" << std::endl;

  file << "node" << statement << "-> node" << &statement->type << std::endl;
  file << "node" << statement << "-> node" << &statement->identifier
       << std::endl;
}

void PrintVisitor::Visit(LValueAssignStatement* statement) {

  file << "node" << statement << " [label = \" = \"]" << std::endl;

  file << "node" << statement << "-> node" << statement->lvalue.get()
       << std::endl;
  file << "node" << statement << "-> node" << statement->expr.get()
       << std::endl;

  statement->lvalue->Accept(this);
  statement->expr->Accept(this);
}

void PrintVisitor::Visit(ReturnStatement* statement) {

  file << "node" << statement << " [label = \"return\"]"
       << std::endl;
  file << "node" << statement << "-> node" << statement->expr.get()
       << std::endl;

  statement->expr->Accept(this);
}

void PrintVisitor::Visit(SOPrintlnStatement* statement) {

  file << "node" << statement << " [label = \"System.out.println\"]"
       << std::endl;
  file << "node" << statement << "-> node" << statement->expr.get()
       << std::endl;

  statement->expr->Accept(this);
}

void PrintVisitor::Visit(WhileStatement* statement) {

  file << "node" << statement << " [label = \"while\"]" << std::endl;
  file << "node" << statement << "-> node" << statement->expr.get()
       << std::endl;
  file << "node" << statement << "-> node" << statement->statement.get()
       << std::endl;

  statement->expr->Accept(this);
  statement->statement->Accept(this);
}

///expressions//////////////////////////////////////////////////////////////////

void PrintVisitor::Visit(AccessExpression* expression) {

  file << "node" << expression << " [label = \"expr[ expr ]\" ]" << std::endl;
  file << "node" << expression << "-> node" << expression->lhv.get()
       << std::endl;
  file << "node" << expression << "-> node" << expression->rhv.get()
       << std::endl;

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
}

void PrintVisitor::Visit(AddExpression* expression) {

  file << "node" << expression << " [label = \" + \" ]" << std::endl;
  file << "node" << expression << "-> node" << expression->lhv.get()
       << std::endl;
  file << "node" << expression << "-> node" << expression->rhv.get()
       << std::endl;

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
}

void PrintVisitor::Visit(AndExpression* expression) {


  file << "node" << expression << " [label =  \" &&  \" ]" << std::endl;

  file << "node" << expression << "-> node" << expression->lhv.get()
       << std::endl;

  file << "node" << expression << "-> node" << expression->rhv.get()
       << std::endl;

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
}

void PrintVisitor::Visit(OrExpression* expression) {

  file << "node" << expression << " [label =  \" || \" ]" << std::endl;
  file << "node" << expression << "-> node" << expression->lhv.get()
       << std::endl;
  file << "node" << expression << "-> node" << expression->rhv.get()
       << std::endl;

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
}

void PrintVisitor::Visit(LessExpression* expression) {

  file << "node" << expression << " [label =  \" < \" ]" << std::endl;
  file << "node" << expression << "-> node" << expression->lhv.get()
       << std::endl;
  file << "node" << expression << "-> node" << expression->rhv.get()
       << std::endl;

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
}

void PrintVisitor::Visit(LogicExpression* expression) {

  file << "node" << expression << " [label =  \"" << expression->value
       << "\" ]" << std::endl;
}

void PrintVisitor::Visit(GreaterExpression* expression) {

  file << "node" << expression << " [label =  \" > \" ]" << std::endl;
  file << "node" << expression << "-> node" << expression->lhv.get()
       << std::endl;
  file << "node" << expression << "-> node" << expression->rhv.get()
       << std::endl;

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
}

void PrintVisitor::Visit(IdentifierExpression* expression) {

  file << "node" << expression << " [label =  \" " << expression->ident_name
       << "\"]" << std::endl;
}

void PrintVisitor::Visit(IntegerExpression* expression) {

  file << "node" << expression << " [label =  \"" << expression->value
       << "\" ]" << std::endl;
}

void PrintVisitor::Visit(IsEqualExpression* expression) {

  file << "node" << expression << " [label =  \" ==  \"]" << std::endl;
  file << "node" << expression << "-> node" << expression->lhv.get()
       << std::endl;
  file << "node" << expression << "-> node" << expression->rhv.get()
       << std::endl;

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
}


void PrintVisitor::Visit(LengthExpression* expression) {

  file << "node" << expression << " [label = \"expr.length\" ]" << std::endl;
  file << "node" << expression << "-> node" << expression->expr.get()
       << std::endl;

  expression->expr->Accept(this);

}

void PrintVisitor::Visit(SubExpression* expression) {

  file << "node" << expression << " [label =  \" - \"]" << std::endl;
  file << "node" << expression << "-> node" << expression->lhv.get()
       << std::endl;
  file << "node" << expression << "-> node" << expression->rhv.get()
       << std::endl;

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
}

void PrintVisitor::Visit(MulExpression* expression) {

  file << "node" << expression << " [label =  \" * \" ]" << std::endl;
  file << "node" << expression << "-> node" << expression->lhv.get()
       << std::endl;
  file << "node" << expression << "-> node" << expression->rhv.get()
       << std::endl;

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
}

void PrintVisitor::Visit(NewArrayExpression* expression) {

  file << "node" << expression << " [label =  \"new " << expression->type
       << " [expr]\" ]" << std::endl;
  file << "node" << expression << "-> node" << expression->expr.get()
       << std::endl;

  expression->expr->Accept(this);

}

void PrintVisitor::Visit(NewExpression* expression) {

  file << "node" << expression << " [label =  \"new " << expression->type
       << " ()\" ]" << std::endl;
}

void PrintVisitor::Visit(NegativeExpression* expression) {


  file << "node" << expression << " [label =  \"!(...)\" ]" << std::endl;
  file << "node" << expression << "-> node" << expression->expr.get()
       << std::endl;

  expression->expr->Accept(this);
}

void PrintVisitor::Visit(ParensExpression* expression) {


  file << "node" << expression << " [label =  \"(...)\" ]" << std::endl;
  file << "node" << expression << "-> node" << expression->expr.get()
       << std::endl;

  expression->expr->Accept(this);
}

void PrintVisitor::Visit(ResidueExpression* expression) {

  file << "node" << expression << " [label = \"  % \" ]" << std::endl;
  file << "node" << expression << "-> node" << expression->lhv.get()
       << std::endl;
  file << "node" << expression << "-> node" << expression->rhv.get()
       << std::endl;

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
}

void PrintVisitor::Visit(ThisExpression* expression) {

  file << "node" << expression << " [label =  \"this\" ]" << std::endl;
}

void PrintVisitor::Visit(MethodInvExpression* expression) {

  file << "node" << expression << " [label =  \"expr." << expression->identifier
       << "( expr )\" ]" << std::endl;
  file << "node" << expression << "-> node" << expression->expr.get()
       << std::endl;
  expression->expr->Accept(this);

  for (auto st : expression->expressions) {
    file << "node" << expression << "-> node" << st.get() << std::endl;
    st->Accept(this);
  }
}

void PrintVisitor::Visit(DivExpression* expression) {

  file << "node" << expression << " [label =  \" / \" ]" << std::endl;
  file << "node" << expression << "-> node" << expression->lhv.get()
       << std::endl;
  file << "node" << expression << "-> node" << expression->rhv.get()
       << std::endl;

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
}

////////////////////////////////////////////////////////////////////////////////
