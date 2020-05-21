//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_STATEMENTS_IFSTATEMENT_H_
#define VISITOR_STATEMENTS_IFSTATEMENT_H_

#pragma once

#include <memory>
#include "Statement.h"
#include "../expressions/Expression.h"

class IfStatement: public Statement {
 public:

  std::shared_ptr<Expression> expr;
  std::shared_ptr<Statement> statement;

  IfStatement(std::shared_ptr<Expression> expr,
              std::shared_ptr<Statement> statement);
  void Accept(Visitor* visitor) override;
};

#endif//VISITOR_STATEMENTS_IFSTATEMENT_H_
