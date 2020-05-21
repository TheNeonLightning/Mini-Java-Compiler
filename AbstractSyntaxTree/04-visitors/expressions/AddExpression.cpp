//
// Created by theneonlightning on 19.05.2020.
//

#include "AddExpression.h"

AddExpression::AddExpression(std::shared_ptr<Expression> lhv,
                             std::shared_ptr<Expression> rhv):
  lhv(lhv), rhv(rhv) {}

int AddExpression::Expr() const {
  return lhv->Expr() + rhv->Expr();
}

void AddExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}