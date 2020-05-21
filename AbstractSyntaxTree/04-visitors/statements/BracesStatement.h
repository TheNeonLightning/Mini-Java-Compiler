//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_STATEMENTS_BRACESSTATEMENT_H_
#define VISITOR_STATEMENTS_BRACESSTATEMENT_H_

#pragma once

#include <vector>
#include <memory>
#include "Statement.h"
#include "../expressions/Expression.h"

class BracesStatement: public Statement {
 public:

  std::vector<std::shared_ptr<Statement>> statements;

  BracesStatement(std::vector<std::shared_ptr<Statement>> statements);
  void Accept(Visitor* visitor) override;
};


#endif//VISITOR_STATEMENTS_BRACESSTATEMENT_H_
