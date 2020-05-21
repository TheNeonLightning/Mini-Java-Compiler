//
// Created by theneonlightning on 19.05.2020.
//

#include "ParensExpression.h"

ParensExpression::ParensExpression(std::shared_ptr<Expression> expr):
    expr(expr) {}

int ParensExpression::Expr() const {
}

void ParensExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
