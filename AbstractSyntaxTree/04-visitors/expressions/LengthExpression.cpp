//
// Created by theneonlightning on 19.05.2020.
//

#include "LengthExpression.h"

LengthExpression::LengthExpression(std::shared_ptr<Expression> expr):
    expr(expr) {}

int LengthExpression::Expr() const {
}

void LengthExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
