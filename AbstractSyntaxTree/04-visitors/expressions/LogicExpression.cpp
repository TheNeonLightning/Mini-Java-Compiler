//
// Created by theneonlightning on 19.05.2020.
//

#include "LogicExpression.h"

LogicExpression::LogicExpression(const std::string& value_str) {
  value_str == "true" ? value = true : value = false;
}

int LogicExpression::Expr() const {
}

void LogicExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
