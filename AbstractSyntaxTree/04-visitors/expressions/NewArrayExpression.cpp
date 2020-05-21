//
// Created by theneonlightning on 19.05.2020.
//

#include "NewArrayExpression.h"

NewArrayExpression::NewArrayExpression(std::string type,
                                       std::shared_ptr<Expression> expr):
    type(type), expr(expr) {}

int NewArrayExpression::Expr() const {
}

void NewArrayExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
