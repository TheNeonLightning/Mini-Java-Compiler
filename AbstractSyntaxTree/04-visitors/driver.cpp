#include "driver.hh"
#include "parser.hh"

#include "visitors/PrintVisitor.h"
#include "visitors/Interpreter.h"
#include "visitors/SymbolTreeVisitor.h"
#include "visitors/TypesChecker.h"
#include "visitors/TypesInterpreter.h"

Driver::Driver() :
    trace_parsing(false),
    trace_scanning(false),
    scanner(*this), parser(scanner, *this) {
}


int Driver::parse(const std::string& f) {
    file = f;
    location.initialize(&file);
    scan_begin();
    parser.set_debug_level(trace_parsing);
    int res = parser();
    scan_end();
    return res;
}

void Driver::scan_begin() {
    scanner.set_debug(trace_scanning);
  if (file.empty () || file == "-") {
  } else {
    stream.open(file);
    std::cout << file << std::endl;
    scanner.yyrestart(&stream);
  }
}

void Driver::PrintASTree(const std::string &filename) {
  PrintVisitor visitor(filename);
  visitor.Visit(program.get());
}

void Driver::Execute() {

  SymbolTreeVisitor symbol_tree_visitor;
  symbol_tree_visitor.Visit(program.get());
  ScopeLayer* root = symbol_tree_visitor.tree.root;

  TypesChecker types_checker(root);
  types_checker.Visit(program.get());

  TypesInterpreter types_interpreter(root);
  types_interpreter.Visit(program.get());

  symbol_tree_visitor.tree.Free(root);

}

void Driver::scan_end()
{
    stream.close();
}

