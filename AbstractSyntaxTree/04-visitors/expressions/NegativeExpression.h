//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_EXPRESSIONS_NEGATIVEEXPRESSION_H_
#define VISITOR_EXPRESSIONS_NEGATIVEEXPRESSION_H_

#pragma once
#include <memory>
#include "Expression.h"


class NegativeExpression: public Expression {
 public:

  std::shared_ptr<Expression> expr;

  NegativeExpression(std::shared_ptr<Expression> expr);
  int Expr() const override;
  void Accept(Visitor* visitor) override;

};


#endif//VISITOR_EXPRESSIONS_NEGATIVEEXPRESSION_H_
