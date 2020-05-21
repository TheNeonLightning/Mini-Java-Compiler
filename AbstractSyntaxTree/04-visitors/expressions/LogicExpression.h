//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_EXPRESSIONS_LOGICEXPRESSION_H_
#define VISITOR_EXPRESSIONS_LOGICEXPRESSION_H_

#pragma once
#include <string>
#include "Expression.h"


class LogicExpression: public Expression {
 public:

  bool value;

  LogicExpression(const std::string& value_str);
  int Expr() const override;
  void Accept(Visitor* visitor) override;

};


#endif//VISITOR_EXPRESSIONS_LOGICEXPRESSION_H_
