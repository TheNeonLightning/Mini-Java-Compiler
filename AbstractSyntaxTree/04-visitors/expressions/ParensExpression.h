//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_EXPRESSIONS_PARENSEXPRESSION_H_
#define VISITOR_EXPRESSIONS_PARENSEXPRESSION_H_

#pragma once
#include <memory>
#include "Expression.h"


class ParensExpression: public Expression {
 public:

  std::shared_ptr<Expression> expr;

  ParensExpression(std::shared_ptr<Expression> expr);
  int Expr() const override;
  void Accept(Visitor* visitor) override;

};


#endif//VISITOR_EXPRESSIONS_PARENSEXPRESSION_H_
