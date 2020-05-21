//
// Created by theneonlightning on 19.05.2020.
//

#include "MethodDeclaration.h"

MethodDeclaration::MethodDeclaration(const std::string &type,
                   const std::string &id,
                   std::vector<std::shared_ptr<VarDeclaration>> var_declarations,
                   std::vector<std::shared_ptr<Statement>> statements):
  type(type), identifier(id), var_declarations(var_declarations),
  statements(statements) {}


void MethodDeclaration::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
