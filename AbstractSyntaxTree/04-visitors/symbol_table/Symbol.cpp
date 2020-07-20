//
// Created by theneonlightning on 18.07.2020.
//

#include "Symbol.h"

#include <iostream>

Symbol::Symbol(const std::string& name): name(name) {}

Symbol::Symbol(const Symbol& symbol): name(symbol.name) {}

bool Symbol::operator==(const Symbol& other) const {
  return name == other.name;
}

bool Symbol::operator!=(const Symbol& other) const {
  return name != other.name;
}

std::string Symbol::GetName() const {
  return name;
}

