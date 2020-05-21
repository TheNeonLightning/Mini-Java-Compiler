//
// Created by theneonlightning on 19.05.2020.
//

#include "SubExpression.h"

SubExpression::SubExpression(std::shared_ptr<Expression> lhv,
                       std::shared_ptr<Expression> rhv):
    lhv(lhv), rhv(rhv) {}

int SubExpression::Expr() const {
  return lhv->Expr() - rhv->Expr();
}

void SubExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
