#ifndef __Prefix_Calculator__Binary_Node__
#define __Prefix_Calculator__Binary_Node__

#include "Binary_Node.h"

#include <iostream>
#include <string>
using namespace std;

class Binary_Node : public Expr_Node {
private:
	Binary_Node(std::string const& op, Expr lhs, Expr rhs);
	~Binary_Node();

	int eval() const;
	void print(std::ostream& os) const;

private:
	friend class Expr;

private:
	std::string _op;
	Expr _lhs, _rhs;
};

#endif