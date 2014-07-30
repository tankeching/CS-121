#ifndef __Picture__with_P_Node__Vcat_Pic__
#define __Picture__with_P_Node__Vcat_Pic__

#include <iostream>
using namespace std;

#include "P_Node.h"
#include "Picture.h"

class Vcat_Pic : public P_Node {
private:
	Vcat_Pic(const Picture& top, const Picture& bottom);
	int height() const;
	int width() const;

	void display(ostream& os, int row, int wd) const;
	Picture reframe(char c, char s, char t);

	friend Picture operator&(const Picture& top, const Picture& bottom);

public:
	Picture* getPic();

private:
	Picture _top, _bottom;

};

#endif