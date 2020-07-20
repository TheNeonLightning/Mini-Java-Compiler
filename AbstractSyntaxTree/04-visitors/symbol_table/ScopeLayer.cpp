//
// Created by theneonlightning on 18.07.2020.
//

#include "ScopeLayer.h"

#include "objects/UninitializedObject.h"

#include <iostream>


ScopeLayer::ScopeLayer(ScopeLayer* parent) : parent(parent) {

  parent->AddChild(this);

  // inserting default classes
  classes.insert("int");
  classes.insert("boolean");
  classes.insert("void");

}


void ScopeLayer::DeclareFieldInClass(std::string class_name, std::string type,
                                     std::string field_name) {
  ScopeLayer* current_layer = this;

  // Searching for class scope layer
  while (current_layer->defined_classes.find(class_name) ==
      current_layer->defined_classes.end() &&
      current_layer->parent != nullptr) {
    current_layer = current_layer->parent;
  }

  if (current_layer->defined_classes.find(class_name) !=
      current_layer->defined_classes.end()) {

    current_layer->defined_classes[class_name].fields
        .emplace_back(type, field_name);

  } else {
    throw std::runtime_error("Can not declare field in class, "
                             "class not declared");
  }
}


void ScopeLayer::DeclareMethodInClass(
    std::string class_name, std::string type, std::string method_name,
    std::vector<std::pair<std::string, std::string>> args) {

  ScopeLayer* current_layer = this;

  // Searching for class scope layer
  while (current_layer->defined_classes.find(class_name) ==
      current_layer->defined_classes.end() &&
      current_layer->parent != nullptr) {
    current_layer = current_layer->parent;
  }

  if (current_layer->defined_classes.find(class_name) !=
      current_layer->defined_classes.end()) {

    current_layer->defined_classes[class_name].methods
        .emplace_back(type, method_name, args);

  } else {
    throw std::runtime_error("Can not declare method in class, "
                             "class not declared");
  }
}


void ScopeLayer::AttachParent() {}


void ScopeLayer::DeclareClass(std::string class_name) {
  classes.insert(class_name);
}


void ScopeLayer::DeclareMethod(const std::string& method_name,
                               MethodType method_type) {
  methods[method_name]
      = MethodType(method_type.type, method_type.name, method_type.var_list);
}


ScopeLayer::ScopeLayer() : parent(nullptr) {}


std::pair<std::string, bool> ScopeLayer::GetType(std::string symbol) {
  ScopeLayer* current_layer = this;

  while (!current_layer->Has(symbol) && current_layer->parent != nullptr) {
    current_layer = current_layer->parent;
  }

  if (current_layer->Has(symbol)) {

    return current_layer->Get(symbol)->GetType();

  } else {
    throw std::runtime_error("Variable not declared");
  }
}


void ScopeLayer::DeclareVariable(Symbol symbol,
                                 std::pair<std::string, bool> type) {

  if (values.find(symbol) != values.end()) {
    throw std::runtime_error("Variable has already been declared");
  }

  ScopeLayer* current_layer = this;

  while (current_layer->classes.find(type.first) ==
      current_layer->classes.end() &&
      current_layer->parent != nullptr) {

    current_layer = current_layer->parent;

  }

  if (current_layer->classes.find(type.first) !=
      current_layer->classes.end()) {

    values[symbol] = std::make_shared<UninitializedObject>(type.first, type.second);
    offsets[symbol] = symbols.size();
    symbols.push_back(symbol);

  } else {
    throw std::runtime_error("Initialization variable of undeclared class");
  }
}


void ScopeLayer::Put(Symbol symbol, std::shared_ptr<Object> value) {

  ScopeLayer* current_layer = this;

  while (!current_layer->Has(symbol) && current_layer->parent != nullptr) {
    current_layer = current_layer->parent;
  }

  if (current_layer->Has(symbol)) {

    current_layer->values.find(symbol)->second = value;

  } else {
    throw std::runtime_error("Variable not declared");
  }
}


bool ScopeLayer::Has(Symbol symbol) {
  return values.find(symbol) != values.end();
}


std::shared_ptr<Object> ScopeLayer::Get(Symbol symbol) {
  ScopeLayer* current_layer = this;

  while (!current_layer->Has(symbol) && current_layer->parent != nullptr) {
    current_layer = current_layer->parent;
  }

  if (current_layer->Has(symbol)) {

    return current_layer->values.find(symbol)->second;

  } else {
    throw std::runtime_error("Variable not declared");
  }
}


ScopeLayer* ScopeLayer::GetChild(size_t index) {
  return children[index];
}


void ScopeLayer::AddChild(ScopeLayer* child) {
  children.push_back(child);
}


ScopeLayer* ScopeLayer::GetParent() const {
  return parent;
}
