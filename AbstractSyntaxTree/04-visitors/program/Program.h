//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_PROGRAM_PROGRAM_H_
#define VISITOR_PROGRAM_PROGRAM_H_

#pragma once
#include <vector>
#include <memory>
#include "../base_elements/BaseElement.h"

class Program: public BaseElement {
 public:

  std::shared_ptr<MainClass> main_class;
  std::vector<std::shared_ptr<ClassDeclaration>> class_declarations;

  Program(std::shared_ptr<MainClass> main_class,
          std::vector<std::shared_ptr<ClassDeclaration>> class_declarations);
  void Accept(Visitor* visitor);
};

#endif//VISITOR_PROGRAM_PROGRAM_H_
