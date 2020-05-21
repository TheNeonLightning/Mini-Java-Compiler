//
// Created by theneonlightning on 19.05.2020.
//

#include "MethodInvExpression.h"

MethodInvExpression::MethodInvExpression(std::shared_ptr<Expression> expr,
  const std::string& identifier,
  const std::vector<std::shared_ptr<Expression>> &expressions):
  expr(std::move(expr)), identifier(identifier), expressions(expressions) {}

int MethodInvExpression::Expr() const {
}

void MethodInvExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}