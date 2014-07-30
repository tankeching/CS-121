#ifndef __Prefix_Calculator__Expr__
#define __Prefix_Calculator__Expr__

#include "Expr_Node.h"

#include <iostream>
using namespace std;

class Expr{
public:
	Expr(int operand);
	Expr(std::string const& op, Expr operand);
	Expr(std::string const& op, Expr lhs, Expr rhs);
	//Expr(missing code);

	Expr(Expr const& other);
	Expr& operator=(Expr const& other);
	~Expr();

	bool operator==(Expr const& other) const;
	bool operator!=(Expr const& other) const;
	bool operator<=(Expr const& other) const;
	bool operator>=(Expr const& other) const;
	bool operator>(Expr const& other) const;

	int eval() const;
	void assign(int value);

private:
	void copy(Expr const& other);
	friend std::ostream& operator<<(std::ostream& os, Expr const& expr);

private:
	Expr_Node* _p;
};

#endif