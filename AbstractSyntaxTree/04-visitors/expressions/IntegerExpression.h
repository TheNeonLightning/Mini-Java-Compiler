//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_EXPRESSIONS_INTEGEREXPRESSION_H_
#define VISITOR_EXPRESSIONS_INTEGEREXPRESSION_H_

#pragma once
#include "Expression.h"


class IntegerExpression: public Expression {
 public:

  int value;

  IntegerExpression(int value);
  int Expr() const override;
  void Accept(Visitor* visitor) override;

};


#endif//VISITOR_EXPRESSIONS_INTEGEREXPRESSION_H_
