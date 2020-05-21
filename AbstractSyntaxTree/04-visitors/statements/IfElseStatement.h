//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_STATEMENTS_IFELSESTATEMENT_H_
#define VISITOR_STATEMENTS_IFELSESTATEMENT_H_

#pragma once

#include <memory>
#include "Statement.h"
#include "../expressions/Expression.h"

class IfElseStatement: public Statement {
 public:

  std::shared_ptr<Expression> expr;
  std::shared_ptr<Statement> statement_true;
  std::shared_ptr<Statement> statement_false;

  IfElseStatement(std::shared_ptr<Expression> expr,
                  std::shared_ptr<Statement> statement_true,
                  std::shared_ptr<Statement> statement_false);
  void Accept(Visitor* visitor) override;
};

#endif//VISITOR_STATEMENTS_IFELSESTATEMENT_H_
