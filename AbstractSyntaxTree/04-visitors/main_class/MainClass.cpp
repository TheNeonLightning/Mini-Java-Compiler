//
// Created by theneonlightning on 19.05.2020.
//

#include "MainClass.h"

MainClass::MainClass(const std::string& identifier,
                     std::vector<std::shared_ptr<Statement>> statements):
  identifier(identifier), statements(statements) {}

void MainClass::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
