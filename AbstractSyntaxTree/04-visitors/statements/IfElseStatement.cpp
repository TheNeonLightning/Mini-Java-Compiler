//
// Created by theneonlightning on 19.05.2020.
//

#include "IfElseStatement.h"

IfElseStatement::IfElseStatement(std::shared_ptr<Expression> expr,
                                 std::shared_ptr<Statement> statement_true,
                                 std::shared_ptr<Statement> statement_false):
  expr(expr), statement_true(statement_true),
  statement_false(statement_false) {}


void IfElseStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
