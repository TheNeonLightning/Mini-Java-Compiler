Statement::Statement(std::shared_ptr<Expression> expr):
    expr(expr) {}

void Statement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}