//
// Created by theneonlightning on 19.05.2020.
//

#include "GreaterExpression.h"

GreaterExpression::GreaterExpression(std::shared_ptr<Expression> lhv,
                       std::shared_ptr<Expression> rhv):
    lhv(lhv), rhv(rhv) {}

int GreaterExpression::Expr() const {
  return lhv->Expr() > rhv->Expr();
}

void GreaterExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
