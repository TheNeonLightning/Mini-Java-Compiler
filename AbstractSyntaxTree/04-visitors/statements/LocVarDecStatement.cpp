//
// Created by theneonlightning on 19.05.2020.
//

#include "LocVarDecStatement.h"

LocVarDecStatement::LocVarDecStatement(const std::string &type,
                                       bool is_array,
                                       const std::string &identifier_):
  type(type), identifier(identifier_), is_array(is_array)  {}

void LocVarDecStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
