//
// Created by theneonlightning on 19.05.2020.
//

#include "IfStatement.h"

IfStatement::IfStatement(std::shared_ptr<Expression> expr,
                         std::shared_ptr<Statement> statement):
  expr(expr), statement(statement) {}

void IfStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
