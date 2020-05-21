//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_STATEMENTS_ASSERTSTATEMENT_H_
#define VISITOR_STATEMENTS_ASSERTSTATEMENT_H_

#pragma once

#include <memory>
#include "Statement.h"
#include "../expressions/Expression.h"

class AssertStatement: public Statement {
 public:

  std::shared_ptr<Expression> expr;

  AssertStatement(std::shared_ptr<Expression> expr);
  void Accept(Visitor* visitor) override;
};

#endif//VISITOR_STATEMENTS_ASSERTSTATEMENT_H_
