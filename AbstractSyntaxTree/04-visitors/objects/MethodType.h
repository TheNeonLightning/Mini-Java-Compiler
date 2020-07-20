//
// Created by theneonlightning on 18.07.2020.
//

#ifndef COMPILERS_04_VISITORS_OBJECTS_METHODTYPE_H_
#define COMPILERS_04_VISITORS_OBJECTS_METHODTYPE_H_

#pragma once

#include "Object.h"
#include <declarations/VarDeclaration.h>
#include <memory>

class MethodType: public Object {

 public:

  explicit MethodType(
      std::string  type, std::string  name,
      std::vector<std::shared_ptr<VarDeclaration>>  input);

  MethodType() = default;

  Method ToMethod() override;
  std::pair<std::string, bool> GetType() override;

 public:
  std::vector<std::shared_ptr<VarDeclaration>> var_list;
  std::string name;
  std::string type;
  bool is_array = false;

};

#endif//COMPILERS_04_VISITORS_OBJECTS_METHODTYPE_H_
