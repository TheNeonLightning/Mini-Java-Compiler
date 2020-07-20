//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_DECLARATIONS_METHODDECLARATION_H_
#define VISITOR_DECLARATIONS_METHODDECLARATION_H_

#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Declaration.h"
#include "VarDeclaration.h"
#include "../statements/Statement.h"



class MethodDeclaration : public Declaration {
 public:

  std::string type;
  std::string identifier;
  bool is_array;
  std::vector<std::shared_ptr<VarDeclaration>> var_declarations;
  std::vector<std::shared_ptr<Statement>> statements;

  MethodDeclaration(std::pair<std::string, bool> type, const std::string& identifier,
                    std::vector<std::shared_ptr<VarDeclaration>>
                        var_declarations,
                    std::vector<std::shared_ptr<Statement>> statements);
  void Accept(Visitor *visitor) override;
};

#endif//VISITOR_DECLARATIONS_METHODDECLARATION_H_
