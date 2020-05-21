//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_STATEMENTS_LVALUEASSIGNSTATEMENT_H_
#define VISITOR_STATEMENTS_LVALUEASSIGNSTATEMENT_H_

#pragma once

#include <memory>
#include "Statement.h"
#include "../expressions/Expression.h"
#include "../lvalue/LValue.h"

class LValueAssignStatement: public Statement {
 public:

  std::shared_ptr<LValue> lvalue;
  std::shared_ptr<Expression> expr;

  LValueAssignStatement(std::shared_ptr<LValue> lvalue,
                        std::shared_ptr<Expression> expr);
  void Accept(Visitor* visitor) override;
};

#endif//VISITOR_STATEMENTS_LVALUEASSIGNSTATEMENT_H_
