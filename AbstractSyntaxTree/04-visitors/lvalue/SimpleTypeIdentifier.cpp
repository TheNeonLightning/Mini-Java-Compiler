//
// Created by theneonlightning on 20.05.2020.
//

#include "SimpleTypeIdentifier.h"

SimpleTypeIdentifier::SimpleTypeIdentifier(const std::string &identifier):
  identifier(identifier) {}

void SimpleTypeIdentifier::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
