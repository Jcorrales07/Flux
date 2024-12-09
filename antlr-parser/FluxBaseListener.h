
// Generated from ./FluxFiles/Flux.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "FluxListener.h"


/**
 * This class provides an empty implementation of FluxListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  FluxBaseListener : public FluxListener {
public:

  virtual void enterProgram(Flux::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(Flux::ProgramContext * /*ctx*/) override { }

  virtual void enterDeclaration(Flux::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(Flux::DeclarationContext * /*ctx*/) override { }

  virtual void enterImportDeclaration(Flux::ImportDeclarationContext * /*ctx*/) override { }
  virtual void exitImportDeclaration(Flux::ImportDeclarationContext * /*ctx*/) override { }

  virtual void enterImportList(Flux::ImportListContext * /*ctx*/) override { }
  virtual void exitImportList(Flux::ImportListContext * /*ctx*/) override { }

  virtual void enterImportItem(Flux::ImportItemContext * /*ctx*/) override { }
  virtual void exitImportItem(Flux::ImportItemContext * /*ctx*/) override { }

  virtual void enterExportDeclaration(Flux::ExportDeclarationContext * /*ctx*/) override { }
  virtual void exitExportDeclaration(Flux::ExportDeclarationContext * /*ctx*/) override { }

  virtual void enterClassDeclaration(Flux::ClassDeclarationContext * /*ctx*/) override { }
  virtual void exitClassDeclaration(Flux::ClassDeclarationContext * /*ctx*/) override { }

  virtual void enterPublicBlock(Flux::PublicBlockContext * /*ctx*/) override { }
  virtual void exitPublicBlock(Flux::PublicBlockContext * /*ctx*/) override { }

  virtual void enterPrivateBlock(Flux::PrivateBlockContext * /*ctx*/) override { }
  virtual void exitPrivateBlock(Flux::PrivateBlockContext * /*ctx*/) override { }

  virtual void enterConstructorDeclaration(Flux::ConstructorDeclarationContext * /*ctx*/) override { }
  virtual void exitConstructorDeclaration(Flux::ConstructorDeclarationContext * /*ctx*/) override { }

  virtual void enterSuperCall(Flux::SuperCallContext * /*ctx*/) override { }
  virtual void exitSuperCall(Flux::SuperCallContext * /*ctx*/) override { }

  virtual void enterConstructorInitStatement(Flux::ConstructorInitStatementContext * /*ctx*/) override { }
  virtual void exitConstructorInitStatement(Flux::ConstructorInitStatementContext * /*ctx*/) override { }

  virtual void enterMethodDeclaration(Flux::MethodDeclarationContext * /*ctx*/) override { }
  virtual void exitMethodDeclaration(Flux::MethodDeclarationContext * /*ctx*/) override { }

  virtual void enterConstDeclaration(Flux::ConstDeclarationContext * /*ctx*/) override { }
  virtual void exitConstDeclaration(Flux::ConstDeclarationContext * /*ctx*/) override { }

  virtual void enterVarDeclaration(Flux::VarDeclarationContext * /*ctx*/) override { }
  virtual void exitVarDeclaration(Flux::VarDeclarationContext * /*ctx*/) override { }

  virtual void enterStatement(Flux::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(Flux::StatementContext * /*ctx*/) override { }

  virtual void enterWhileStatement(Flux::WhileStatementContext * /*ctx*/) override { }
  virtual void exitWhileStatement(Flux::WhileStatementContext * /*ctx*/) override { }

  virtual void enterDoWhileStatement(Flux::DoWhileStatementContext * /*ctx*/) override { }
  virtual void exitDoWhileStatement(Flux::DoWhileStatementContext * /*ctx*/) override { }

  virtual void enterBreakStatement(Flux::BreakStatementContext * /*ctx*/) override { }
  virtual void exitBreakStatement(Flux::BreakStatementContext * /*ctx*/) override { }

  virtual void enterContinueStatement(Flux::ContinueStatementContext * /*ctx*/) override { }
  virtual void exitContinueStatement(Flux::ContinueStatementContext * /*ctx*/) override { }

  virtual void enterForStatement(Flux::ForStatementContext * /*ctx*/) override { }
  virtual void exitForStatement(Flux::ForStatementContext * /*ctx*/) override { }

  virtual void enterForRange(Flux::ForRangeContext * /*ctx*/) override { }
  virtual void exitForRange(Flux::ForRangeContext * /*ctx*/) override { }

  virtual void enterRangeExpr(Flux::RangeExprContext * /*ctx*/) override { }
  virtual void exitRangeExpr(Flux::RangeExprContext * /*ctx*/) override { }

  virtual void enterBuiltInCall(Flux::BuiltInCallContext * /*ctx*/) override { }
  virtual void exitBuiltInCall(Flux::BuiltInCallContext * /*ctx*/) override { }

  virtual void enterBlock(Flux::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(Flux::BlockContext * /*ctx*/) override { }

  virtual void enterAssignmentStatement(Flux::AssignmentStatementContext * /*ctx*/) override { }
  virtual void exitAssignmentStatement(Flux::AssignmentStatementContext * /*ctx*/) override { }

  virtual void enterArrayAssignmentStatement(Flux::ArrayAssignmentStatementContext * /*ctx*/) override { }
  virtual void exitArrayAssignmentStatement(Flux::ArrayAssignmentStatementContext * /*ctx*/) override { }

  virtual void enterArrayLiteral(Flux::ArrayLiteralContext * /*ctx*/) override { }
  virtual void exitArrayLiteral(Flux::ArrayLiteralContext * /*ctx*/) override { }

  virtual void enterArrayAccess(Flux::ArrayAccessContext * /*ctx*/) override { }
  virtual void exitArrayAccess(Flux::ArrayAccessContext * /*ctx*/) override { }

  virtual void enterIfStatement(Flux::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(Flux::IfStatementContext * /*ctx*/) override { }

  virtual void enterValueAccess(Flux::ValueAccessContext * /*ctx*/) override { }
  virtual void exitValueAccess(Flux::ValueAccessContext * /*ctx*/) override { }

  virtual void enterExpr(Flux::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(Flux::ExprContext * /*ctx*/) override { }

  virtual void enterArithmeticOp(Flux::ArithmeticOpContext * /*ctx*/) override { }
  virtual void exitArithmeticOp(Flux::ArithmeticOpContext * /*ctx*/) override { }

  virtual void enterCompareOp(Flux::CompareOpContext * /*ctx*/) override { }
  virtual void exitCompareOp(Flux::CompareOpContext * /*ctx*/) override { }

  virtual void enterLogicalOp(Flux::LogicalOpContext * /*ctx*/) override { }
  virtual void exitLogicalOp(Flux::LogicalOpContext * /*ctx*/) override { }

  virtual void enterAssignOp(Flux::AssignOpContext * /*ctx*/) override { }
  virtual void exitAssignOp(Flux::AssignOpContext * /*ctx*/) override { }

  virtual void enterNotExpr(Flux::NotExprContext * /*ctx*/) override { }
  virtual void exitNotExpr(Flux::NotExprContext * /*ctx*/) override { }

  virtual void enterClassInstantiation(Flux::ClassInstantiationContext * /*ctx*/) override { }
  virtual void exitClassInstantiation(Flux::ClassInstantiationContext * /*ctx*/) override { }

  virtual void enterTerm(Flux::TermContext * /*ctx*/) override { }
  virtual void exitTerm(Flux::TermContext * /*ctx*/) override { }

  virtual void enterFactor(Flux::FactorContext * /*ctx*/) override { }
  virtual void exitFactor(Flux::FactorContext * /*ctx*/) override { }

  virtual void enterFuncDeclaration(Flux::FuncDeclarationContext * /*ctx*/) override { }
  virtual void exitFuncDeclaration(Flux::FuncDeclarationContext * /*ctx*/) override { }

  virtual void enterFuncCall(Flux::FuncCallContext * /*ctx*/) override { }
  virtual void exitFuncCall(Flux::FuncCallContext * /*ctx*/) override { }

  virtual void enterParamList(Flux::ParamListContext * /*ctx*/) override { }
  virtual void exitParamList(Flux::ParamListContext * /*ctx*/) override { }

  virtual void enterParam(Flux::ParamContext * /*ctx*/) override { }
  virtual void exitParam(Flux::ParamContext * /*ctx*/) override { }

  virtual void enterReturnStmt(Flux::ReturnStmtContext * /*ctx*/) override { }
  virtual void exitReturnStmt(Flux::ReturnStmtContext * /*ctx*/) override { }

  virtual void enterType(Flux::TypeContext * /*ctx*/) override { }
  virtual void exitType(Flux::TypeContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

