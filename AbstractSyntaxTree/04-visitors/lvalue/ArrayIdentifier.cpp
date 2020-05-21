//
// Created by theneonlightning on 20.05.2020.
//

#include "ArrayIdentifier.h"

ArrayIdentifier::ArrayIdentifier(const std::string &id,
                                 std::shared_ptr<Expression> expr):
  identifier(id), expr(expr) {}

void ArrayIdentifier::Accept(Visitor *visitor) {
  visitor->Visit(this);
}