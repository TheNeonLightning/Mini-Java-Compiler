//
// Created by theneonlightning on 19.05.2020.
//

#include "LValueAssignStatement.h"

LValueAssignStatement::LValueAssignStatement(std::shared_ptr<LValue> lvalue,
                                             std::shared_ptr<Expression> expr):
  lvalue(lvalue), expr(expr) {}

void LValueAssignStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
