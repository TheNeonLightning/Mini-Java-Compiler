//
// Created by theneonlightning on 19.05.2020.
//

#ifndef VISITOR_EXPRESSIONS_EXPRESSION_H_
#define VISITOR_EXPRESSIONS_EXPRESSION_H_

#pragma once
#include "../base_elements/BaseElement.h"

class Expression: public BaseElement {
 public:
  virtual int Expr() const = 0;

};

#endif//VISITOR_EXPRESSIONS_EXPRESSION_H_
