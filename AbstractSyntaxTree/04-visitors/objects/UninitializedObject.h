//
// Created by theneonlightning on 18.07.2020.
//

#ifndef COMPILERS_04_VISITORS_OBJECTS_UNINITIALIZEDOBJECT_H_
#define COMPILERS_04_VISITORS_OBJECTS_UNINITIALIZEDOBJECT_H_

#pragma once

#include "Object.h"


class UninitializedObject : public Object {
 public:
  UninitializedObject(std::string types, bool array);

  int ToInt() override;
  std::pair<std::string, bool> GetType() override;

  std::string type;
  bool is_array;
};

#endif//COMPILERS_04_VISITORS_OBJECTS_UNINITIALIZEDOBJECT_H_
