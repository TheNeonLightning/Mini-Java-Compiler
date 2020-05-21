//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_EXPRESSIONS_NEWARRAYEXPRESSION_H_
#define VISITOR_EXPRESSIONS_NEWARRAYEXPRESSION_H_

#pragma once
#include <string>
#include <memory>
#include "Expression.h"


class NewArrayExpression: public Expression {
 public:

  std::string type;
  std::shared_ptr<Expression> expr;

  NewArrayExpression(std::string type, std::shared_ptr<Expression> expr);
  int Expr() const override;
  void Accept(Visitor* visitor) override;

};


#endif//VISITOR_EXPRESSIONS_NEWARRAYEXPRESSION_H_
