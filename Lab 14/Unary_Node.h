#ifndef __Prefix_Calculator__Unary_Node__
#define __Prefix_Calculator__Unary_Node__

#include "Expr_Node.h"
#include "Expr.h"

#include <iostream>
using namespace std;

class Unary_Node : public Expr_Node {

private:
	Unary_Node(int n);
	~Unary_Node();

	int eval() const;

	void print(std::ostream& os) const;

private:
	friend class Expr;

private:
	std::string _op;
	Expr _operand;
};

#endif