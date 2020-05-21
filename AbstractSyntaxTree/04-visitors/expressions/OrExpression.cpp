//
// Created by theneonlightning on 19.05.2020.
//

#include "OrExpression.h"

OrExpression::OrExpression(std::shared_ptr<Expression> lhv,
                       std::shared_ptr<Expression> rhv):
    lhv(lhv), rhv(rhv) {}

int OrExpression::Expr() const {
  return lhv->Expr() || rhv->Expr();
}

void OrExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
