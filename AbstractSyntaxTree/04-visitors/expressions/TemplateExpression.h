#pragma once
#include <memory>
#include "Expression.h"


class Expression: public Expression {
 public:

  std::shared_ptr<Expression> lhv;
  std::shared_ptr<Expression> rhv;

  Expression(std::shared_ptr<Expression> lhv,
             std::shared_ptr<Expression> rhv);
  int Expr() const override;
  void Accept(Visitor* visitor) override;

};
