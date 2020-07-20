//
// Created by theneonlightning on 18.07.2020.
//

#include "UninitializedObject.h"

#include <stdexcept>


UninitializedObject::UninitializedObject(std::string types, bool array)
    : type(std::move(types)), is_array(array) {}

int UninitializedObject::ToInt() {
  throw std::runtime_error("Variable not initialized");
}

std::pair<std::string, bool> UninitializedObject::GetType() {
  return {type, is_array};
}