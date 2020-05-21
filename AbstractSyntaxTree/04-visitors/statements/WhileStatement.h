//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_STATEMENTS_WHILESTATEMENT_H_
#define VISITOR_STATEMENTS_WHILESTATEMENT_H_

#pragma once

#include <memory>
#include "Statement.h"
#include "../expressions/Expression.h"

class WhileStatement: public Statement {
 public:

  std::shared_ptr<Expression> expr;
  std::shared_ptr<Statement> statement;

  WhileStatement(std::shared_ptr<Expression> expr,
                 std::shared_ptr<Statement> statement);
  void Accept(Visitor* visitor) override;
};

#endif//VISITOR_STATEMENTS_WHILESTATEMENT_H_
