//
// Created by theneonlightning on 19.05.2020.
//

#include "ClassDeclaration.h"

ClassDeclaration::ClassDeclaration(const std::string& identifier,
                                   const std::string& extends_ident,
                                   std::vector<std::shared_ptr<Declaration>>
                                       declarations):
  identifier(identifier), extends_ident(extends_ident),
  declarations(declarations) {}

void ClassDeclaration::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
