//
// Created by theneonlightning on 18.07.2020.
//

#include "Object.h"
#include <iostream>

int Object::ToInt() {
  std::cout << "Wrong type (ToInt())" << std::endl;
}

bool Object::ToBoolean() {
  std::cout << "Wrong type (ToBoolean)" << std::endl;
}

Class Object::ToClass() {
  std::cout << "Wrong type (ToClass)" << std::endl;
}

Method Object::ToMethod() {
  std::cout << "Wrong type (ToMethod)" << std::endl;
}

std::pair<std::string, bool> Object::GetType() {}