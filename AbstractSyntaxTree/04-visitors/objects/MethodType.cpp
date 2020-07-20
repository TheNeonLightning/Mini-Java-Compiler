//
// Created by theneonlightning on 18.07.2020.
//

#include "MethodType.h"

#include <utility>

Method MethodType::ToMethod() {
  return {};
}

MethodType::MethodType(std::string  type, std::string  name,
    std::vector<std::shared_ptr<VarDeclaration>>  input)
    : type(std::move(type)), name(std::move(name)), var_list(std::move(input)),
      is_array(false) {}

std::pair<std::string, bool> MethodType::GetType() {
  return {type, false};
}