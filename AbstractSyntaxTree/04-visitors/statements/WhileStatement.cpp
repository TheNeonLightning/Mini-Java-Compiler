//
// Created by theneonlightning on 19.05.2020.
//

#include "WhileStatement.h"


WhileStatement::WhileStatement(std::shared_ptr<Expression> expr,
                               std::shared_ptr<Statement> statement):
  expr(expr), statement(statement) {}


void WhileStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
