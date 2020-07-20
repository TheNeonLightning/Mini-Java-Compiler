//
// Created by theneonlightning on 19.05.2020.
//

#include "VarDeclaration.h"

VarDeclaration::VarDeclaration(const std::pair<std::string, bool> type,
                               const std::string& id)
    : type(type.first), identifier(id), is_array(type.second)
{}

void VarDeclaration::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
