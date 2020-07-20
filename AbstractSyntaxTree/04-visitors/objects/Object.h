//
// Created by theneonlightning on 18.07.2020.
//

#ifndef COMPILERS_04_VISITORS_OBJECTS_OBJECT_H_
#define COMPILERS_04_VISITORS_OBJECTS_OBJECT_H_

#pragma once

#include <string>
#include <utility>
#include <vector>

class Field {
 public:
  Field() = default;
  Field(std::string type, std::string identifier)
      : type(std::move(type)), identifier(std::move(identifier)) {}

  std::string identifier;
  std::string type;
};

class Method {
 public:
  Method() = default;
  Method(std::string type, std::string name,
         std::vector<std::pair<std::string, std::string>> args)
      : name(std::move(name)), type(std::move(type)), args(std::move(args)) {}

  std::string name;
  std::string type;
  std::vector<std::pair<std::string, std::string>> args;
};

class Class {
 public:
  std::vector<Field> fields;
  std::vector<Method> methods;
};

class Object {
 public:
  virtual int ToInt();
  virtual bool ToBoolean();
  virtual Class ToClass();
  virtual Method ToMethod();
  virtual std::pair<std::string, bool> GetType();
  virtual ~Object() = default;
};

#endif//COMPILERS_04_VISITORS_OBJECTS_OBJECT_H_
