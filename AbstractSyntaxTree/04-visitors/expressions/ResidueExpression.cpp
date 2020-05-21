//
// Created by theneonlightning on 19.05.2020.
//

#include "ResidueExpression.h"

ResidueExpression::ResidueExpression(std::shared_ptr<Expression> lhv,
                       std::shared_ptr<Expression> rhv):
    lhv(lhv), rhv(rhv) {}

int ResidueExpression::Expr() const {
  return lhv->Expr() % rhv->Expr();
}

void ResidueExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
