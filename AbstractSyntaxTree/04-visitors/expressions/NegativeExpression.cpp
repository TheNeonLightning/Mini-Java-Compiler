//
// Created by theneonlightning on 19.05.2020.
//

#include "NegativeExpression.h"

NegativeExpression::NegativeExpression(std::shared_ptr<Expression> expr):
    expr(expr) {}

int NegativeExpression::Expr() const {
}

void NegativeExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
