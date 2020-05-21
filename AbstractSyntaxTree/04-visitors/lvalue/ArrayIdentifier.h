//
// Created by theneonlightning on 20.05.2020.
//

#ifndef VISITOR_LVALUE_ARRAYIDENTIFIER_H_
#define VISITOR_LVALUE_ARRAYIDENTIFIER_H_

#pragma once
#include <string>
#include <memory>
#include "LValue.h"
#include "../expressions/Expression.h"

class ArrayIdentifier: public LValue {
 public:
  std::string identifier;
  std::shared_ptr<Expression> expr;

  ArrayIdentifier(const std::string& identifier,
                  std::shared_ptr<Expression> expr);
  void Accept(Visitor* visitor);
};

#endif//VISITOR_LVALUE_ARRAYIDENTIFIER_H_
