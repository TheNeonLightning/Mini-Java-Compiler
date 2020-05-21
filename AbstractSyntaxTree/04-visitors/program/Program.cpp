//
// Created by theneonlightning on 19.05.2020.
//

#include "Program.h"

Program::Program(std::shared_ptr<MainClass> main_class,
            std::vector<std::shared_ptr<ClassDeclaration>> class_declarations):
  main_class(main_class), class_declarations(class_declarations) {}

void Program::Accept(Visitor *visitor) {
  visitor->Visit(this);
}