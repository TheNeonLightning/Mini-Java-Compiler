//
// Created by theneonlightning on 18.07.2020.
//

#ifndef COMPILERS_04_VISITORS_OBJECTS_INTEGER_H_
#define COMPILERS_04_VISITORS_OBJECTS_INTEGER_H_

#pragma once

#include "Object.h"

class Integer: public Object {

 public:

  explicit Integer(int value, bool array);

  int ToInt() override;
  std::pair<std::string, bool> GetType() override;

 private:
  int value;
  bool is_array;
};

#endif//COMPILERS_04_VISITORS_OBJECTS_INTEGER_H_
