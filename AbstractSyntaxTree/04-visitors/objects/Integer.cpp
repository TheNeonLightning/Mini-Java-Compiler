//
// Created by theneonlightning on 18.07.2020.
//

#include "Integer.h"


Integer::Integer(int value, bool array): value(value), is_array(array) {}

int Integer::ToInt() {
  return value;
}

std::pair<std::string, bool> Integer::GetType() {
  return {"int", is_array};
}