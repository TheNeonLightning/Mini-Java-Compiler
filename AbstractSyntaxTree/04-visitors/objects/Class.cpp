//
// Created by theneonlightning on 18.07.2020.
//

#include "Class.h"

#include <utility>


Class ClassType::ToClass() {
  return {};
}

ClassType::ClassType(std::string type,
                     bool array): type(std::move(type)), is_array(array) {}

std::pair<std::string, bool> ClassType::GetType() {
  return {type, is_array};
}