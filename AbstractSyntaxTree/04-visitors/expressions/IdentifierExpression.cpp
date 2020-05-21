//
// Created by theneonlightning on 19.05.2020.
//

#include "IdentifierExpression.h"

IdentifierExpression::IdentifierExpression(const std::string& ident_name):
  ident_name(ident_name) {}


int IdentifierExpression::Expr() const {
  return 0;
}

void IdentifierExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
