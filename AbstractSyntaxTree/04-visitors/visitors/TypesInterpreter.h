//
// Created by theneonlightning on 19.07.2020.
//

#ifndef COMPILERS_04_VISITORS_VISITORS_TYPESINTERPRETER_H_
#define COMPILERS_04_VISITORS_VISITORS_TYPESINTERPRETER_H_

#include "visitors/Visitor.h"
#include <stack>
#include "symbol_table/ScopeLayerTree.h"

class TypesInterpreter : public Visitor {

 public:
  TypesInterpreter(ScopeLayer *tree);
  ~TypesInterpreter() = default;

  void Visit(Program *program) override;

  void Visit(MainClass *main_class) override;

  void Visit(ClassDeclaration *declaration) override;
  void Visit(MethodDeclaration *declaration) override;
  void Visit(VarDeclaration *declaration) override;

  void Visit(AssertStatement *statement) override;
  void Visit(IfElseStatement *statement) override;
  void Visit(IfStatement *statement) override;
  void Visit(BracesStatement *statement) override;
  void Visit(LValueAssignStatement *statement) override;
  void Visit(LocVarDecStatement *statement) override;
  void Visit(ReturnStatement *statement) override;
  void Visit(SOPrintlnStatement *statement) override;
  void Visit(WhileStatement *statement) override;

  void Visit(ArrayIdentifier *identifier) override;
  void Visit(SimpleTypeIdentifier *identifier) override;

  void Visit(OrExpression *expression) override;
  void Visit(AndExpression *expression) override;
  void Visit(LessExpression *expression) override;
  void Visit(GreaterExpression *expression) override;
  void Visit(IsEqualExpression *expression) override;
  void Visit(AddExpression *expression) override;
  void Visit(SubExpression *expression) override;
  void Visit(MulExpression *expression) override;
  void Visit(DivExpression *expression) override;
  void Visit(ResidueExpression *expression) override;
  void Visit(AccessExpression *expression) override;
  void Visit(LengthExpression *expression) override;
  void Visit(NewArrayExpression *expression) override;
  void Visit(NewExpression *expression) override;
  void Visit(NegativeExpression *expression) override;
  void Visit(ParensExpression *expression) override;
  void Visit(IdentifierExpression *expression) override;
  void Visit(IntegerExpression *expression) override;
  void Visit(ThisExpression *expression) override;
  void Visit(LogicExpression *expression) override;
  void Visit(MethodInvExpression *expression) override;

  ScopeLayerTree tree;
  ScopeLayer* current_layer;
  std::shared_ptr<Object> return_value;
  std::string current_identifier;
  int array_size;
  std::stack<size_t> offsets;
};

#endif//COMPILERS_04_VISITORS_VISITORS_TYPESINTERPRETER_H_
