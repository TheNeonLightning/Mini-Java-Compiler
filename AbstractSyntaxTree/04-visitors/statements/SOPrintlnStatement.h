//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_STATEMENTS_SOPRINTLNSTATEMENT_H_
#define VISITOR_STATEMENTS_SOPRINTLNSTATEMENT_H_

#pragma once

#include <memory>
#include "Statement.h"
#include "../expressions/Expression.h"

class SOPrintlnStatement: public Statement {
 public:

  std::shared_ptr<Expression> expr;

  SOPrintlnStatement(std::shared_ptr<Expression> expr);
  void Accept(Visitor* visitor) override;
};

#endif//VISITOR_STATEMENTS_SOPRINTLNSTATEMENT_H_
