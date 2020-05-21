//
// Created by theneonlightning on 19.05.2020.
//

#include "AccessExpression.h"

AccessExpression::AccessExpression(std::shared_ptr<Expression> lhv,
                                   std::shared_ptr<Expression> rhv):
    lhv(lhv), rhv(rhv) {}

int AccessExpression::Expr() const {
}

void AccessExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
