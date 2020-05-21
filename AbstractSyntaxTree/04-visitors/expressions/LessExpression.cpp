//
// Created by theneonlightning on 19.05.2020.
//

#include "LessExpression.h"

LessExpression::LessExpression(std::shared_ptr<Expression> lhv,
                               std::shared_ptr<Expression> rhv):
    lhv(lhv), rhv(rhv) {}

int LessExpression::Expr() const {
  return lhv->Expr() < rhv->Expr();
}

void LessExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
