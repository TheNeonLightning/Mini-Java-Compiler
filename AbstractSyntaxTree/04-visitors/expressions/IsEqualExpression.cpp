//
// Created by theneonlightning on 19.05.2020.
//

#include "IsEqualExpression.h"

IsEqualExpression::IsEqualExpression(std::shared_ptr<Expression> lhv,
                                     std::shared_ptr<Expression> rhv):
    lhv(lhv), rhv(rhv) {}

int IsEqualExpression::Expr() const {
  return lhv->Expr() == rhv->Expr();
}

void IsEqualExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
