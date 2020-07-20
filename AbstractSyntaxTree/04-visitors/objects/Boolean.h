//
// Created by theneonlightning on 18.07.2020.
//

#ifndef COMPILERS_04_VISITORS_OBJECTS_BOOLEAN_H_
#define COMPILERS_04_VISITORS_OBJECTS_BOOLEAN_H_

#pragma once

#include "Object.h"

class Boolean: public Object {

 public:

  explicit Boolean(bool value, bool array);

  bool ToBoolean() override;
  std::pair<std::string, bool> GetType() override;

 private:
  bool value;
  bool is_array;
};

#endif//COMPILERS_04_VISITORS_OBJECTS_BOOLEAN_H_
