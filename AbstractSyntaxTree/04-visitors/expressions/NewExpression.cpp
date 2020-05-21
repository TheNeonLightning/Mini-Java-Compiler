//
// Created by theneonlightning on 19.05.2020.
//

#include "NewExpression.h"

NewExpression::NewExpression(std::string type): type(type) {}


int NewExpression::Expr() const {
}

void NewExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
