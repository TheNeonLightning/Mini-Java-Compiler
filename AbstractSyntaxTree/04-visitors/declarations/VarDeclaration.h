//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_DECLARATIONS_VARDECLARATION_H_
#define VISITOR_DECLARATIONS_VARDECLARATION_H_

#pragma once
#include <string>
#include "Declaration.h"

class VarDeclaration: public Declaration {
 public:

  std::string type;
  std::string identifier;

  VarDeclaration(const std::string& type, const std::string& identifier);
  void Accept(Visitor* visitor) override;
};

#endif//VISITOR_DECLARATIONS_VARDECLARATION_H_
