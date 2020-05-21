//
// Created by theneonlightning on 19.05.2020.
//

#include "VarDeclaration.h"

VarDeclaration::VarDeclaration(const std::string& type,
                               const std::string& identifier):
  type(type), identifier(identifier) {}

void VarDeclaration::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
