//
// Created by theneonlightning on 18.07.2020.
//

#ifndef COMPILERS_04_VISITORS_OBJECTS_CLASS_H_
#define COMPILERS_04_VISITORS_OBJECTS_CLASS_H_

#pragma once

#include "Object.h"

class ClassType: public Object {

 public:

  explicit ClassType(std::string type, bool array);

  Class ToClass () override;
  std::pair<std::string, bool> GetType() override;

 private:
  std::string type;
  bool is_array;
};

#endif//COMPILERS_04_VISITORS_OBJECTS_CLASS_H_
