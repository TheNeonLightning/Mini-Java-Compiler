//
// Created by theneonlightning on 19.05.2020.
//

#include "BracesStatement.h"

BracesStatement::BracesStatement
    (std::vector<std::shared_ptr<Statement>> statements):
    statements(statements) {}

void BracesStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
