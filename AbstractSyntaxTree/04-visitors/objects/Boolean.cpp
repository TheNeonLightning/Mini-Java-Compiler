//
// Created by theneonlightning on 18.07.2020.
//

#include "Boolean.h"


Boolean::Boolean(bool value, bool array): value(value), is_array(array) {}

bool Boolean::ToBoolean() {
  return value;
}

std::pair<std::string, bool> Boolean::GetType() {
  return {"boolean", is_array};
}