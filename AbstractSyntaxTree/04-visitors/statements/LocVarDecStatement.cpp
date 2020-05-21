//
// Created by theneonlightning on 19.05.2020.
//

#include "LocVarDecStatement.h"

LocVarDecStatement::LocVarDecStatement(const std::string &type,
                                       const std::string &identifie_):
  type(type), identifier(identifie_) {}

void LocVarDecStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
