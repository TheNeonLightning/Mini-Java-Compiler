//
// Created by theneonlightning on 19.05.2020.
//

#include "MulExpression.h"

MulExpression::MulExpression(std::shared_ptr<Expression> lhv,
                       std::shared_ptr<Expression> rhv):
    lhv(lhv), rhv(rhv) {}

int MulExpression::Expr() const {
  return lhv->Expr() * rhv->Expr();
}

void MulExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
