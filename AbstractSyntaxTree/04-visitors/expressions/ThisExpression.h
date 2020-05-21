//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_EXPRESSIONS_THISEXPRESSION_H_
#define VISITOR_EXPRESSIONS_THISEXPRESSION_H_

#pragma once
#include "Expression.h"


class ThisExpression: public Expression {
 public:

  ThisExpression();
  int Expr() const override;
  void Accept(Visitor* visitor) override;

};


#endif//VISITOR_EXPRESSIONS_THISEXPRESSION_H_
