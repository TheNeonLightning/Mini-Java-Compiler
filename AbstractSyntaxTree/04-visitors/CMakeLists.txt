project(ASTreeVisitor)
set(
        HEADERS
        driver.hh
        parser.hh
)

BISON_TARGET(
        ASTreeParser
        parser.y
        ${ASTreeVisitor_SOURCE_DIR}/parser.cpp
        DEFINES_FILE ${ASTreeVisitor_SOURCE_DIR}/parser.hh
        COMPILE_FLAGS "--warnings=all --report=all --verbose"
)

FLEX_TARGET(
        ASTreeScanner
        scanner.l
        ${ASTreeVisitor_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(ASTreeScanner ASTreeParser)

add_executable(
        ASTreeVisitor
        main.cpp
        driver.cpp
        ${BISON_ASTreeParser_OUTPUTS}
        ${FLEX_ASTreeScanner_OUTPUTS}
        expressions/IntegerExpression.cpp
        expressions/MulExpression.cpp
        expressions/AddExpression.cpp
        expressions/SubExpression.cpp
        expressions/DivExpression.cpp
        expressions/IdentifierExpression.cpp
        expressions/ResidueExpression.cpp
        expressions/AndExpression.cpp
        expressions/OrExpression.cpp
        expressions/LessExpression.cpp
        expressions/GreaterExpression.cpp
        expressions/IsEqualExpression.cpp
        expressions/AccessExpression.cpp
        expressions/LengthExpression.cpp
        expressions/NewArrayExpression.cpp
        expressions/NewExpression.cpp
        expressions/NegativeExpression.cpp
        expressions/ParensExpression.cpp
        expressions/ThisExpression.cpp
        expressions/LogicExpression.cpp
        expressions/MethodInvExpression.cpp
        statements/WhileStatement.cpp
        statements/AssertStatement.cpp
        statements/BracesStatement.cpp
        statements/IfStatement.cpp
        statements/IfElseStatement.cpp
        statements/SOPrintlnStatement.cpp
        statements/ReturnStatement.cpp
        statements/LocVarDecStatement.cpp
        lvalue/SimpleTypeIdentifier.cpp
        lvalue/ArrayIdentifier.cpp
        statements/LValueAssignStatement.cpp
        declarations/VarDeclaration.cpp
        declarations/MethodDeclaration.cpp
        declarations/ClassDeclaration.cpp
        main_class/MainClass.cpp
        program/Program.cpp
        visitors/PrintVisitor.cpp
        visitors/Interpreter.cpp
)

target_include_directories(
        ASTreeVisitor PRIVATE ${ASTreeVisitor_SOURCE_DIR}
)
