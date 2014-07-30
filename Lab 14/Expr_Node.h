#ifndef __Prefix_Calculator__Expr_Node__
#define __Prefix_Calculator__Expr_Node__

#include <iostream>
using namespace std;

class Expr_Node{
public:
	virtual void print(std::ostream& os) const = 0;

protected:
	Expr_Node();
	virtual ~Expr_Node();

	virtual int eval() const = 0;
	virtual void print(std::ostream& os) const = 0;

private:
	friend std::ostream& operator<<(std::ostream& os, Expr_Node const& node);
	friend class Expr;

private:
	int _use;
};

#endif