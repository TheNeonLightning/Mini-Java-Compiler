//
// Created by theneonlightning on 20.05.2020.
//

#ifndef VISITOR_VISITORS_VISITOR_H_
#define VISITOR_VISITORS_VISITOR_H_

#pragma once

#include "forward_decl.h"

class Visitor {
 public:

  virtual void Visit(AssertStatement* statement) = 0;
  virtual void Visit(IfElseStatement* statement) = 0;
  virtual void Visit(IfStatement* statement) = 0;
  virtual void Visit(BracesStatement* statement) = 0;
  virtual void Visit(LValueAssignStatement* statement) = 0;
  virtual void Visit(LocVarDecStatement* statement) = 0;
  virtual void Visit(ReturnStatement* statement) = 0;
  virtual void Visit(SOPrintlnStatement* statement) = 0;
  virtual void Visit(WhileStatement* statement) = 0;

  virtual void Visit(ClassDeclaration* declaration) = 0;
  virtual void Visit(MethodDeclaration* declaration) = 0;
  virtual void Visit(VarDeclaration* declaration) = 0;

  virtual void Visit(ArrayIdentifier* identifier) = 0;
  virtual void Visit(SimpleTypeIdentifier* identifier) = 0;

  virtual void Visit(MainClass* main_class) = 0;
  virtual void Visit(Program* program) = 0;

  //virtual void Visit(CertainType* type) = 0;


  virtual void Visit(OrExpression* expression) = 0;
  virtual void Visit(LessExpression* expression) = 0;
  virtual void Visit(AndExpression* expression) = 0;
  virtual void Visit(GreaterExpression* expression) = 0;
  virtual void Visit(IsEqualExpression* expression) = 0;
  virtual void Visit(AddExpression* expression) = 0;
  virtual void Visit(SubExpression* expression) = 0;
  virtual void Visit(MulExpression* expression) = 0;
  virtual void Visit(DivExpression* expression) = 0;
  virtual void Visit(ResidueExpression* expression) = 0;
  virtual void Visit(AccessExpression* expression) = 0;
  virtual void Visit(LengthExpression* expression) = 0;
  virtual void Visit(NewArrayExpression* expression) = 0;
  virtual void Visit(NewExpression* expression) = 0;
  virtual void Visit(NegativeExpression* expression) = 0;
  virtual void Visit(ParensExpression* expression)= 0;
  virtual void Visit(IdentifierExpression* expression) = 0;
  virtual void Visit(IntegerExpression* expression) = 0;
  virtual void Visit(ThisExpression* expression) = 0;
  virtual void Visit(LogicExpression* expression) = 0;
  virtual void Visit(MethodInvExpression* expression) = 0;

};

#endif//VISITOR_VISITORS_VISITOR_H_
