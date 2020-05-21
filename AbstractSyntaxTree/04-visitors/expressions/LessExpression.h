//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_EXPRESSIONS_LESSEXPRESSION_H_
#define VISITOR_EXPRESSIONS_LESSEXPRESSION_H_

#pragma once
#include <memory>
#include "Expression.h"


class LessExpression: public Expression {
 public:

  std::shared_ptr<Expression> lhv;
  std::shared_ptr<Expression> rhv;

  LessExpression(std::shared_ptr<Expression> lhv,
             std::shared_ptr<Expression> rhv);
  int Expr() const override;
  void Accept(Visitor* visitor) override;

};


#endif//VISITOR_EXPRESSIONS_LESSEXPRESSION_H_
