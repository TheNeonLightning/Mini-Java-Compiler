//
// Created by theneonlightning on 20.05.2020.
//

#ifndef VISITOR_VISITORS_ELEMENTS_H_
#define VISITOR_VISITORS_ELEMENTS_H_

#pragma once

#include "../declarations/ClassDeclaration.h"
#include "../declarations/MethodDeclaration.h"
#include "../declarations/VarDeclaration.h"

#include "../expressions/AddExpression.h"
#include "../expressions/AndExpression.h"
#include "../expressions/AccessExpression.h"
#include "../expressions/DivExpression.h"
#include "../expressions/Expression.h"
#include "../expressions/IdentifierExpression.h"
#include "../expressions/ParensExpression.h"
#include "../expressions/IsEqualExpression.h"
#include "../expressions/GreaterExpression.h"
#include "../expressions/LessExpression.h"
#include "../expressions/LengthExpression.h"
#include "../expressions/LogicExpression.h"
#include "../expressions/MethodInvExpression.h"
#include "../expressions/ResidueExpression.h"
#include "../expressions/MulExpression.h"
#include "../expressions/NegativeExpression.h"
#include "../expressions/NewArrayExpression.h"
#include "../expressions/NewExpression.h"
#include "../expressions/IntegerExpression.h"
#include "../expressions/OrExpression.h"
#include "../expressions/SubExpression.h"
#include "../expressions/ThisExpression.h"

#include "../lvalue/ArrayIdentifier.h"
#include "../lvalue/SimpleTypeIdentifier.h"

#include "../program/Program.h"
#include "../main_class/MainClass.h"

#include "../statements/AssertStatement.h"
#include "../statements/IfElseStatement.h"
#include "../statements/IfStatement.h"
#include "../statements/BracesStatement.h"
#include "../statements/LValueAssignStatement.h"
#include "../statements/LocVarDecStatement.h"
#include "../statements/ReturnStatement.h"
#include "../statements/SOPrintlnStatement.h"
#include "../statements/Statement.h"
#include "../statements/WhileStatement.h"

#endif//VISITOR_VISITORS_ELEMENTS_H_
