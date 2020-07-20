//
// Created by theneonlightning on 18.07.2020.
//

#include "ScopeLayerTree.h"


ScopeLayerTree::ScopeLayerTree(ScopeLayer* root): root(root) {}

void ScopeLayerTree::Free(ScopeLayer* layer) {

  for (size_t index = 0; index < layer->children.size(); ++index) {
    Free(layer->children[index]);
  }

  if (layer->children.empty()) {
    return;
  }

  for (size_t index = 0; index < layer->children.size(); ++index) {
    delete layer->children[index];
  }
}

