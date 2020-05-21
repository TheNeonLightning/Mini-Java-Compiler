#pragma once

#include <memory>
#include "Statement.h"
#include "../expressions/Expression.h"

class Statement: public Statement {
 public:

  std::shared_ptr<Expression> expr;

  Statement(std::shared_ptr<Expression> expr);
  void Accept(Visitor* visitor) override;
};
