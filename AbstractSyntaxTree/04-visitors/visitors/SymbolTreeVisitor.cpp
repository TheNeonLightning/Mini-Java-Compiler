//
// Created by theneonlightning on 18.07.2020.
//

#include "SymbolTreeVisitor.h"
#include "elements.h"
#include "objects/Integer.h"


SymbolTreeVisitor::SymbolTreeVisitor(): tree(new ScopeLayer) {
  current_layer = tree.root;
}

///program//////////////////////////////////////////////////////////////////////

void SymbolTreeVisitor::Visit(Program* program) {

  std::string identifier = program->main_class->identifier;

  current_layer->classes.insert(identifier);
  current_layer->defined_classes[identifier] = Class();
  current_class.push(identifier);

  ScopeLayer* next_layer = new ScopeLayer(current_layer);
  current_layer = next_layer;

  program->main_class->Accept(this);

  current_layer = current_layer->GetParent();
  current_class.pop();

  // Repeating the same actions for every class declaration
  for (auto class_decl: program->class_declarations) {

    current_layer->classes.insert(class_decl->identifier);
    current_layer->defined_classes[class_decl->identifier] = Class();
    current_class.push(class_decl->identifier);

    ScopeLayer* next_layer = new ScopeLayer(current_layer);
    current_layer = next_layer;

    class_decl->Accept(this);

    current_layer = current_layer->GetParent();
    current_class.pop();
  }
}

///main_class///////////////////////////////////////////////////////////////////

void SymbolTreeVisitor::Visit(MainClass* main_class) {

  ScopeLayer* new_layer = new ScopeLayer(current_layer);

  current_layer->DeclareMethodInClass(current_class.top(), "void", "main", {});
  current_layer->DeclareMethod("main", MethodType("void", "main", {}));

  current_layer = new_layer;

  for (auto statement : main_class->statements) {
    statement->Accept(this);
  }

  current_layer = current_layer->GetParent();
}

///declarations/////////////////////////////////////////////////////////////////

void SymbolTreeVisitor::Visit(ClassDeclaration* declaration) {

  for (auto declaration: declaration->declarations) {
    declaration->Accept(this);
  }

}

void SymbolTreeVisitor::Visit(MethodDeclaration* declaration) {

  current_layer->DeclareMethod(declaration->identifier,
                                MethodType(declaration->type,
                                           declaration->identifier,
                                           declaration->var_declarations));

  current_layer->DeclareMethodInClass(current_class.top(), declaration->type,
                                       declaration->identifier, {});

  ScopeLayer* new_layer = new ScopeLayer(current_layer);
  current_layer = new_layer;

  for (auto statement : declaration->statements) {
    statement->Accept(this);
  }

  current_layer = current_layer->GetParent();
}

void SymbolTreeVisitor::Visit(VarDeclaration* declaration) {
  current_layer->DeclareVariable(declaration->identifier, {declaration->type, declaration->is_array});
}

///identifiers//////////////////////////////////////////////////////////////////

void SymbolTreeVisitor::Visit(ArrayIdentifier* identifier) {}

void SymbolTreeVisitor::Visit(SimpleTypeIdentifier* identifier) {}

///statements///////////////////////////////////////////////////////////////////

void SymbolTreeVisitor::Visit(AssertStatement* statement) {}

void SymbolTreeVisitor::Visit(IfElseStatement* statement) {
  statement->statement_true->Accept(this);
  statement->statement_false->Accept(this);
}

void SymbolTreeVisitor::Visit(IfStatement* statement) {
  statement->statement->Accept(this);
}

void SymbolTreeVisitor::Visit(BracesStatement* statement) {

  ScopeLayer* new_layer = new ScopeLayer(current_layer);
  current_layer = new_layer;

  for (auto statement: statement->statements) {
    statement->Accept(this);
  }

  current_layer = current_layer->GetParent();
}

void SymbolTreeVisitor::Visit(LValueAssignStatement* statement) {}

void SymbolTreeVisitor::Visit(LocVarDecStatement* statement) {
  current_layer->DeclareVariable(statement->identifier, {statement->type, statement->is_array});
}

void SymbolTreeVisitor::Visit(ReturnStatement* statement) {}

void SymbolTreeVisitor::Visit(SOPrintlnStatement* statement) {}

void SymbolTreeVisitor::Visit(WhileStatement* statement) {
  statement->statement->Accept(this);
}

///expressions//////////////////////////////////////////////////////////////////

void SymbolTreeVisitor::Visit(OrExpression* expression) {}

void SymbolTreeVisitor::Visit(AndExpression* expression) {}

void SymbolTreeVisitor::Visit(LessExpression* expression) {}

void SymbolTreeVisitor::Visit(GreaterExpression* expression) {}

void SymbolTreeVisitor::Visit(IsEqualExpression* expression) {}

void SymbolTreeVisitor::Visit(AddExpression* expression) {}

void SymbolTreeVisitor::Visit(SubExpression* expression) {}

void SymbolTreeVisitor::Visit(MulExpression* expression) {}

void SymbolTreeVisitor::Visit(DivExpression* expression) {}

void SymbolTreeVisitor::Visit(ResidueExpression* expression) {}

void SymbolTreeVisitor::Visit(AccessExpression* expression) {}

void SymbolTreeVisitor::Visit(LengthExpression* expression) {}

void SymbolTreeVisitor::Visit(NewArrayExpression* expression) {}

void SymbolTreeVisitor::Visit(NewExpression* expression) {}

void SymbolTreeVisitor::Visit(NegativeExpression* expression) {}

void SymbolTreeVisitor::Visit(ParensExpression* expression) {}

void SymbolTreeVisitor::Visit(IdentifierExpression* expression) {}

void SymbolTreeVisitor::Visit(IntegerExpression* expression) {}

void SymbolTreeVisitor::Visit(ThisExpression* expression) {}

void SymbolTreeVisitor::Visit(LogicExpression* expression) {}

void SymbolTreeVisitor::Visit(MethodInvExpression* expression) {}

////////////////////////////////////////////////////////////////////////////////