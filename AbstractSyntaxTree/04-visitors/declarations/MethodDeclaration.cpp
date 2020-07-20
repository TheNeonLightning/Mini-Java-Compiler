//
// Created by theneonlightning on 19.05.2020.
//

#include "MethodDeclaration.h"

MethodDeclaration::MethodDeclaration(const std::pair<std::string, bool> type,
                   const std::string& id,
                   std::vector<std::shared_ptr<VarDeclaration>> var_declarations,
                   std::vector<std::shared_ptr<Statement>> statements):
  type(type.first), identifier(id), is_array(type.second), var_declarations(var_declarations),
  statements(statements) {}


void MethodDeclaration::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
