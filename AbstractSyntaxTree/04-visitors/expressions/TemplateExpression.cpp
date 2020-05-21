Expression::Expression(std::shared_ptr<Expression> lhv,
                       std::shared_ptr<Expression> rhv):
    lhv(lhv), rhv(rhv) {}

int Expression::Expr() const {
  return lhv->Expr() rhv->Expr();
}

void Expression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
