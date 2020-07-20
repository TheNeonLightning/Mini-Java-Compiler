//
// Created by theneonlightning on 18.07.2020.
//

#ifndef COMPILERS_04_VISITORS_SYMBOL_TABLE_SCOPELAYER_H_
#define COMPILERS_04_VISITORS_SYMBOL_TABLE_SCOPELAYER_H_


#pragma once

#include "Symbol.h"
#include "objects/MethodType.h"

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <set>

class ScopeLayer {
 public:
  explicit ScopeLayer(ScopeLayer* parent);
  ScopeLayer();
  void DeclareVariable(Symbol symbol, std::pair<std::string, bool> type);
  void DeclareClass(std::string name);
  void Put(Symbol symbol, std::shared_ptr<Object> value);
  void DeclareMethod(const std::string &id, MethodType method_type);
  void DeclareMethodInClass(std::string cl, std::string t, std::string id,
                            std::vector<std::pair<std::string, std::string>> args);
  void DeclareFieldInClass(std::string cl, std::string t, std::string id);
  std::shared_ptr<Object> Get(Symbol symbol);
  bool Has(Symbol symbol);
  std::pair<std::string, bool> GetType(std::string symbol);

  void AddChild(ScopeLayer *child);
  void AttachParent();

  ScopeLayer* GetChild(size_t index);
  ScopeLayer* GetParent() const;

  std::unordered_map<Symbol, std::shared_ptr<Object>> values;
  std::unordered_map<Symbol, size_t> offsets;
  std::vector<Symbol> symbols;

  std::set<std::string> classes;
  std::map<std::string, MethodType> methods;
  std::map<std::string, Class> defined_classes;

  ScopeLayer* parent;
  std::vector<ScopeLayer*> children;
};

#endif//COMPILERS_04_VISITORS_SYMBOL_TABLE_SCOPELAYER_H_
