//
// Created by theneonlightning on 19.05.2020.
//

#include "DivExpression.h"

DivExpression::DivExpression(std::shared_ptr<Expression> lhv,
                       std::shared_ptr<Expression> rhv):
    lhv(lhv), rhv(rhv) {}

int DivExpression::Expr() const {
  return lhv->Expr() / rhv->Expr();
}

void DivExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
