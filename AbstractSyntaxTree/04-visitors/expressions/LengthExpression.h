//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_EXPRESSIONS_LENGTHEXPRESSION_H_
#define VISITOR_EXPRESSIONS_LENGTHEXPRESSION_H_

#pragma once
#include <memory>
#include "Expression.h"


class LengthExpression: public Expression {
 public:

  std::shared_ptr<Expression> expr;

  LengthExpression(std::shared_ptr<Expression> expr);
  int Expr() const override;
  void Accept(Visitor* visitor) override;

};


#endif//VISITOR_EXPRESSIONS_LENGTHEXPRESSION_H_
