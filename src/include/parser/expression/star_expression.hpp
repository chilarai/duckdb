//===----------------------------------------------------------------------===//
//
//                         DuckDB
//
// parser/expression/star_expression.hpp
//
// Author: Mark Raasveldt
//
//===----------------------------------------------------------------------===//

#pragma once

#include "parser/expression.hpp"

namespace duckdb {

//! Represents a * expression in the SELECT clause
class StarExpression : public Expression {
  public:
	StarExpression()
	    : Expression(ExpressionType::STAR) {}

	virtual void Accept(SQLNodeVisitor *v) override { v->Visit(*this); }
	virtual ExpressionClass GetExpressionClass() override { return ExpressionClass::STAR; }

	virtual std::string ToString() const override { return "*"; }
};
} // namespace duckdb