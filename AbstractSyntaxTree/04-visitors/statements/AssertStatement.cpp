//
// Created by theneonlightning on 19.05.2020.
//

#include "AssertStatement.h"

AssertStatement::AssertStatement(std::shared_ptr<Expression> expr):
  expr(expr) {}

void AssertStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
