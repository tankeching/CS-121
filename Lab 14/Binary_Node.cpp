#include "Binary_Node.h"
#include "Expr_Node.h"
#include "Expr.h"
#include <string>

Binary_Node::Binary_Node(std::string const& op, Expr lhs, Expr rhs) : _op(op), _lhs(lhs), _rhs(rhs){}

Binary_Node::~Binary_Node() {}

void Binary_Node::print(std::ostream& os) const{
	os << _op << " " << _lhs << " " << _rhs;
}