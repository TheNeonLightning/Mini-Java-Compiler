//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_MAIN_CLASS_MAINCLASS_H_
#define VISITOR_MAIN_CLASS_MAINCLASS_H_

#pragma once
#include <string>
#include <vector>
#include <memory>
#include "../base_elements/BaseElement.h"

class MainClass: public BaseElement {
 public:

  std::string identifier;
  std::vector<std::shared_ptr<Statement>> statements;

  MainClass(const std::string& identifier,
            std::vector<std::shared_ptr<Statement>> statements);
  void Accept(Visitor* visitor) override;
};

#endif//VISITOR_MAIN_CLASS_MAINCLASS_H_
