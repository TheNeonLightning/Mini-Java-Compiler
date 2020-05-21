//
// Created by theneonlightning on 19.05.2020.
//

#include "AndExpression.h"

AndExpression::AndExpression(std::shared_ptr<Expression> lhv,
                       std::shared_ptr<Expression> rhv):
    lhv(lhv), rhv(rhv) {}

int AndExpression::Expr() const {
  return lhv->Expr() && rhv->Expr();
}

void AndExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
