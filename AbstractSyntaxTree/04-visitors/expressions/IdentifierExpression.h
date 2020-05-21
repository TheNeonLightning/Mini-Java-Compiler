//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_EXPRESSIONS_IDENTIFIEREXPRESSION_H_
#define VISITOR_EXPRESSIONS_IDENTIFIEREXPRESSION_H_

#pragma once
#include <string>
#include "Expression.h"


class IdentifierExpression: public Expression {
 public:

  std::string ident_name;

  IdentifierExpression(const std::string& ident_name);
  int Expr() const override;
  void Accept(Visitor* visitor) override;

};


#endif//VISITOR_EXPRESSIONS_IDENTIFIEREXPRESSION_H_
