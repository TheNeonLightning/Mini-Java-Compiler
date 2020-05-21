//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_DECLARATIONS_CLASSDECLARATION_H_
#define VISITOR_DECLARATIONS_CLASSDECLARATION_H_

#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Declaration.h"
#include "VarDeclaration.h"
#include "../statements/Statement.h"

class ClassDeclaration: public Declaration {
 public:

  std::string identifier;
  std::string extends_ident;
  std::vector<std::shared_ptr<Declaration>> declarations;

  ClassDeclaration(const std::string &identifier, const std::string &extend_ident,
                   std::vector<std::shared_ptr<Declaration>> declarations);
  void Accept(Visitor *visitor) override;
};

#endif//VISITOR_DECLARATIONS_CLASSDECLARATION_H_
