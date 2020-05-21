//
// Created by theneonlightning on 19.05.2020.
//

#include "IntegerExpression.h"

IntegerExpression::IntegerExpression(int value): value(value) {}


int IntegerExpression::Expr() const {
  return value;
}

void IntegerExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
