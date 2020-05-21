//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_EXPRESSIONS_NEWEXPRESSION_H_
#define VISITOR_EXPRESSIONS_NEWEXPRESSION_H_

#pragma once
#include <string>
#include "Expression.h"


class NewExpression: public Expression {
 public:

  std::string type;

  NewExpression(std::string type);
  int Expr() const override;
  void Accept(Visitor* visitor) override;

};


#endif//VISITOR_EXPRESSIONS_NEWEXPRESSION_H_
