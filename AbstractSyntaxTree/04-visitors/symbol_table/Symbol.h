//
// Created by theneonlightning on 18.07.2020.
//

#ifndef COMPILERS_04_VISITORS_SYMBOL_TABLE_SYMBOL_H_
#define COMPILERS_04_VISITORS_SYMBOL_TABLE_SYMBOL_H_

#pragma once

#include <string>
#include <unordered_map>
#include <memory>


class Symbol {
 public:

  bool operator== (const Symbol& other) const;
  bool operator!= (const Symbol& other) const;

  std::string GetName() const;

  Symbol(const std::string& name);
  Symbol(const Symbol& other);

 private:
  std::string name;
};

/**
 * Using string hash for Symbol hash
 */
namespace std {
  template<>
  struct hash<Symbol> {
    std::size_t operator() (const Symbol& other) const {
      return hash<string>()(other.GetName());
    }
  };

}

#endif//COMPILERS_04_VISITORS_SYMBOL_TABLE_SYMBOL_H_
