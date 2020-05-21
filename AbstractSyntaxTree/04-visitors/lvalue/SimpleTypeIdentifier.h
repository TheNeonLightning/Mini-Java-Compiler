//
// Created by theneonlightning on 20.05.2020.
//

#ifndef VISITOR_LVALUE_SIMPLETYPEIDENTIFIER_H_
#define VISITOR_LVALUE_SIMPLETYPEIDENTIFIER_H_

#pragma once
#include <string>
#include "LValue.h"

class SimpleTypeIdentifier: public LValue {
 public:
  std::string identifier;

  SimpleTypeIdentifier(const std::string& identifier);
  void Accept(Visitor* visitor) override;
};

#endif//VISITOR_LVALUE_SIMPLETYPEIDENTIFIER_H_
