//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_STATEMENTS_LOCVARDECSTATEMENT_H_
#define VISITOR_STATEMENTS_LOCVARDECSTATEMENT_H_

#pragma once

#include <string>
#include "Statement.h"
#include "../expressions/Expression.h"

class LocVarDecStatement: public Statement {
 public:

  std::string type;
  std::string identifier;

  LocVarDecStatement(const std::string& type, const std::string& identifier);
  void Accept(Visitor* visitor) override;
};

#endif//VISITOR_STATEMENTS_LOCVARDECSTATEMENT_H_
