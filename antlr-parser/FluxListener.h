
// Generated from ./FluxFiles/Flux.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "Flux.h"


/**
 * This interface defines an abstract listener for a parse tree produced by Flux.
 */
class  FluxListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(Flux::ProgramContext *ctx) = 0;
  virtual void exitProgram(Flux::ProgramContext *ctx) = 0;

  virtual void enterDeclaration(Flux::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(Flux::DeclarationContext *ctx) = 0;

  virtual void enterImportDeclaration(Flux::ImportDeclarationContext *ctx) = 0;
  virtual void exitImportDeclaration(Flux::ImportDeclarationContext *ctx) = 0;

  virtual void enterImportList(Flux::ImportListContext *ctx) = 0;
  virtual void exitImportList(Flux::ImportListContext *ctx) = 0;

  virtual void enterImportItem(Flux::ImportItemContext *ctx) = 0;
  virtual void exitImportItem(Flux::ImportItemContext *ctx) = 0;

  virtual void enterExportDeclaration(Flux::ExportDeclarationContext *ctx) = 0;
  virtual void exitExportDeclaration(Flux::ExportDeclarationContext *ctx) = 0;

  virtual void enterClassDeclaration(Flux::ClassDeclarationContext *ctx) = 0;
  virtual void exitClassDeclaration(Flux::ClassDeclarationContext *ctx) = 0;

  virtual void enterPublicBlock(Flux::PublicBlockContext *ctx) = 0;
  virtual void exitPublicBlock(Flux::PublicBlockContext *ctx) = 0;

  virtual void enterPrivateBlock(Flux::PrivateBlockContext *ctx) = 0;
  virtual void exitPrivateBlock(Flux::PrivateBlockContext *ctx) = 0;

  virtual void enterConstructorDeclaration(Flux::ConstructorDeclarationContext *ctx) = 0;
  virtual void exitConstructorDeclaration(Flux::ConstructorDeclarationContext *ctx) = 0;

  virtual void enterSuperCall(Flux::SuperCallContext *ctx) = 0;
  virtual void exitSuperCall(Flux::SuperCallContext *ctx) = 0;

  virtual void enterConstructorInitStatement(Flux::ConstructorInitStatementContext *ctx) = 0;
  virtual void exitConstructorInitStatement(Flux::ConstructorInitStatementContext *ctx) = 0;

  virtual void enterMethodDeclaration(Flux::MethodDeclarationContext *ctx) = 0;
  virtual void exitMethodDeclaration(Flux::MethodDeclarationContext *ctx) = 0;

  virtual void enterConstDeclaration(Flux::ConstDeclarationContext *ctx) = 0;
  virtual void exitConstDeclaration(Flux::ConstDeclarationContext *ctx) = 0;

  virtual void enterVarDeclaration(Flux::VarDeclarationContext *ctx) = 0;
  virtual void exitVarDeclaration(Flux::VarDeclarationContext *ctx) = 0;

  virtual void enterStatement(Flux::StatementContext *ctx) = 0;
  virtual void exitStatement(Flux::StatementContext *ctx) = 0;

  virtual void enterWhileStatement(Flux::WhileStatementContext *ctx) = 0;
  virtual void exitWhileStatement(Flux::WhileStatementContext *ctx) = 0;

  virtual void enterDoWhileStatement(Flux::DoWhileStatementContext *ctx) = 0;
  virtual void exitDoWhileStatement(Flux::DoWhileStatementContext *ctx) = 0;

  virtual void enterBreakStatement(Flux::BreakStatementContext *ctx) = 0;
  virtual void exitBreakStatement(Flux::BreakStatementContext *ctx) = 0;

  virtual void enterContinueStatement(Flux::ContinueStatementContext *ctx) = 0;
  virtual void exitContinueStatement(Flux::ContinueStatementContext *ctx) = 0;

  virtual void enterForStatement(Flux::ForStatementContext *ctx) = 0;
  virtual void exitForStatement(Flux::ForStatementContext *ctx) = 0;

  virtual void enterForRange(Flux::ForRangeContext *ctx) = 0;
  virtual void exitForRange(Flux::ForRangeContext *ctx) = 0;

  virtual void enterRangeExpr(Flux::RangeExprContext *ctx) = 0;
  virtual void exitRangeExpr(Flux::RangeExprContext *ctx) = 0;

  virtual void enterBuiltInCall(Flux::BuiltInCallContext *ctx) = 0;
  virtual void exitBuiltInCall(Flux::BuiltInCallContext *ctx) = 0;

  virtual void enterBlock(Flux::BlockContext *ctx) = 0;
  virtual void exitBlock(Flux::BlockContext *ctx) = 0;

  virtual void enterAssignmentStatement(Flux::AssignmentStatementContext *ctx) = 0;
  virtual void exitAssignmentStatement(Flux::AssignmentStatementContext *ctx) = 0;

  virtual void enterArrayAssignmentStatement(Flux::ArrayAssignmentStatementContext *ctx) = 0;
  virtual void exitArrayAssignmentStatement(Flux::ArrayAssignmentStatementContext *ctx) = 0;

  virtual void enterArrayLiteral(Flux::ArrayLiteralContext *ctx) = 0;
  virtual void exitArrayLiteral(Flux::ArrayLiteralContext *ctx) = 0;

  virtual void enterArrayAccess(Flux::ArrayAccessContext *ctx) = 0;
  virtual void exitArrayAccess(Flux::ArrayAccessContext *ctx) = 0;

  virtual void enterIfStatement(Flux::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(Flux::IfStatementContext *ctx) = 0;

  virtual void enterValueAccess(Flux::ValueAccessContext *ctx) = 0;
  virtual void exitValueAccess(Flux::ValueAccessContext *ctx) = 0;

  virtual void enterExpr(Flux::ExprContext *ctx) = 0;
  virtual void exitExpr(Flux::ExprContext *ctx) = 0;

  virtual void enterArithmeticOp(Flux::ArithmeticOpContext *ctx) = 0;
  virtual void exitArithmeticOp(Flux::ArithmeticOpContext *ctx) = 0;

  virtual void enterCompareOp(Flux::CompareOpContext *ctx) = 0;
  virtual void exitCompareOp(Flux::CompareOpContext *ctx) = 0;

  virtual void enterLogicalOp(Flux::LogicalOpContext *ctx) = 0;
  virtual void exitLogicalOp(Flux::LogicalOpContext *ctx) = 0;

  virtual void enterAssignOp(Flux::AssignOpContext *ctx) = 0;
  virtual void exitAssignOp(Flux::AssignOpContext *ctx) = 0;

  virtual void enterNotExpr(Flux::NotExprContext *ctx) = 0;
  virtual void exitNotExpr(Flux::NotExprContext *ctx) = 0;

  virtual void enterClassInstantiation(Flux::ClassInstantiationContext *ctx) = 0;
  virtual void exitClassInstantiation(Flux::ClassInstantiationContext *ctx) = 0;

  virtual void enterTerm(Flux::TermContext *ctx) = 0;
  virtual void exitTerm(Flux::TermContext *ctx) = 0;

  virtual void enterFactor(Flux::FactorContext *ctx) = 0;
  virtual void exitFactor(Flux::FactorContext *ctx) = 0;

  virtual void enterFuncDeclaration(Flux::FuncDeclarationContext *ctx) = 0;
  virtual void exitFuncDeclaration(Flux::FuncDeclarationContext *ctx) = 0;

  virtual void enterFuncCall(Flux::FuncCallContext *ctx) = 0;
  virtual void exitFuncCall(Flux::FuncCallContext *ctx) = 0;

  virtual void enterParamList(Flux::ParamListContext *ctx) = 0;
  virtual void exitParamList(Flux::ParamListContext *ctx) = 0;

  virtual void enterParam(Flux::ParamContext *ctx) = 0;
  virtual void exitParam(Flux::ParamContext *ctx) = 0;

  virtual void enterReturnStmt(Flux::ReturnStmtContext *ctx) = 0;
  virtual void exitReturnStmt(Flux::ReturnStmtContext *ctx) = 0;

  virtual void enterType(Flux::TypeContext *ctx) = 0;
  virtual void exitType(Flux::TypeContext *ctx) = 0;


};

