//
// Created by theneonlightning on 18.07.2020.
//

#ifndef COMPILERS_04_VISITORS_SYMBOL_TABLE_SCOPELAYERTREE_H_
#define COMPILERS_04_VISITORS_SYMBOL_TABLE_SCOPELAYERTREE_H_

#pragma once

#include "ScopeLayer.h"


class ScopeLayerTree {

 public:

  explicit ScopeLayerTree(ScopeLayer* root);
  void Free(ScopeLayer* layer);
  ScopeLayer* root;

};

#endif//COMPILERS_04_VISITORS_SYMBOL_TABLE_SCOPELAYERTREE_H_
