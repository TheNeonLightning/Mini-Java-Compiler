//
// Created by theneonlightning on 19.05.2020.
//

#include "ThisExpression.h"

ThisExpression::ThisExpression() {}

int ThisExpression::Expr() const {
}

void ThisExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
