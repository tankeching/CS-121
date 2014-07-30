#ifndef __Prefix_Calculator__Int_Node__
#define __Prefix_Calculator__Int_Node__

#include "Expr_Node.h"

#include <iostream>
using namespace std;

class Int_Node : public Expr_Node {
private:
	Int_Node(std::string const& op, Expr operand);
	~Int_Node();

	int eval() const;
	void print(std::ostream& os) const;

private:
	friend class Expr;

private:
	int _operand;
};

#endif