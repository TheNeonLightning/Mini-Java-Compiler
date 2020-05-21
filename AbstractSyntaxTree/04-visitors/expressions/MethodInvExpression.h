//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_EXPRESSIONS_METHODINVEXPRESSION_H_
#define VISITOR_EXPRESSIONS_METHODINVEXPRESSION_H_

#pragma once
#include <memory>
#include <vector>
#include "Expression.h"
#include "../statements/Statement.h"

class MethodInvExpression: public Expression, public Statement {
 public:

  std::string identifier;
  std::shared_ptr<Expression> expr;
  std::vector<std::shared_ptr<Expression>> expressions;

  MethodInvExpression(std::shared_ptr<Expression> expr, const std::string& identifier,
                 const std::vector<std::shared_ptr<Expression>>& expr_list);
  int Expr() const override;
  void Accept(Visitor* visitor) override;
};


#endif//VISITOR_EXPRESSIONS_METHODINVEXPRESSION_H_
